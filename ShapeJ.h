//  file: ShapeJ.h
// class: COP 3003 Programming II
//    by: Nathan D'Agostino
//  desc: J shape for game Tetris derived
//        from the base class Tetromino
// --------------------------------------------------------
#include "tetris.h"
#include "Tetromino.h"
#include <SFML/Graphics.hpp>

#ifndef TETRIS3_SHAPEJ_H
#define TETRIS3_SHAPEJ_H


class ShapeJ : public Tetromino {
private:

public:
    explicit ShapeJ(sf::Vector2f position={0.f, 0.f})
            : Tetromino(3, 3) {     // init rows and columns to 3x3
        // set the shape type
        _shapeType = SHAPE_J;

        // define the matrix values
        int blocks[9] = { 0, 1, 0,
                          0, 1, 0,
                          1, 1, 0 };
        // set the internal matrix
        setMatrix(blocks);

        // set the screen size, position, and color
        _size = sf::Vector2f(_rows * BLOCK_SIZE, _columns * BLOCK_SIZE);
        _position = position;
        _fillColor = sf::Color(DARK_BLUE);
    } // default constructor

}; // class ShapeJ


#endif //TETRIS3_SHAPEJ_H
