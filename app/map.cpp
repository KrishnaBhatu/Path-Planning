/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file    map.cpp
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief class for map of an image;
 *
 *  @section DESCRIPTION
 *
 *  This source file implements a Map class.
 *  The class contains methods to get and set
 *  size of a map.
 *
 */
#include "../include/map.h"
///! Default Constructor
Map::Map() {
  
}
///! Constructor with initial values
Map::Map(const int& x, const int& y, const cv::Mat &imageMap) {
  
}
///! Default Destructor
Map::~Map() {
}
///! Get map width in pixels
int Map::getSizeX() {
  return 0;
}
///! Set map width
void Map::setSizeX(const int& x) {
  
}
///! Get map height in pixels
int Map::getSizeY() {
  return 0;
}
///! Set map height
void Map::setSizeY(const int& y) {
 
}
///! Get robot x coordinate
int Map::getRobotX() {
  return 0;
}
///! Set robot x coordinate
void Map::setRobotX(const int& x) {
  
}
///! Get robot y coordinate
int Map::getRobotY() {
  return 0;
}
///! Set robot y coordinate
void Map::setRobotY(const int& y) {
  
}
///! Get goal x coordinate
int Map::getGoalX() {
  return 0;
}
///! Set goal x coordinate
void Map::setGoalX(const int& x) {
 
}
///! Get goal y coordinate
int Map::getGoalY() {
  return 0;
}
///! Set goal y coordinate
void Map::setGoalY(const int& y) {
  
}
///! Read image and store obstacle coordinates
void Map::readObstaclePixels() {
  
}
///! Ask user for coordinates of robot and goal location
bool Map::validateCoordinatesOfEndNode(const int&x, const int&y) {
  return false;
}
///! Check if robot or goal coordinates lie on obstacle
bool Map::nodeCheck(int x, int y) {
  return false;
}
///! Generate radom nodes in free space
void Map::generateRandomNodes() {
  
}
///! Get random node in current area of image
cv::Point_<int> Map::getNode(int i, int j) {
  return cv::Point_<int>(0,0);
}
///! Generate neighbours for every node
void Map::generateNeighbours() {
}
///! Draw lines between neighbours
void Map::drawNeighbours() {
}
///! Find optimum path for given image and given robot coordinates
void Map::findOptimumPath() {
}
