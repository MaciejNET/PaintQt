cmake_minimum_required(VERSION 3.24)
project(PoProj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(PoProj main.cpp tool.h pen_tool.cpp pen_tool.h rectangle_shape.cpp rectangle_shape.h drawing_area.cpp drawing_area.h main_window.cpp main_window.h eraser_tool.cpp eraser_tool.h circle_shape.cpp circle_shape.h line_shape.cpp line_shape.h tool_manager.cpp tool_manager.h)
target_link_libraries(PoProj
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

