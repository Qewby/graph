cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME graph)
project(${PROJECT_NAME})

set(SOURCE_FILES HelloWorldApp.cpp HelloWorldApp.h libs/mathplot.cpp libs/mathplot.h MyFunction.cpp MyFunction.h GraphFrame.cpp GraphFrame.h)
set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})