/**
 * @file WheeledMobileRobot.h
 * @author Sang Su Lee (physism@gmail.com)
 * @brief Wheeled mobile robot. See equation (7) in the following material.
 * https://www.semanticscholar.org/paper/Control-of-a-nonholonomic-mobile-robot-using-neural-Fierro-Lewis/fee564882bef314be31d56d50a1c4dac48926742
 * @version 1.0
 * @date 2021-11-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef WHEELED_MOBILE_ROBOT_H
#define WHEELED_MOBILE_ROBOT_H

#include <Eigen/Dense>
#include <cmath>
#include <iostream>

#include "RobotSimCppGeneral.h"

class WheeledMobileRobot
{
public:
    WheeledMobileRobot(double initX = 0.0, double initY = 0.0, double initTheta = 0.0,
                       double centerToWheelAxis = 0.0);
    virtual ~WheeledMobileRobot();
    virtual Eigen::Vector3d stateVector();

    /**
     * @brief
     *
     * @param input Linear and angular velocities
     * @param timeStep elapsed time per unit step
     */
    virtual void timeUpdate(Eigen::Vector2d input, double timeStep);

private:
    // System states
    Eigen::Vector3d m_state;
    double m_xPos, m_yPos;  // unit: m
    double m_theta;         // unit: rad

    // Intrinsic constants
    double m_centerToWheelAxis;
};

#endif
