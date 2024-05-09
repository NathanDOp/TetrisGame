//  file: Tetromino.cpp
// class: COP 3003 Programming II
//    by: Nathan D'Agostino
//  desc: Implementation of an abstract Tetromino shape
// audit: v2 - modified property constructor to pass through
//        base class Matrix, removed references to _shapes in
//        draw and rotate, added move method to move shape
//        left, right, and down.  Lastly added toString override
// --------------------------------------------------------
#include <sstream>
#include "Tetromino.h"

// Constructors
// --------------------------------------------------
Tetromino::Tetromino() {
    _shapeType = SHAPE_NONE;

    // all other properties are class objects with
    // their own default constructors
}

Tetromino::Tetromino(int rows, int columns)
        : Matrix{rows, columns} {
    _shapeType = SHAPE_NONE;

    // all other properties are class objects with
    // their own default constructors
}


Tetromino::Tetromino(int rows, int columns, int *blocks)
        : Matrix{rows, columns, blocks} {
    _shapeType = SHAPE_NONE;

    // all other properties are class objects with
    // their own default constructors
}

/**
 * draw the Tetromino by going through the Matrix and
 * creating a RectangleShape, sizing, positioning, and
 * filling its color, for any cells with a 1
 * @param window - target window to draw on
 */
void Tetromino::draw(sf::RenderWindow &window) {
    // calculate block size relative to size of
    // Tetromino and Matrix rows & columns
    sf::Vector2f blockSize { _size.x / _columns,
                             _size.y / _rows };

    // start block position at top left of Tetromino
    sf::Vector2f blockPos = _position;
    for (int row=0; row < _rows; ++row) {
        blockPos.x = _position.x;

        for (int col=0; col < _columns; ++col) {
            // see if cell in Matrix has a 1 in it
            if (hasBlock(row, col)) {
                // create temp block, position, and color it
                sf::RectangleShape block{blockSize};
                block.setPosition(blockPos);
                block.setFillColor(_fillColor);
                window.draw(block);
            }

            blockPos.x += blockSize.x;
        } // for each column

        blockPos.y += blockSize.y;
    } // for each row

} // end draw

/**
 * Rotate this shape counter-clockwise 90 degrees
 */
void Tetromino::rotate() {
    anticlockwise();
} // end rotate


/**
 * Move a Tetromino one block left, right, or down. No collision
 * checking is done here, so this should only be called if it is
 * possible to move in the direction given.
 * @param direction - move shape in given direction
 * @param blocks - the number of blocks to move
 */
void Tetromino::move(Tetromino::Movement direction, int blocks) {
    switch(direction) {
        case MoveLeft:
            _position.x -= (_size.x / _columns) * blocks;
            break;
        case MoveRight:
            _position.x += (_size.x / _columns) * blocks;
            break;
        case MoveDown:
            _position.y += (_size.y / _rows) * blocks;
    }
} // end move


/**
 * @return string representation of the matrix
 */
std::string Tetromino::toString() {
    std::stringstream ssShape;

    ssShape << " Tetromino:\n";
    ssShape << + "    Size: (" << int(_size.x) << "," << int(_size.y) << ")\n";
    ssShape << + "Position: (" << int(_position.x) << "," << int(_position.y) << ")\n";
    ssShape << + "   Color: (" << int(_fillColor.r) << "," << int(_fillColor.g)
            << "," << int(_fillColor.b) << ")\n";
    ssShape << "    Matrix: \n";
    ssShape << Matrix::toString() << std::endl;

    return ssShape.str();
}



