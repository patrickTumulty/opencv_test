cmake_minimum_required(VERSION 2.8)
project (OpenCVTest)

find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_executable(openCVTest main.cpp img_process.cpp)

target_link_libraries(openCVTest ${OpenCV_LIBS})
