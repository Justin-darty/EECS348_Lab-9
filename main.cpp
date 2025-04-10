#include <iostream>
#include <fstream>
#include <sstream>
#include "matrix.hpp"

// Function to read matrix from file
Matrix read_matrix_from_file(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        exit(1);  // Exit if the file can't be opened
    }

    // Read N and type flag
    std::size_t N;
    int type_flag;
    file >> N >> type_flag;

    // Create a matrix based on the type flag (int or double)
    if (type_flag == 0) {  // Integer matrix
        std::vector<std::vector<int>> data(N, std::vector<int>(N));
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < N; ++j) {
                file >> data[i][j];
            }
        }
        return Matrix(data);
    } else {  // Double matrix
        std::vector<std::vector<double>> data(N, std::vector<double>(N));
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < N; ++j) {
                file >> data[i][j];
            }
        }
        return Matrix(data);  // Assuming Matrix has a constructor to handle double values
    }
}

int main() {
    // Ask user for input file name
    std::string filename;
    std::cout << "Enter the name of the input file: ";
    std::cin >> filename;

    // Load matrices from file
    Matrix matrix1 = read_matrix_from_file(filename);
    Matrix matrix2 = read_matrix_from_file(filename);  // Assuming same file is used for both matrices

    // Print matrices
    std::cout << "Matrix 1:" << std::endl;
    matrix1.print_matrix();
    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.print_matrix();

    // Add matrices
    Matrix result_add = matrix1 + matrix2;
    std::cout << "\nSum of Matrices:" << std::endl;
    result_add.print_matrix();

    // Multiply matrices
    Matrix result_mult = matrix1 * matrix2;
    std::cout << "\nProduct of Matrices:" << std::endl;
    result_mult.print_matrix();

    // Sum diagonals
    int major_diag_sum = matrix1.sum_diagonal_major();
    int minor_diag_sum = matrix1.sum_diagonal_minor();
    std::cout << "\nSum of Major Diagonal: " << major_diag_sum << std::endl;
    std::cout << "Sum of Minor Diagonal: " << minor_diag_sum << std::endl;

    // Swap rows and display the result
    matrix1.swap_rows(0, 1);
    std::cout << "\nAfter swapping rows 0 and 1:" << std::endl;
    matrix1.print_matrix();

    // Swap columns and display the result
    matrix1.swap_cols(0, 2);
    std::cout << "\nAfter swapping columns 0 and 2:" << std::endl;
    matrix1.print_matrix();

    // Update matrix value and display the result
    matrix1.set_value(1, 1, 99);
    std::cout << "\nAfter updating value at (1, 1) to 99:" << std::endl;
    matrix1.print_matrix();

    return 0;
}
