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
/// Initializes parameters to zero
Map::Map() {
  sizeX = 0;
  sizeY = 0;
  robotX = 0;
  robotY = 0;
  goalX = 480;
  goalY = 480;
}
/// Initializes parameters to user input
Map::Map(const int& x, const int& y, const cv::Mat &imageMap) {
  sizeX = x;
  sizeY = y;
  image = imageMap;
  robotX = 0;
  robotY = 0;
  goalX = 480;
  goalY = 480;
}
/// Clears memory pointer to the object.
Map::~Map() {
}
/// Returns map width in pixels
int Map::getSizeX() {
  return sizeX;
}
/// Sets map width
void Map::setSizeX(const int& x) {
  sizeX = x;
}
/// Returns map height in pixels
int Map::getSizeY() {
  return sizeY;
}
/// Sets map height
void Map::setSizeY(const int& y) {
  sizeY = y;
}
/// Returns robot x coordinate
int Map::getRobotX() {
  return robotX;
}
/// Sets robot x coordinate
void Map::setRobotX(const int& x) {
  robotX = x;
}
/// Returns robot y coordinate
int Map::getRobotY() {
  return robotY;
}
/// Sets robot y coordinate
void Map::setRobotY(const int& y) {
  robotY = y;
}
/// Returns goal x coordinate
int Map::getGoalX() {
  return goalX;
}
/// Sets goal x coordinate
void Map::setGoalX(const int& x) {
  goalX = x;
}
/// Returns goal y coordinate
int Map::getGoalY() {
  return goalY;
}
/// Sets goal y coordinate
void Map::setGoalY(const int& y) {
  goalY = y;
}
/// Detects obstacles and stores their coordinates
void Map::readObstaclePixels() {
  cv::Mat greyImage, threshImage, dilatedImage, kernel, sub;
  cv::cvtColor(image, greyImage, CV_BGR2GRAY);
  cv::threshold(greyImage, threshImage, 127, 255, CV_THRESH_BINARY);
  kernel = cv::Mat::ones(10, 10, CV_32F);
  cv::erode(threshImage, dilatedImage, kernel);
  int i = 0, j = 0;
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
/// Validates coordinates of robot and goal location
bool Map::validateCoordinatesOfEndNode(const int& x, const int& y) {
  bool isValidInput = nodeCheck(x, y);
  if (x > 499 || y > 499 || x < 0 || y < 0) {
    isValidInput = false;
  }
  return isValidInput;
}
/// Checks if robot or goal coordinates lie on obstacle
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
  return notOnObstacle;
}
/// Generates radom nodes in free space
void Map::generateRandomNodes() {
  randomNodes.emplace_back(Node(robotX, robotY, true, false));
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
  randomNodes.emplace_back(Node(goalX, goalY, false, true));
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
/// Returns random node in current area of image
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
/// Generates neighbours for every node
void Map::generateNeighbours() {
std::cout << "Generating neighbours. Please wait." << std::endl;
  int dist;
  double line;
  std::vector<std::vector<Node>> neighbourVec;
  std::vector<std::vector<int>> pathCostsTemp;
  for (auto ncheck : randomNodes) {
    std::vector<Node> tempN;
    std::vector<int> tempP;
    for (auto nAll : randomNodes) {
      dist = sqrt(
          pow((ncheck.getX() - nAll.getX()), 2)
              + pow((ncheck.getY() - nAll.getY()), 2));
      if (dist < 150) {
        if (dist != 0) {
          bool test = true;
          for (auto obs : obstaclesCoordinates) {
            line = ((obs.y - nAll.getY()) * (nAll.getX() - ncheck.getX()))
                - ((obs.x - nAll.getX()) * (nAll.getY() - ncheck.getY()));
            if (line == 0) {
              if (((nAll.getX() - obs.x) <= 0 && (ncheck.getX() - obs.x) >= 0)
|| ((nAll.getX() - obs.x) >= 0 &&
(ncheck.getX() - obs.x) <= 0)) {
                if (((nAll.getY() - obs.y) <= 0 && (ncheck.getY() - obs.y) >= 0)
                    || ((nAll.getY() - obs.y) >= 0
                        && (ncheck.getY() - obs.y) <= 0)) {
                  test = false;
                  break;
                }
                }
              }
            }
          if (test) {
            tempN.emplace_back(nAll);
            tempP.emplace_back(dist);
          }
         }
        }
      }
    neighbourVec.emplace_back(tempN);
    pathCostsTemp.emplace_back(tempP);
    }
  int count = 0;
  for (auto && n : randomNodes) {
    n.neighbours = neighbourVec[count];
    n.pathCosts = pathCostsTemp[count];
  count++;
  }
}
/// Draws lines between neighbours
void Map::drawNeighbours() {
  generateNeighbours();
for (Node n : randomNodes) {
  for (Node nn : n.neighbours) {
    cv::line(Map::image, cv::Point_<int>(n.getX(), n.getY()),
        cv::Point_<int>(nn.getX(), nn.getY()),
        cv::Scalar_<double>(160, 160, 160));
    }
  }
}
/// Finds optimum path for given image and given robot coordinates
void Map::findOptimumPath() {
  result.emplace_back(std::make_shared < Node > (randomNodes[0]));
  int currNode = 0;
  while (!result.empty()) {
  int n_count = 0;
  int smallest = 800;
  int index = 0;
    for (auto && n : result[currNode]->neighbours) {
    double hn = sqrt(pow((n.getX() - randomNodes[randomNodes.size()-1].getX()),
2)+ pow((n.getY() - randomNodes[randomNodes.size()-1].getY()), 2));
  n.setHN(hn);
    if (n.getHN() < smallest) {
      smallest = n.getHN();
        index = n_count;
      }
    n_count++;
  }
    unsigned int rNodeIndex = 0;
  int rCount = 0;
  for (Node n : randomNodes) {
      if (n.getX() == result[currNode]->neighbours[index].getX()
          && n.getY() == result[currNode]->neighbours[index].getY()) {
      rNodeIndex = rCount;
      break;
    }
  rCount++;
}
  currNode++;
    result.emplace_back(std::make_shared < Node > (randomNodes[rNodeIndex]));
  if (rNodeIndex == randomNodes.size() - 1) {
    break;
  }
}
  for (unsigned int i = 0; i < (result.size() - 1); i++) {
  cv::line(
      Map::image,
      cv::Point_<int>(result[i]->getX(), result[i]->getY()),
             cv::Point_<int>(result[i + 1]->getX(), result[i + 1]->getY()),
      cv::Scalar_<double>(255, 255, 0), 3);
  }
}
