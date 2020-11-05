cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES mainwindow.cpp lib.cpp)

set(HEADERS mainwindow.h main_lib.h)

set(UI mainwindow.ui)

add_library(liba ${SOURCES} ${HEADERS} ${UI})

target_link_libraries(liba PRIVATE Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::DBus
)
