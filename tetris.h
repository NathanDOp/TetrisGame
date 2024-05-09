//  file: tetris.h
// class: COP 3003 Programming II
//    by: Nathan D'Agostino
//  desc: global constants and types for a tetris game app
// --------------------------------------------------------
#include <SFML/Graphics.hpp>

#ifndef TETRIS3_TETRIS_H
#define TETRIS3_TETRIS_H

const int FPS = 30;     // how many update frames per second
const int FRAME_RATE_MS = (1.f / float(FPS) * 1000.f); // per millisecond

const int FRAMES_NEW_SHAPE = 45;    // default rate to show next shape
const int FRAMES_AUTO_MOVE = 30;    // default rate that a shape auto moves downward

// The number of rows and columns that make up the grid
// in the Tetris gameboard
const int GAME_ROWS = 21;
const int GAME_COLUMNS = 10;

// Size of a square block (width & height) of each block in the
// Tetris gameboard grid and individual blocks of a Tetromino shape
const int BLOCK_SIZE = 30;  // width & height in pixels

// calculate required window size to accommodate game rows x columns with
// one block size of margin around the gameboard
const int WIN_WIDTH  = GAME_COLUMNS * BLOCK_SIZE + (2 * BLOCK_SIZE); // 1 block on left & right of gameboard
const int WIN_HEIGHT = GAME_ROWS * BLOCK_SIZE + (2 * BLOCK_SIZE);    // 1 block on top & bottom of gameboard

const int GRID_LEFT = BLOCK_SIZE;
const int GRID_TOP = BLOCK_SIZE;

const int START_CELL_COLUMN = 3;    // column 4, array index 3
const int START_CELL_ROW = 20;      // Top row 21, array index 20

const sf::Color BACKGROUND_COLOR = sf::Color::Black;
const sf::Color GRID_COLOR = sf::Color(0xD3, 0xD3, 0xD3, 50); // light grey 50/255 ~20% Opacity

struct KeyPressedState {    // maintain state of each input key across frames
    bool prior;             // state of key in prior frame: Pressed = true
    bool current;           // state of key for this frame: Pressed = true
};

#endif //TETRIS3_TETRIS_H

