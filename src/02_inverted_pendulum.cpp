/**
 * @file 02_inverted_pendulum.cpp
 * @author Sang Su Lee (physism@gmail.com)
 * @brief Inverted pendulum control example.
 * @version 1.0
 * @date 2021-06-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "InvertedPendulum.h"

int main(int argc, char* argv[])
{
    double timeStep = 0.01;
    double initPosition = 0.0;
    double initAngle = 0.1;
    InvertedPendulum pendulum(timeStep, initPosition, initAngle);

    std::cout << "Initial output of the pendulum" << std::endl;
    std::cout << pendulum.outputVector() << std::endl;

    for (int i = 0; i < 10; i++) {
        pendulum.timeUpdate(-1.0);
    }

    std::cout << "Output after force applied" << std::endl;
    std::cout << pendulum.outputVector() << std::endl;

    return 0;
}