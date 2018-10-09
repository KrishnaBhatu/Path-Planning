/**
 *  @copyright (c) 2018 Krishna Bhatu, Siddhesh Rane
 *  @file   main.cpp
 *  @author  Krishna Bhatu, Siddhesh Rane
 *
 *  @brief main class for unit testing;
 *
 *  @section DESCRIPTION
 *
 *  This file runs all the tests implemented by unit
 *  testing class.
 *
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
