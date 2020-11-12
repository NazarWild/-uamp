cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)

find_library(TAGLIB taglib)

include_directories(
    src
    resources
    ../build/3dparty/taglib
    ../3dparty/taglib/taglib/ape
    ../3dparty/taglib/taglib/asf
    ../3dparty/taglib/taglib/flac
    ../3dparty/taglib/taglib/it
    ../3dparty/taglib/taglib/mod
    ../3dparty/taglib/taglib/mp4
    ../3dparty/taglib/taglib/mpc
    ../3dparty/taglib/taglib/mpeg
    ../3dparty/taglib/taglib/mpeg/id3v2
    ../3dparty/taglib/taglib/mpeg/id3v2/frames
    ../3dparty/taglib/taglib/ogg
    ../3dparty/taglib/taglib/riff
    ../3dparty/taglib/taglib/s3m
    ../3dparty/taglib/taglib/toolkit
    ../3dparty/taglib/taglib/trueaudio
    ../3dparty/taglib/taglib/wavpack
    ../3dparty/taglib/taglib/xm
    ../3dparty/taglib/taglib
)

add_compile_options(
    -std=c++17
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Gui Multimedia DBus MultimediaWidgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Gui Multimedia DBus MultimediaWidgets Sql REQUIRED)

add_executable(uamp main.cpp)

add_subdirectory(src
                resources)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::DBus
        Qt${QT_VERSION_MAJOR}::Sql
        liba
        tag
)

set_target_properties(uamp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../..)
