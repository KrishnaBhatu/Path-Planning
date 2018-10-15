/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file    map.h
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief class for Map Image
 *
 *  @section DESCRIPTION
 *
 *  Map class defines properties and functions for
 *  a map image that will be provided as an input.
 *
 */
#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui.hpp>
#include "../include/node.h"
class Map{
 private:
  int sizeX;  ///< Width of map in pixels
  int sizeY;  ///< height of map in pixels
  int robotX;  ///< X coodinates of robot
  int robotY;  ///< Y coodinates of robot
  int goalX;  ///< X coodinates of goal
  int goalY;  ///< Y coodinates of goal

 public:
  ///< vector to store coordinates of obstacles
  std::vector<cv::Point_<int>> obstaclesCoordinates;
  ///< vector to store random Nodes
  std::vector<Node> randomNodes;
  ///< map image
  cv::Mat image;
  /**
   * @brief Default class constructor
   */
  Map();
  /**
   * @brief Constructor with initial values
   * @param sizeX - width of map in pixels
   * @param sizeY - height of map in pixels
   */
  Map(const int& x, const int& y, const cv::Mat &imageMap);
  /**
   * @brief Default destructor
   */
  ~Map();
  /**
   * @brief get map width in pixels
   * @return map width
   */
  int getSizeX();
  /**
   * @brief set map width
   * @return void
   */
  void setSizeX(const int& x);
  /**
   * @brief get map height in pixels
   * @return map height
   */
  int getSizeY();
  /**
   * @brief set map height
   * @return void
   */
  void setSizeY(const int& y);
  /**
   * @brief get robot x coordinate
   * @return x coordinate
   */
  int getRobotX();
  /**
   * @brief set robot x coordinate
   * @return void
   */
  void setRobotX(const int& x);
  /**
   * @brief get robot y coordinate
   * @return y coordinate
   */
  int getRobotY();
  /**
   * @brief set robot y coordinate
   * @return return
   */
  void setRobotY(const int& y);
  /**
   * @brief get goal x coordinate
   * @return x coordinate
   */
  int getGoalX();
  /**
   * @brief set goal x coordinate
   * @return void
   */
  void setGoalX(const int& x);
  /**
   * @brief get goal y coordinate
   * @return y coordinate
   */
  int getGoalY();
  /**
   * @brief set goal y coordinate
   * @return void
   */
  void setGoalY(const int& y);
  /**
   * @brief read image and store obstacle coordinates
   * @param map image
   */
  void readObstaclePixels();
  /**
   * @bried validate inputs from user
   * @param x coordinate
   * @param y coordinate
   * return validation boolean
   */
  bool validateCoordinatesOfEndNode(const int&x, const int&y);
  /**
   * @brief check if robot or goal lies on obstacle
   * @param robotX - x coordinate of robot
   * @param robotY - y coordinate of robot
   * @return if input is on obstacle
   */
  bool nodeCheck(int x, int y);
  /**
   * @brief generate random nodes in free space
   */
  void generateRandomNodes();
  /**
   * @brief get random node for current grid
   * @param i - column number
   * @param j - row number
   * @return random point in grid
   */
  cv::Point_<int> getNode(int i, int j);
  /**
   * @brief generate neighbours for each node
   */
  void generateNeighbours();
  /**
   * @brief draw neighbour paths
   */
  void drawNeighbours();
  /**
   * @brief Find optimum path for given image and given
   *        robot coordinates
   * @param image - png image of the map
   * @param robotX - X coodinates of robot
   * @param robotY - Y coodinates of robot
   * @param goalX - X coodinates of goal
   * @param goalY - Y coodinates of goal
   * @return void
   */
  void findOptimumPath();
};
#endif  // INCLUDE_MAP_H_
