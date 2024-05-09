//  file: ShapeZ.h
// class: COP 3003 Programming II
//    by: Nathan D'Agostino
//  desc: Z shape for game Tetris derived
//        from the base class Tetromino
// --------------------------------------------------------
#include "tetris.h"
#include "Tetromino.h"
#include <SFML/Graphics.hpp>

#ifndef TETRIS3_SHAPEZ_H
#define TETRIS3_SHAPEZ_H


class ShapeZ : public Tetromino {
private:

public:
    explicit ShapeZ(sf::Vector2f position={0.f, 0.f})
            : Tetromino(3, 3) {     // init rows and columns to 3x3
        // set the shape type
        _shapeType = SHAPE_Z;

        // define the matrix values
        int blocks[9] = { 0, 0, 0,
                          1, 1, 0,
                          0, 1, 1};
        // set the internal matrix
        setMatrix(blocks);

        // set the screen size, position, and color
        _size = sf::Vector2f(_rows * BLOCK_SIZE, _columns * BLOCK_SIZE);
        _position = position;
        _fillColor = sf::Color(RED);
    } // default constructor

}; // class ShapeZ


#endif //TETRIS3_SHAPEZ_H
