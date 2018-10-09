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
#include <iostream>
#include <vector>
#include <array>
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui.hpp>
class Map{
 private:
  int sizeX;  ///< Width of map in pixels
  int sizeY;  ///< height of map in pixels
  int robotX;  ///< X coodinates of robot
  int robotY;  ///< Y coodinates of robot
  int goalX;  ///< X coodinates of goal
  int goalY;  ///< Y coodinates of goal
 public:
  /**
   * @brief Default class constructor
   */
  Map();
  /**
   * @brief Constructor with initial values
   * @param sizeX - width of map in pixels
   * @param sizeY - height of map in pixels
   */
  Map(const int& sizeX, const int& sizeY);
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
   * @brief Find optimum path for given image and given
   *        robot coordinates
   * @param image - png image of the map
   * @param robotX - X coodinates of robot
   * @param robotY - Y coodinates of robot
   * @param goalX - X coodinates of goal
   * @param goalY - Y coodinates of goal
   * @return vector of arrays of coordinates
   */
  std::vector<std::array<int,2>> findOptimumPath(cv::Mat image,
					 const int& robotX, const int& robotY,
		                         const int& goalX, const int& goalY);
};
#endif  // INCLUDE_MAP_H_
