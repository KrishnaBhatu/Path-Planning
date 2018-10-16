/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file   test.cpp
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief test class for unit testing;
 *
 *  @section DESCRIPTION
 *
 *  This file implements Google test which is unit testing
 *  library for C++ programming language.
 *
 */
#include <gtest/gtest.h>
#include <memory>
#include "../include/map.h"
#include "../include/node.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
/**
 * @brief Test for map class initialization
 */
TEST(MapTest, classInitialization) {
  std::shared_ptr<Map> dummyMap = std::make_shared<Map>();
  int mapX = 500;
  int mapY = 500;
  dummyMap->setSizeX(mapX);
  dummyMap->setSizeY(mapY);
  EXPECT_EQ(500, dummyMap->getSizeX());
  EXPECT_EQ(500, dummyMap->getSizeY());
}
/**
 * @brief Test for map class constructor
 */
TEST(MapTest, classConstructor) {
  int mapX = 500;
  int mapY = 500;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  EXPECT_EQ(500, dummyMap->getSizeX());
  EXPECT_EQ(500, dummyMap->getSizeY());
}
/**
 * @brief Test for start and end node location
 */
TEST(MapTest, robotAndGoalLocation) {
  int robX = 10;
  int robY = 10;
  int goalX = 10;
  int goalY = 10;
  std::shared_ptr<Map> dummyMap = std::make_shared<Map>();
  dummyMap->setRobotX(robX);
  dummyMap->setRobotY(robY);
  dummyMap->setGoalX(goalX);
  dummyMap->setGoalY(goalY);
  EXPECT_EQ(10, dummyMap->getRobotX());
  EXPECT_EQ(10, dummyMap->getRobotY());
  EXPECT_EQ(10, dummyMap->getGoalX());
  EXPECT_EQ(10, dummyMap->getGoalY());
}
/**
 * @brief Test for obstacle detection
 */
TEST(MapTest, obstacleDetect) {
  int mapX = 500;
  int mapY = 500;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  dummyMap->readObstaclePixels();
  EXPECT_EQ(400, dummyMap->obstaclesCoordinates[0].x);
  EXPECT_EQ(0, dummyMap->obstaclesCoordinates[0].y);
  int k = dummyMap->obstaclesCoordinates.size() - 1;
  EXPECT_EQ(365, dummyMap->obstaclesCoordinates[k].x);
  EXPECT_EQ(465, dummyMap->obstaclesCoordinates[k].y);
}
/**
 * @brief Get coordinates of end nodes
 */
TEST(MapTest, endNodeCoordinates) {
  int mapX = 500;
  int mapY = 500;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  int r1x = 55;
  int r1y = 55;
  int g1x = 605;
  int g1y = 805;
  EXPECT_TRUE(dummyMap->validateCoordinatesOfEndNode(r1x, r1y));
  EXPECT_FALSE(dummyMap->validateCoordinatesOfEndNode(g1x, g1y));
}
/**
 * @brief Test to check if node is on obstacle
 */
TEST(MapTest, nodeCheck) {
  int mapX = 500;
  int mapY = 500;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  EXPECT_TRUE(dummyMap->nodeCheck(50, 50));
}
/**
 * @brief Test to check random node generation
 */
TEST(MapTest, randomNodes) {
  int mapX = 500;
  int mapY = 500;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  dummyMap->setRobotX(50);
  dummyMap->setRobotY(50);
  dummyMap->setGoalX(480);
  dummyMap->setGoalY(480);
  dummyMap->generateRandomNodes();
  EXPECT_EQ(50, dummyMap->randomNodes[0].getX());
  EXPECT_EQ(50, dummyMap->randomNodes[0].getY());
  int k = dummyMap->randomNodes.size() - 1;
  EXPECT_EQ(480, dummyMap->randomNodes[k].getX());
  EXPECT_EQ(480, dummyMap->randomNodes[k].getY());
}
/**
 * @brief Test to get random node in current area
 */
TEST(MapTest, getNodeTest) {
  int mapX = 500;
  int mapY = 500;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  cv::Point_<int> node;
  node = dummyMap->getNode(0, 0);
  ///! Since this random node generation range is kept high
  ///! It should get node anywhere in 50X50px from given
  ///! values of parameters in getNode();
  EXPECT_NEAR(25, node.x, 25);
  EXPECT_NEAR(25, node.y, 25);
}
/**
 * @brief Test to generate Neighbours
 */
TEST(MapTest, generateNeighbours) {
  int mapX = 500;
  int mapY = 500;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  dummyMap->readObstaclePixels();
  dummyMap->generateRandomNodes();
  dummyMap->drawNeighbours();
  ///! Distance between node and neighbour must within range of 0 to 150.
  EXPECT_NEAR(75, dummyMap->randomNodes[0].pathCosts[0], 75);
}
/**
 * @brief Test for optimum path generation
 */
TEST(MapTest, findOptimumPath) {
  int mapX = 500;
  int mapY = 500;
  int robotX = 50;
  int robotY = 50;
  int goalX = 480;
  int goalY = 480;
  cv::Mat image;
  image = cv::imread("../image/testMap.png", 1);
  if (!image.data) {
    std::cout << "Could not open or find the image" << std::endl;
  }
  std::shared_ptr<Map> dummyMap = std::make_shared < Map > (mapX, mapY, image);
  dummyMap->setRobotX(robotX);
  dummyMap->setRobotY(robotY);
  dummyMap->setGoalX(goalX);
  dummyMap->setGoalY(goalY);
  dummyMap->readObstaclePixels();
  dummyMap->generateRandomNodes();
  dummyMap->drawNeighbours();
  dummyMap->findOptimumPath();
  EXPECT_EQ(50, dummyMap->result[0]->getX());
  EXPECT_EQ(50, dummyMap->result[0]->getY());
  EXPECT_EQ(480, dummyMap->result[dummyMap->result.size() - 1]->getX());
  EXPECT_EQ(480, dummyMap->result[dummyMap->result.size() - 1]->getY());
}
/**
 * @brief Test for Node class initialization
 */
TEST(NodeTest, initializeNodeClass) {
  std::shared_ptr<Node> dummyNode = std::make_shared<Node>();
  dummyNode->setX(50);
  dummyNode->setY(50);
  EXPECT_EQ(50, dummyNode->getX());
  EXPECT_EQ(50, dummyNode->getY());
}
/**
 * @brief Test for Node class constructor
 */
TEST(NodeTest, classConstructor) {
  std::shared_ptr<Node> dummyNode = std::make_shared < Node
      > (50, 100, true, true);
  EXPECT_EQ(50, dummyNode->getX());
  EXPECT_EQ(100, dummyNode->getY());
  EXPECT_EQ(true, dummyNode->isRobotBool());
  EXPECT_EQ(true, dummyNode->isGoalBool());
}
/**
 * @brief Test for heuristic distance of the Node
 */
TEST(NodeTest, heuristicDistance) {
  std::shared_ptr<Node> dummyNode = std::make_shared<Node>();
  dummyNode->setHN(150);
  EXPECT_EQ(150, dummyNode->getHN());
}
