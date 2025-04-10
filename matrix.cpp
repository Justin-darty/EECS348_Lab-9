#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

// Integer matrix constructor
Matrix::Matrix(std::size_t N) : size(N), matrix_int(N, std::vector<int>(N)), is_double(false) {}

// Integer matrix constructor
Matrix::Matrix(std::vector<std::vector<int>> nums) : size(nums.size()), matrix_int(nums), is_double(false) {}

// Double matrix constructor
Matrix::Matrix(std::vector<std::vector<double>> nums) : size(nums.size()), matrix_double(nums), is_double(true) {}

// Addition of two matrices
Matrix Matrix::operator+(const Matrix &rhs) const {
    if (this->size != rhs.size) {
        throw std::invalid_argument("Matrix sizes must be the same for addition.");
    }

    if (this->is_double != rhs.is_double) {
        throw std::invalid_argument("Matrix types (int/double) must match for addition.");
    }

    Matrix result(this->size);

    if (this->is_double) {
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                result.matrix_double[i][j] = this->matrix_double[i][j] + rhs.matrix_double[i][j];
            }
        }
    } else {
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                result.matrix_int[i][j] = this->matrix_int[i][j] + rhs.matrix_int[i][j];
            }
        }
    }
    return result;
}

// Multiplication of two matrices
Matrix Matrix::operator*(const Matrix &rhs) const {
    if (this->size != rhs.size) {
        throw std::invalid_argument("Matrix sizes must be the same for multiplication.");
    }

    Matrix result(this->size);

    if (this->is_double) {
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                result.matrix_double[i][j] = 0;
                for (std::size_t k = 0; k < size; ++k) {
                    result.matrix_double[i][j] += this->matrix_double[i][k] * rhs.matrix_double[k][j];
                }
            }
        }
    } else {
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                result.matrix_int[i][j] = 0;
                for (std::size_t k = 0; k < size; ++k) {
                    result.matrix_int[i][j] += this->matrix_int[i][k] * rhs.matrix_int[k][j];
                }
            }
        }
    }
    return result;
}

// Set value at (i, j)
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (is_double) {
        throw std::invalid_argument("Cannot set value for a double matrix using an int.");
    }
    matrix_int[i][j] = n;
}

// Get value at (i, j)
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (is_double) {
        throw std::invalid_argument("Matrix contains double values.");
    }
    return matrix_int[i][j];
}

// Get size of matrix
int Matrix::get_size() const {
    return size;
}

// Sum of the main diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        if (is_double) {
            sum += static_cast<int>(matrix_double[i][i]);
        } else {
            sum += matrix_int[i][i];
        }
    }
    return sum;
}

// Sum of the minor diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        if (is_double) {
            sum += static_cast<int>(matrix_double[i][size - 1 - i]);
        } else {
            sum += matrix_int[i][size - 1 - i];
        }
    }
    return sum;
}

// Swap rows of the matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (is_double) {
        std::swap(matrix_double[r1], matrix_double[r2]);
    } else {
        std::swap(matrix_int[r1], matrix_int[r2]);
    }
}

// Swap columns of the matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    for (std::size_t i = 0; i < size; ++i) {
        if (is_double) {
            std::swap(matrix_double[i][c1], matrix_double[i][c2]);
        } else {
            std::swap(matrix_int[i][c1], matrix_int[i][c2]);
        }
    }
}

// Print matrix
void Matrix::print_matrix() const {
    if (is_double) {
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                std::cout << std::setw(6) << matrix_double[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                std::cout << std::setw(6) << matrix_int[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
