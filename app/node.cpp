/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file    node.cpp
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief class for pixel on an image;
 *
 *  @section DESCRIPTION
 *
 *  This source file implements a Node class.
 *  The class contains methods to get and set
 *  coordinate values of a node, set it's status
 *  and inform whether it is a robot or goal node.
 *
 */
#include "../include/node.h"
/// Default Constructor
Node::Node() {
  x = 0;
  y = 0;
  isGoal = false;
  isRobot = false;
  hN = 0;
}
/// Constructor with initial values
Node::Node(const int &nodeX, const int &nodeY, const bool &isRob,
           const bool &isGl) {
  x = nodeX;
  y = nodeY;
  isRobot = isRob;
  isGoal = isGl;
  hN = 0;
}
/// Default destructor
Node::~Node() {
}
/// get boolean value indicating if node is robot
bool Node::isRobotBool() {
  return isRobot;
}
/// get boolean value indicating if node is goal
bool Node::isGoalBool() {
  return isGoal;
}
/// set parent node for current node
void Node::setParent(std::shared_ptr<Node> n) {
  parent = n;
}
/// get parent Node object
std::shared_ptr<Node> Node::getParent() {
  return parent;
}
/// set heuristic distance
void Node::setHN(const int& hn) {
  hN = hn;
}
/// get distance from starting node
int Node::getHN() {
  return hN;
}
/// Set x value of the pixel
void Node::setX(const int& xP) {
  x = xP;
}
/// Get x value of the pixel
int Node::getX() {
  return x;
}
/// Set y value of the pixel
void Node::setY(const int& yP) {
  y = yP;
}
/// Get y value of the pixel
int Node::getY() {
  return y;
}
