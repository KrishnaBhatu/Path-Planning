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
#include "node.h"
#include <memory>
/// Default Constructor
Node::Node(){
}
/// Constructor with initial values
Node::Node(const int &centerX, const int &centerY, const bool &isRobot,
           const bool &isGoal){
}
/// Default destructor
Node::~Node(){}
/// get boolean value indicating if node is robot
bool Node::isRobotBool(){
  return true;
}
/// get boolean value indicating if node is goal
bool Node::isGoalBool(){
  return true;
}
/// set parent node for current node
void Node::setParent(std::shared_ptr<Node> n){
  
}
/// get parent Node object
std::shared_ptr<Node> Node::getParent(){
  return this->parent;
}
/// set heuristic distance
void Node::setHN(const int& hN){
  
}
/// get distance from starting node
int Node::getHN(){
  return -1;
}
/// set distance from starting node
void Node::setGN(const int& gN){
}
/// get distance from starting node
int Node::getGN(){
  return -1;
}
/// set functional distance
void Node::setFN(const int& fN){
  
}
/// get functional distance
int Node::getFN(){
  return -1;
}
