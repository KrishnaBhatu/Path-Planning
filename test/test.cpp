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
#include "map.h"
#include "node.h"
#include "pixel.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp" 
/**
 * @brief Test for class initialization
 */
TEST(MapTest,classInitialization) {
  std::shared_ptr<Map> dummyMap = std::make_shared<Map>();
  int mapX = 500; 
  int mapY = 500;	  
  dummyMap->setSizeX(mapX);
  dummyMap->setSizeY(mapY);
  EXPECT_EQ(500, dummyMap->getSizeX());
  EXPECT_EQ(500, dummyMap->getSizeY());
}
/**
 * @brief Test for start and end node location
 */
TEST(MapTest, robotAndGoalLocation) {
  int mapX = 500; 
  int mapY = 500;
  int robX = 10;
  int robY = 10;
  int goalX = 10;
  int goalY = 10;
  std::shared_ptr<Map> dummyMap = std::make_shared<Map>(mapX,mapY);
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
 * @brief Test for optimum path generation function
 */
TEST(MapTest, findOptimumPath) {
  int mapX = 500; 
  int mapY = 500;
  cv::Mat image;
  image = cv::imread( "testMap.png", 1 );
  std::shared_ptr<Map> dummyMap = std::make_shared<Map>(mapX,mapY);
  int robX = 0;
  int robY = 0;
  int goalX = 10;
  int goalY = 10;
  std::vector<std::array<int,2>> output = dummyMap->findOptimumPath(image, robX,
							    robY, goalX, goalY);
  EXPECT_EQ(output[0][0], dummyMap->getRobotX());
  EXPECT_EQ(output[0][1], dummyMap->getRobotY());
}
/**
 * @brief Test for node class initialization
 */
TEST(NodeTest, classInitialization) {
  std::shared_ptr<Node> dummyNode = std::make_shared<Node>();
  int nodeX = 0;
  int nodeY = 0;
  int hn = 0;
  int gn = 0;
  int fn = 0;
  dummyNode->setX(nodeX);
  dummyNode->setY(nodeY);
  dummyNode->setHN(hn);
  dummyNode->setGN(gn);
  dummyNode->setFN(fn);
  EXPECT_EQ(0, dummyNode->getX());
  EXPECT_EQ(0, dummyNode->getY());
  EXPECT_EQ(0, dummyNode->getHN());
  EXPECT_EQ(0, dummyNode->getGN());
  EXPECT_EQ(0, dummyNode->getFN());
  EXPECT_EQ(false, dummyNode->isRobotBool());
  EXPECT_EQ(false, dummyNode->isGoalBool());
}
/**
 * @brief Test for parent node of current node
 */
TEST(NodeTest, parentNode) {
  bool isRobot = false;
  bool isGoal = false;
  std::shared_ptr<Node> dummyNode = std::make_shared<Node>(0, 0, isRobot, isGoal);
  std::shared_ptr<Node> dummyParent = std::make_shared<Node>(10, 10, isRobot, isGoal);	
  dummyNode->setParent(dummyParent);
  EXPECT_EQ(dummyParent, dummyNode->getParent());
}
/**
 * @brief Test for default constructor
 */
TEST(PixelTest, defaultConstructor) {
  int x = 10;
  int y = 10;
  std::shared_ptr<Pixel> dummyPixel = std::make_shared<Pixel>();
  dummyPixel->setX(x);
  dummyPixel->setY(y);
  EXPECT_EQ(10, dummyPixel->getX());
  EXPECT_EQ(10, dummyPixel->getY());
}
/**
 * @brief Test for class constructor
 */
TEST(PixelTest, classConstructor) {
  int x = 10;
  int y = 10;
  std::shared_ptr<Pixel> dummyPixel = std::make_shared<Pixel>(x, y);
  EXPECT_EQ(10, dummyPixel->getX());
  EXPECT_EQ(10, dummyPixel->getY());
}
