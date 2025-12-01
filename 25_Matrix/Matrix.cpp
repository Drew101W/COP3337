#include "Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int rows, int cols) {
    if (rows < 1 || cols < 1) {
        this->rows = 0;
        this->cols = 0;
        throw std::logic_error("Rows and cols should be positive\n");
    }

    this->rows = rows;
    this->cols = cols;

    data = new int*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        data[i] = new int[this->cols];
    }
    
    // initialize the values with 0's
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            data[i][j] = 0;
        }
    }


    Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix::Matrix(const Matrix &m) {
    rows = m.rows;
    cols = m.cols;

    data = new int*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        data[i] = new int[this->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            data[i][j] = m.data[i][j];
        }
    }


    Matrix& Matrix::operator=(const Matrix &other) {

    rows = m.rows;
    cols = m.cols;

    data = new int*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        data[i] = new int[this->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            data[i][j] = m.data[i][j];
        }

        return *this;
    }
}

}
}

    void print() const;
