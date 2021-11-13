#include "gazebo_sim/WheeledMobileRobotPoseControl.h"

int main(int argc, char** argv)
{
    // Init node
    ros::init(argc, argv, "wheeled_mobile_robot_pose_control_node");
    ros::NodeHandle nodeHandler("~");

    // Set controller parameters
    double gamma_1, gamma_2, h;
    double k1, k2, k3;

    nodeHandler.param("wheeled_mobile_robot_pose_control/Jang2009/gamma_1", gamma_1, 1.5);
    nodeHandler.param("wheeled_mobile_robot_pose_control/Jang2009/gamma_2", gamma_2, 1.0);
    nodeHandler.param("wheeled_mobile_robot_pose_control/Jang2009/h", h, 2.0);
    nodeHandler.param("wheeled_mobile_robot_pose_control/Kanayama1990/k1", k1, 1.0);
    nodeHandler.param("wheeled_mobile_robot_pose_control/Kanayama1990/k2", k2, 5.0);
    nodeHandler.param("wheeled_mobile_robot_pose_control/Kanayama1990/k3", k3, 0.3);

    // Set controller
    std::shared_ptr<WheeledMobileRobotController> pController;

    while (true) {
        int controllerCode;
        std::cout << "Select controller" << std::endl << std::endl;

        std::cout << "1. Jang2009" << std::endl;
        std::cout << "2. Kanayama1990" << std::endl << std::endl;

        std::cout << "Enter number: ";
        std::cin >> controllerCode;

        if (controllerCode == 1) {
            pController = std::make_shared<Jang2009>(gamma_1, gamma_2, h);

            ROS_INFO_STREAM("[robot_sim_cpp] Kinematic controller for the robot are set."
                            << std::endl
                            << "gamma_1: " << gamma_1 << std::endl
                            << "gamma_2: " << gamma_2 << std::endl
                            << "h: " << h);
            break;
        }
        else if (controllerCode == 2) {
            pController = std::make_shared<Kanayama1990>(k1, k2, k3);

            ROS_INFO_STREAM("[robot_sim_cpp] Kinematic controller for the robot are set."
                            << std::endl
                            << "k1: " << k1 << std::endl
                            << "k2: " << k2 << std::endl
                            << "k3: " << k3);
            break;
        }
        else {
            std::cout << "Invalid number. Please try again." << std::endl << std::endl;
        }
    }

    // Set Gazebo robot pose controller object
    WheeledMobileRobotPoseControl robotPoseController(
        "jackal", 0.02, pController, "/gazebo/model_states", "/target_pose", "/cmd_vel");

    // Start control
    ros::Duration(2.0).sleep();
    robotPoseController.startControl();

    ros::waitForShutdown();
    return 1;
}
