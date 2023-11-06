cmake_minimum_required(VERSION 3.26)
project(PaintQt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(PaintQt src/main.cpp include/tool.h src/pen_tool.cpp include/pen_tool.h src/rectangle_shape.cpp include/rectangle_shape.h src/drawing_area.cpp include/drawing_area.h src/main_window.cpp include/main_window.h src/eraser_tool.cpp include/eraser_tool.h src/circle_shape.cpp include/circle_shape.h src/line_shape.cpp include/line_shape.h src/tool_manager.cpp include/tool_manager.h
        src/text_tool.cpp
        include/text_tool.h)
target_link_libraries(PaintQt
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

