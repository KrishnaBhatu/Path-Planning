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
#include "map.h"
  /// Default Constructor
  Map::Map(){
  
  }
  /// Constructor with initial values
  Map::Map(const int& sizeX, const int& sizeY){
  
  }
  /// Default Destructor
  Map::~Map(){
  
  }
  /// get map width in pixels
  int Map::getSizeX(){
    return -1;
  }
  /// set map width
  void Map::setSizeX(const int& x){
    
  }
  /// get map height in pixels
  int Map::getSizeY(){
    return -1;
  }
  /// set map height
  void Map::setSizeY(const int& y){
    
  }
  /// get robot x coordinate
  int Map::getRobotX(){
    return -1;
  }
  /// set robot x coordinate
  void Map::setRobotX(const int& x){
    
  }
  /// get robot y coordinate
  int Map::getRobotY(){
    return -1;
  }
  /// set robot y coordinate
  void Map::setRobotY(const int& y){
    
  }
  /// get goal x coordinate
  int Map::getGoalX(){
    return -1;
  }
  /// set goal x coordinate
  void Map::setGoalX(const int& x){
    
  }
  /// get goal y coordinate
  int Map::getGoalY(){
    return -1;
  }
  /// set goal y coordinate
  void Map::setGoalY(const int& y){
    
  }
  /// Find optimum path for given image and given robot coordinates
  std::vector<std::array<int,2>> Map::findOptimumPath(cv::Mat image,
					 const int& robotX, const int& robotY,
		                         const int& goalX, const int& goalY){
    return {{-1,-1},{-2,-2}};
  }
