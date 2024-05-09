// file : Matrix.cpp
//   by : Prof. Allen
// desc : A matrix class implementation
// --------------------------------------------------------

#include "Matrix.h"
#include <utility>  // swap

// Constructors / Destructors
// --------------------------------------------------------

/**
 * Default constructor sets up an empty matrix (0x0)
 */
Matrix::Matrix() : _rows{0}, _columns{0}, _matrix{nullptr} { }

/**
 * Property constructor sets up an empty matrix with space
 *    for (rows x columns)
 * @param rows - number of rows
 * @param columns - number of columns
 */
Matrix::Matrix(int rows, int columns)
        : _rows{rows}, _columns{columns}, _matrix{nullptr} { }

/**
 * Property constructor sets up a matrix with space
 *    for (rows x columns) and sets initial values
 *    based on the list provided
 * @param rows - number of rows
 * @param columns - number of columns
 * @param list - list of initial values
 */
Matrix::Matrix(int rows, int columns, int *list)
        : _rows{rows}, _columns{columns}, _matrix{nullptr}
{
    setMatrix(list);
}

/**
 * Destructor - removes dynamic memory allocated for the matrix
 */
Matrix::~Matrix() {
    erase();
}

/**
 * Copy constructor
 * @param other - Matrix object to copy
 */
Matrix::Matrix(const Matrix& other) {

    erase(); // erase any existing data in this matrix

    // copy rows and columns of other
    this->_rows = other._rows;
    this->_columns = other._columns;

    // re-initialize this matrix
    init();

    // copy the matrix data from other
    copyMatrix(other._matrix);
} // copy constructor

/**
 * Copy assignment
 * @param rhs - Matrix being copied (right hand side)
 * @return pointer to this Matrix after copy
 */
Matrix& Matrix::operator=(const Matrix& rhs) {
    // self-assignment check
    if (this != &rhs) {
        erase(); // erase any existing data in this matrix

        // copy rows and columns of other
        this->_rows = rhs._rows;
        this->_columns = rhs._columns;

        // re-initialize this matrix
        init();

        // copy the matrix data from other
        copyMatrix(rhs._matrix);

    } // self check

    return *this;
} // copy assignment

/**
 * Move this object into memory of Matrix object
 * being removed
 * @param other - Matrix being replaced
 */
Matrix::Matrix(Matrix&& other) {
    this->_rows = other._rows;
    this->_columns = other._columns;
    this->_matrix = other._matrix; // copy 1st pointer from rhs
    other._matrix = nullptr; // prevent old from still pointing to matrix data
} // move constructor

/**
 * Move this object into memory of Matrix object
 * being removed
 * @param rhs - Matrix being moved (right hand side)
 * @return pointer to this Matrix after move
 */
Matrix& Matrix::operator=(Matrix&& rhs) {
    // self-assignment check
    if (this != &rhs) {

        erase(); // delete current matrix data

        // copy rows and columns of other
        this->_rows = rhs._rows;
        this->_columns = rhs._columns;


        this->_matrix = rhs._matrix; // copy 1st pointer from rhs
        rhs._matrix = nullptr; // prevent old from still pointing to matrix data

    } // self check

    return *this;
} // move assignment



// Accessors
// --------------------------------------------------------

int Matrix::getRows() {
    return _rows;
}

void Matrix::setRows(int rows) {
    _rows = rows;
    init(); // reinitialize the matrix
}

int Matrix::getColumns() {
    return _columns;
}

void Matrix::setColumns(int columns) {
    _columns = columns;
    init(); // reinitialize the matrix
}

void Matrix::setMatrix(int *list) {
    init(); // reinitialize the matrix

    if (list) {
        for (int row = 0; row < _rows; ++row) {
            for (int column = 0; column < _columns; ++column) {
                _matrix[row][column] = *list;   // copy from list to matrix
                ++list; // next item in list
            } // each column
        } // each row
    } // if list

} // setMatrix

// Methods
// --------------------------------------------------------

/**
 * Determine if a cell of the matrix has a 1 or 0
 * @param row - of the cell (0-indexed)
 * @param column - of the cell (0 - indexed)
 * @return true if the cell has a 1 or false
 */
bool Matrix::hasBlock(int row, int column) {
    return _matrix[row][column] == 1;
}

/**
 * Transpose the matrix along the diagonal axis from cell (0,0)
 * to cell (rows-1,columns-1)
 *   0 1 2     0 3 6
 *   3 4 5  => 1 4 7
 *   6 7 8     2 5 8
 */
void Matrix::transpose() {
    for (int row = 0; row < _rows; ++row) {
        for (int column = 0; column < row; ++column) {
            std::swap(_matrix[row][column], _matrix[column][row]);
        }
    }
}

/**
 * Flip the matrix by reversing the columns in each row
 *   0 1 2     6 7 8
 *   3 4 5  => 3 4 5
 *   6 7 8     0 1 2
 */
void Matrix::flipVertical() {

    for (int row=0; row < _rows / 2; ++row) {
        for (int column=0; column < _columns; ++column) {
            std::swap(_matrix[row][column],_matrix[_rows - row - 1][column]);
        }
    }

} // flipVertical

/**
 * Flip the matrix by reversing the rows across each column
 *   0 1 2     2 1 0
 *   3 4 5  => 5 4 3
 *   6 7 8     8 7 6
 */
void Matrix::flipHorizontal() {

    for (int row=0; row < _rows; ++row) {
        for (int column=0; column < _columns / 2; ++column) {
            std::swap(_matrix[row][column],_matrix[row][_columns - column - 1]);
        }
    }

} // flipHorizontal

/**
 * rotate the matrix clockwise
 *   0 1 2     6 3 0
 *   3 4 5  => 7 4 1
 *   6 7 8     8 5 2
 */
void Matrix::clockwise() {
    transpose();
    flipHorizontal();
} // clockwise

/**
 * rotate the matrix counter-clockwise
 *   0 1 2     2 5 8
 *   3 4 5  => 1 4 7
 *   6 7 8     0 3 6
 */
void Matrix::anticlockwise() {
    transpose();
    flipVertical();
} // anticlockwise


/**
 * @return string representation of the matrix
 */
std::string Matrix::toString() {
    std::string strMatrix{""};

    for (int row = 0; row < _rows; ++row) {
        for (int column = 0; column < _columns; ++column) {
            strMatrix += std::to_string(_matrix[row][column]);
            strMatrix += " ";
        }
        strMatrix += "\n";
    }

    return strMatrix;
} // toString


// Private Methods
// --------------------------------------------------------

/**
 * clear the previous matrix and re-size it
 */
void Matrix::init() {
    if (_matrix) {
        erase();
    }

    if (_rows > 0 && _columns > 0) {
        _matrix = new int*[_rows];

        for (int row = 0; row < _rows; ++row) {
            _matrix[row] = new int[_columns]{0};
        }

    } // rows & columns > 0
} // init

/**
 * delete the matrix
 */
void Matrix::erase() {
    if (_matrix) {
        for (int row = 0; row < _rows; ++row) {
            delete _matrix[row];
        }
        delete _matrix;
    }
} // erase

/**
 * Perform a deep copy of another matrix into this matrix
 * @param rhs - right hand side matrix (other)
 */
void Matrix::copyMatrix(int** rhs) {
    if (_matrix && rhs) {
        for (int row=0; row < _rows; ++row) {
            for (int column=0; column < _columns; ++column) {
                _matrix[row][column] = rhs[row][column];
            } // each column
        } // each row
    } // matrix and rhs exists
} // copyMatrix