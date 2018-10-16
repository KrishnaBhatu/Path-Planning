/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file    main.cpp
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief main class for the project;
 *
 *  @section DESCRIPTION
 *
 *  C++ program to implement Probabilistic Road Map
 *
 */
#include <iostream>
#include <opencv2/highgui.hpp>
#include "../include/map.h"
#include "../include/node.h"
int main(int argc, char** argv) {
  ///! code to read Image
  cv::Mat image;
  image = cv::imread("../image/testMap.png" , CV_LOAD_IMAGE_COLOR);
  if (!image.data) {
      std::cout <<  "Could not open or find the image" << std::endl;
      return -1;
  } else {
    ///! initialize map object from given image
    std::shared_ptr<Map> map;
    map = std::make_shared<Map>(image.cols, image.rows, image);
    ///! set Obstacle Coordinates
    map->readObstaclePixels();
    ///! Ask user for robot location
    bool validRobot = false;
    int robotX, robotY;
    std::cout << "Please enter Robot coordinates" << std::endl;
    std::cin >> robotX >> robotY;
    ///! since smallest node size is 10X10
    if (robotX % 10 != 0 || robotY % 10 != 0) {
      int rm = robotX % 10;
      robotX = robotX - rm;
      rm = robotY % 10;
      robotY = robotY - rm;
    }
    validRobot = map->validateCoordinatesOfEndNode(robotX, robotY);
    while (!validRobot) {
      std::cout << "Warning: Robot coordinates should not be on" << std::endl;
      std::cout << "obstacles and they should not be outside the" << std::endl;
      std::cout << "image size (in this case: 500X500)" << std::endl;
      std::cout << "Please enter Robot Coordinates" << std::endl;
      std::cin >> robotX >> robotY;
      validRobot = map->validateCoordinatesOfEndNode(robotX, robotY);
    }
    map->setRobotX(robotX);
    map->setRobotY(robotY);
    ///! Ask user for goal location
    bool validGoal = false;
    int goalX, goalY;
    std::cout << "Please enter Goal coordinates" << std::endl;
    std::cin >> goalX >> goalY;
    ///! since smallest node size is 10X10
    if (goalX % 10 != 0 || goalY % 10 != 0) {
      int rm = goalX % 10;
      goalX = goalX - rm;
      rm = goalY % 10;
      goalY = goalY - rm;
    }
    validGoal = map->validateCoordinatesOfEndNode(goalX, goalY);
    while (!validGoal) {
      std::cout << "Warning: Goal coordinates should not be on" << std::endl;
      std::cout << "obstacles and they should not be outside the" << std::endl;
      std::cout << "image size (in this case: 500X500)" << std::endl;
      std::cout << "Please enter Goal Coordinates" << std::endl;
      std::cin >> goalX >> goalY;
      validGoal = map->validateCoordinatesOfEndNode(goalX, goalY);
    }
    map->setGoalX(goalX);
    map->setGoalY(goalY);
    ///! Generate Random Nodes
    map->generateRandomNodes();
    ///! Find neighbours and connect them
    map->drawNeighbours();
  }
  return 0;
}



