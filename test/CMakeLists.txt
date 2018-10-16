set(GTEST_SHUFFLE 1)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../app/map.cpp
    ../app/node.cpp	
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
