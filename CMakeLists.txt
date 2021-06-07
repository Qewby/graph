cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME graph)
project(${PROJECT_NAME})

set(SOURCE_FILES src/MainApp.cpp src/MainApp.h libs/mathplot.cpp libs/mathplot.h src/MyFunction.cpp src/MyFunction.h src/GraphPanel.cpp src/GraphPanel.h src/MainFrame.cpp src/MainFrame.h)
set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})