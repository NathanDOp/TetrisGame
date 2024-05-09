cmake_minimum_required(VERSION 3.24)
project(TetrisFINAL)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:\\SFML-2.6.0")
set(SFML_STATIC_LIBRARIES TRUE)

list(APPEND CMAKE_PREFIX_PATH "${SFML_DIR}/lib/cmake/")
include_directories("${SFML_DIR}/include")
link_directories("${SFML_DIR}/lib")
find_package(SFML COMPONENTS system window graphics)
add_executable(TetrisFINAL tetris.cpp Tetromino.cpp Tetromino.h Matrix.cpp Matrix.h tetris.h TetrisBoard.cpp TetrisBoard.h ShapeZ.h ShapeI.h ShapeJ.h ShapeL.h ShapeO.h)
target_link_libraries(TetrisFINAL sfml-graphics sfml-window sfml-system)