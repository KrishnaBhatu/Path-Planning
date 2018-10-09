/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file    pixel.h
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief class for pixel on an image;
 *
 *  @section DESCRIPTION
 *
 *  Pixel class defines properties and functions of a
 *  pixel on an image.
 *
 */
#ifndef INCLUDE_PIXEL_H_
#define INCLUDE_PIXEL_H_
#include <iostream>
#include <vector>
class Pixel{
 private:
  int x;  ///< x coordinate of the pixel
  int y;  ///< y coordinate of the pixel
 public:
  /**
  * @brief Default Constructor	
  */	
  Pixel();
  /**
   * @brief Constructor with initial values
   * @param x - x coordinate of the pixel
   * @param y - y coordinate of the pixel
   */
  Pixel(int& x, int& y);
  /**
   * @brief Default destructor
   */
  ~Pixel();
  /**
   * @brief Set x value of the pixel
   * @param int value of x coordinate
   * @return void
   */
  void setX(int& x);
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
  void setY(int& y);
  /**
   * @brief get y value of the pixel
   * @return y coordinate of the pixel
   */
  int getY();
};
#endif  // INCLUDE_PIXEL_H_
