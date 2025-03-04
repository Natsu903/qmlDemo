cmake_minimum_required(VERSION 3.20)
project(player)
###QT库设置
find_package(Qt6 COMPONENTS Quick REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
###opencv库设置
set(OPENCVPATH "${CMAKE_CURRENT_LIST_DIR}/../lib/opencv/")
if(MINGW)
    set(TOOL "mingw")
    string(APPEND OPENCVPATH "mingw")
endif()
if(MSVC)
    set(TOOL "msvc")
    string(APPEND OPENCVPATH "msvc")
endif()

find_package(OpenCV REQUIRED PATHS OPENCVPATH)

add_executable(${PROJECT_NAME}
    main.cpp
    qml.qrc
    myvideo.h myvideo.cpp
)

qt_add_qml_module(
    ${PROJECT_NAME}
    URI myvideo
)

set(QML_IMPORT_PATH "${CMAKE_BINARY_DIR}"
    CACHE STRING "Qt Creator 4.1 extra qml import paths")

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt6::Quick
    ${OpenCV_LIBS}
)

#项目输出路径

set(RUNTIME "${CMAKE_CURRENT_LIST_DIR}/../bin/${TOOL}")
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${RUNTIME}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${RUNTIME}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RUNTIME}
)
