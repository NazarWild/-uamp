cmake_minimum_required(VERSION 3.17.2)

project(uamp)

set(CMAKE_CXX_STANDARD 17)

include_directories(app)

include_directories(3dparty/taglib)

add_subdirectory(app)

add_subdirectory(3dparty/taglib)
