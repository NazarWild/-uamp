cmake_minimum_required(VERSION 3.17.2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES mainwindow.cpp recentlyused.cpp playlists.cpp Player.cpp Controls.cpp)

set(HEADERS mainwindow.h recentlyused.h playlists.h Player.h Controls.h)

set(UI mainwindow.ui recentlyused.ui playlists.ui)

add_library(liba ${SOURCES} ${HEADERS} ${UI})

target_link_libraries(liba PRIVATE Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::DBus
        Qt${QT_VERSION_MAJOR}::Sql
)
