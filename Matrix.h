// file : Matrix.h
//   by : Prof. Allen
// desc : A matrix class definition
// --------------------------------------------------------
#include <string>

#ifndef CMATRIX_MATRIX_H
#define CMATRIX_MATRIX_H

class Matrix {
protected:
    int _rows;
    int _columns;
    int **_matrix;

public:

    // Constructors / Destructors
    // --------------------------------------------------------
    Matrix(); // default
    Matrix(int rows, int columns); // property constructor
    Matrix(int rows, int columns, int *list); // property constructor     
    ~Matrix(); // destructor

    // copy constructor
    Matrix(const Matrix& other);
    // copy assignment
    Matrix& operator=(const Matrix& rhs);

    // move constructor
    Matrix(Matrix&& other);
    // move assignment
    Matrix& operator=(Matrix&& rhs);

    // Accessors
    // --------------------------------------------------------
    int getRows();
    void setRows(int rows);

    int getColumns();
    void setColumns(int columns);

    void setMatrix(int *list);
    
    
    // Methods
    // --------------------------------------------------------
    bool hasBlock(int row, int column);
    void transpose();
    void flipVertical();
    void flipHorizontal();
    void clockwise();
    void anticlockwise();

    std::string toString();

private:
    void init();
    void erase();
    void copyMatrix(int** rhs);
};


#endif //CMATRIX_MATRIX_H
