//  file: ShapeO.h
// class: COP 3003 Programming II
//    by: Nathan D'Agostino
//  desc: O shape for game Tetris derived
//        from the base class Tetromino
// --------------------------------------------------------
#include "tetris.h"
#include "Tetromino.h"
#include <SFML/Graphics.hpp>

#ifndef TETRIS3_SHAPEO_H
#define TETRIS3_SHAPEO_H


class ShapeO : public Tetromino {
private:

public:
    explicit ShapeO(sf::Vector2f position={0.f, 0.f})
            : Tetromino(3, 3) {     // init rows and columns to 3x3
        // set the shape type
        _shapeType = SHAPE_O;

        // define the matrix values
        int blocks[9] = { 0, 1, 1,
                          0, 1, 1,
                          0, 0, 0 };
        // set the internal matrix
        setMatrix(blocks);

        // set the screen size, position, and color
        _size = sf::Vector2f(_rows * BLOCK_SIZE, _columns * BLOCK_SIZE);
        _position = position;
        _fillColor = sf::Color(YELLOW);
    } // default constructor

}; // class ShapeO


#endif //TETRIS3_SHAPEO_H
