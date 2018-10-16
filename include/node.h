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
#include <vector>
#include <memory>
class Node {
 private:
  bool isGoal;  ///< check if node is goal node
  bool isRobot;  ///< check if node is robot node
  int x;  ///< x coordinate of the pixel
  int y;  ///< y coordinate of the pixel
  int hN;  ///< heuristic distance

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
  Node(const int &nodeX, const int &nodeY, const bool &isRob,
       const bool &isGl);
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
   * @brief set heuristic distance
   * @param h_n - heuristic value
   * @return void
   */
  void setHN(const int& hn);
  /**
   * @return distance from starting node
   * @return heuristic distance
   */
  int getHN();
  /**
   * @brief Set x value of the pixel
   * @param int value of x coordinate
   * @return void
   */
  void setX(const int& xP);
  /**
   * @brief get x value of the pixel
   * @return x coordinate of the pixel
   */
  int getX();
  /**
   * @brief Set y value of the pixel
   * @param int value of y coordinate
   * @return void
   */
  void setY(const int& yP);
  /**
   * @brief get y value of the pixel
   * @return y coordinate of the pixel
   */
  int getY();
};
#endif  // INCLUDE_NODE_H_
