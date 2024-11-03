cmake_minimum_required(VERSION 3.10)
project(TvShowsPlatform)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(TvShowsPlatform src/main.cpp src/TvShow.cpp)
