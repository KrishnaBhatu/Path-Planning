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
#include "pixel.h"

class Node : public Pixel {
 private:
  bool isGoal;  ///< check if node is goal node
  bool isRobot;  ///< check if node is robot node
  Node* parent;  ///< parent node
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
   */
  void setParent(Node* n);
  /**
   * @return parent Node object
   */
  Node* getParent();
  /**
   * @brief set heuristic distance
   * @param h_n - heuristic value
   */
  void setHN(const int& hN);
  /**
   * @return distance from starting node
   */
  int getHN();
  /**
   * @brief set distance from starting node
   * @param g_n - distance from starting value
   */
  void setGN(const int& gN);
  /**
   * @return get distance from starting node
   */
  int getGN();
  /**
   * @brief set functional distance
   * @param f_n - h_n + g_n
   */
  void setFN(const int& fN);
  /**
   * @return functional distance
   */
  int getFN();
};
#endif  // INCLUDE_NODE_H_
