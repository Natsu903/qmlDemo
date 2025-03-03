cmake_minimum_required(VERSION 3.20)
project(player)
###QT库设置
find_package(Qt6 COMPONENTS Quick REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
###opencv库设置
find_package(OpenCV REQUIRED PATHS "${CMAKE_CURRENT_LIST_DIR}/../lib/opencv/mingw")


add_executable(${PROJECT_NAME}
    main.cpp
    qml.qrc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt6::Quick
    ${OPENCV_LIBS}
)
