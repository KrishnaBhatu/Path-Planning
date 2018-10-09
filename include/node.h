/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file    node.h
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief class for random nodes on the map
 *
 *  @section DESCRIPTION
 *
 *  Node class defines properties and functions for
 *  all the random nodes, robot node and goal node.
 *
 */
#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_
#include <iostream>
#include <vector>
#include <memory>
#include "pixel.h"

class Node : public Pixel {
 private:
  bool isGoal;  ///< check if node is goal node
  bool isRobot;  ///< check if node is robot node
  std::shared_ptr<Node> parent;  ///< parent node
  int hN;  ///< heuristic distance
  int gN;  ///< distance from start node
  int fN;  ///< h_n + f_n
 public:
  std::vector<Node> neighbours;  ///< vector of all neighbours
  std::vector<int> pathCosts;  ///< vector of distance to all neighbours
  /**
   * @brief Default Constructor
   */
  Node();
  /**
   * @brief Constructor with initial values
   * @param centerX ///< x coordinate of center pixel
   * @param centerY ///< y coordinate of center pixel
   * @param isRobot ///< check if node is robot node
   * @param isGoal ///< check if node is goal node
   */
  Node(const int &centerX, const int &centerY, const bool &isRobot,
       const bool &isGoal);
  /**
   * @brief Default destructor
   */
  ~Node();
  /**
   * @return boolean value indicating if node is robot
   */
  bool isRobotBool();
  /**
   * @return boolean value indicating if node is goal
   */
  bool isGoalBool();
  /**
   * @brief set parent node for current node
   * @param Node object
   * @return void	
   */
  void setParent(std::shared_ptr<Node> n);
  /**
   * @return parent Node object
   */
  std::shared_ptr<Node> getParent();
  /**
   * @brief set heuristic distance
   * @param h_n - heuristic value
   * @return void
   */
  void setHN(const int& hN);
  /**
   * @return distance from starting node
   * @return heuristic distance
   */
  int getHN();
  /**
   * @brief set distance from starting node
   * @param g_n - distance from starting value
   * @return void   
   */
  void setGN(const int& gN);
  /**
   * @return distance from starting node
   */
  int getGN();
  /**
   * @brief set functional distance
   * @param f_n - h_n + g_n
   * @return void
   */
  void setFN(const int& fN);
  /**
   * @return functional distance
   */
  int getFN();
};
#endif  // INCLUDE_NODE_H_
