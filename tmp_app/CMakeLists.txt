cmake_minimum_required(VERSION 3.30)
project(tmp_app VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} main_app.cpp)