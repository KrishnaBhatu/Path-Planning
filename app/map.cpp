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
  sizeX = 0;
  sizeY = 0;
  robotX = 0;  ///< X coodinates of robot
  robotY = 0;  ///< Y coodinates of robot
  goalX = 480;  ///< X coodinates of goal
  goalY = 480;
}
///! Constructor with initial values
Map::Map(const int& x, const int& y, const cv::Mat &imageMap) {
  sizeX = x;
  sizeY = y;
  image = imageMap;
}
///! Default Destructor
Map::~Map() {
}
///! Get map width in pixels
int Map::getSizeX() {
  return sizeX;
}
///! Set map width
void Map::setSizeX(const int& x) {
  sizeX = x;
}
///! Get map height in pixels
int Map::getSizeY() {
  return sizeY;
}
///! Set map height
void Map::setSizeY(const int& y) {
  sizeY = y;
}
///! Get robot x coordinate
int Map::getRobotX() {
  return robotX;
}
///! Set robot x coordinate
void Map::setRobotX(const int& x) {
  robotX = x;
}
///! Get robot y coordinate
int Map::getRobotY() {
  return robotY;
}
///! Set robot y coordinate
void Map::setRobotY(const int& y) {
  robotY = y;
}
///! Get goal x coordinate
int Map::getGoalX() {
  return goalX;
}
///! Set goal x coordinate
void Map::setGoalX(const int& x) {
  goalX = x;
}
///! Get goal y coordinate
int Map::getGoalY() {
  return goalY;
}
///! Set goal y coordinate
void Map::setGoalY(const int& y) {
  goalY = y;
}
///! Read image and store obstacle coordinates
void Map::readObstaclePixels() {
  cv::Mat greyImage, threshImage, dilatedImage, kernel, sub;
  cv::cvtColor(image, greyImage, CV_BGR2GRAY);
  cv::threshold(greyImage, threshImage, 127, 255, CV_THRESH_BINARY);
  kernel = cv::Mat::ones(10, 10, CV_32F);
  cv::erode(threshImage, dilatedImage, kernel);
  unsigned int i = 0, j = 0;
  cv::MatIterator_<uchar> it, end;
  for (it = dilatedImage.begin<uchar>(), end = dilatedImage.end<uchar>();
      it != end; it++) {
    if (i == dilatedImage.cols) {
      j++;
      i = 0;
    }
    if (*it == static_cast<uchar>(0)) {
      obstaclesCoordinates.emplace_back(cv::Point_<int>(i, j));
    }
    i++;
  }
}
///! Ask user for coordinates of robot and goal location
bool Map::validateCoordinatesOfEndNode(const int& x, const int& y) {
  bool isValidInput = false;
  isValidInput = nodeCheck(x, y);
  if (x > 499 || y > 499 || x < 0 || y < 0) {
    isValidInput = false;
  }
  return isValidInput;
}
///! Check if robot or goal coordinates lie on obstacle
bool Map::nodeCheck(int x, int y) {
  bool notOnObstacle = true;
  for (int i = x; i < (x + 10); i++) {
    for (int j = y; j < (y + 10); j++) {
      for (auto pnt : obstaclesCoordinates) {
        if (i == pnt.x && j == pnt.y) {
          notOnObstacle = false;
          return notOnObstacle;
        }
      }
    }
  }
}
///! Generate radom nodes in free space
void Map::generateRandomNodes() {
  ///! create robot node
  randomNodes.emplace_back(Node(robotX, robotY, true, false));
  ///! code for generating random nodes
  int randx = 0;
  int randy = 0;
  int count = 0;
  int noOfPossibleNodesi = sizeY / 10;
  int noOfPossibleNodesj = sizeX / 10;

  for (int i = 0; i <= (sizeY - noOfPossibleNodesi); i += noOfPossibleNodesi) {
    for (int j = 0; j <= (sizeX - noOfPossibleNodesj); j +=
        noOfPossibleNodesj) {
      int attemptNodeMaking = 0;
      while (attemptNodeMaking < 25) {
        cv::Point_<int> node = getNode(i, j);
        bool NodeValid = nodeCheck(node.x, node.y);
        if (NodeValid) {
          randomNodes.emplace_back(Node(node.x, node.y, false, false));
          break;
        } else {
          attemptNodeMaking++;
        }
      }
    }
  }
  ///! create goal node
  randomNodes.emplace_back(Node(goalX, goalY, false, true));
  ///! draw nodes on image
  for (auto node : randomNodes) {
    int px1 = node.getX();
    int py1 = node.getY();
    int px2 = node.getX() + 10;
    int py2 = node.getY() + 10;
    if (node.isRobotBool()) {
      cv::rectangle(image, cv::Point_<int>(px1, py1), cv::Point_<int>(px2, py2),
                    cv::Scalar_<double>(255, 0, 0), -1);
    } else if (node.isGoalBool()) {
      cv::rectangle(image, cv::Point_<int>(px1, py1), cv::Point_<int>(px2, py2),
                    cv::Scalar_<double>(0, 255, 0), -1);
    } else {
      cv::rectangle(image, cv::Point_<int>(px1, py1), cv::Point_<int>(px2, py2),
                    cv::Scalar_<double>(0, 0, 255), -1);
    }
  }
}
///! Get random node in current area of image
cv::Point_<int> Map::getNode(int i, int j) {
  cv::Point_<int> node;
  int randx = rand() % 4;
  int randy = rand() % 4;
  int nx = randx * 10 + i;
  int ny = randy * 10 + j;
  node.x = nx;
  node.y = ny;
  return node;
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
