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
#include <memory>
/// Default Constructor
Node::Node() {
}
/// Constructor with initial values
Node::Node(const int &nodeX, const int &nodeY, const bool &isRob,
           const bool &isGl) {
}
/// Default destructor
Node::~Node() {
}
/// get boolean value indicating if node is robot
bool Node::isRobotBool() {
  return false;
}
/// get boolean value indicating if node is goal
bool Node::isGoalBool() {
  return false;
}
/// set parent node for current node
void Node::setParent(std::shared_ptr<Node> n) {
}
/// get parent Node object
std::shared_ptr<Node> Node::getParent() {
  return nullptr;
}
/// set heuristic distance
void Node::setHN(const int& hn) {
}
/// get distance from starting node
int Node::getHN() {
  return 0;
}
/// Set x value of the pixel
void Node::setX(const int& xP) {
}
/// Get x value of the pixel
int Node::getX() {
  return 0;
}
/// Set y value of the pixel
void Node::setY(const int& yP) {
}
/// Get y value of the pixel
int Node::getY() {
  return 0;
}
