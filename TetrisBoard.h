//  file: TetrisBoard.h
// class: COP 3003 Programming II
//    by: Nathan D'Agostino
//  desc: Main gameboard for Tetris
// --------------------------------------------------------
#include "tetris.h"
#include "Tetromino.h"
#include <random>
#include <SFML/Graphics.hpp>

#ifndef TETRIS3_TETRISBOARD_H
#define TETRIS3_TETRISBOARD_H


class TetrisBoard {
private:
    struct FrameCounters {
        int newShapeRate;
        int newShape;
        int autoMoveRate;
        int autoMove;
    };

    FrameCounters _counters;

    struct GridCell {
        bool filled;
        sf::RectangleShape block;
    };


    // grid cells by row and column
    GridCell _cells[GAME_ROWS][GAME_COLUMNS];

    // current and next shape
    Tetromino*      _currentShape;
    Tetromino*      _nextShape;

    // top/left row/column of grid for current shape
    sf::Vector2i    _currentCell;

    // properties for generating random numbers to select
    // the next Tetromino at random
    //      randomDevice is a seed for the generator
    //      uses a merseene_twister generator engine
    //      produces a uniform integer distribution
    std::random_device              _randDevice;
    std::mt19937                    _randGenerator;
    std::uniform_int_distribution<> _randDistribution;

    void nextShape();                                            // calculate next random shape

    bool canMoveShape(Tetromino::Movement direction);            // see if shape can move

    bool canRotateShape();                                       // Check to see if shape can be rotated

    void wallKick(sf::Vector2i location);                        // Make a shape perform a wall-kick

    bool hasCollision(Tetromino& shape, sf::Vector2i location);  // check to see if the shape has collision

    void lockShape();                                            // lock shape into board

    bool GameOver();                                             // Check to see if game ends

public:
    TetrisBoard();

    ~TetrisBoard();

    bool update(KeyPressedState input[]);

    void render(sf::RenderWindow & window);

};


#endif //TETRIS3_TETRISBOARD_H
