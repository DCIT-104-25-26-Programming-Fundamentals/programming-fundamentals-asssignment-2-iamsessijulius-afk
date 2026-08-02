// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> read_matrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
      cout << "Enter row " << (i + 1) << ": ";
      for (int j = 0; j < cols; ++j) {
        cin >> matrix[i][j];
        }
    }
    return matrix;
}
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
      for (int val : row) {
        cout << val << " ";
      }
      cout << endl;
    }
}
vector<vector<int>> transpose_matrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> result(cols, vector<int>(rows));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result[j][i] = matrix[i][j];
      }
    }
    return result;
}
vector<vector<int>> add_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result[i][j] = A[i][j] + B[i][j];
      }
    }
    return result;
}
vector<vector<int>> multiply_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; ++i) {
      for (int j = 0; j < colsB; ++j) {
        for (int k = 0; k < colsA; ++k) {
          result[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    return result;
}
int main() {
  int r, c;
  cout << " PART A: Transpose " << endl;
  cout << "Enter number of rows: ";
  cin >> r;
  cout << "Enter number of columns: ";
  cin >> c;
  vector<vector<int>> A = read_matrix(r, c);
  cout << "\nTransposed Matrix A:" << endl;
  print_matrix(transpose_matrix(A));
  cout << "\n PART B: Addition " << endl;
  cout << "Enter number of rows:";
  cin >> r;
  cout << "Enter number of columns:";
  cin >> c;
  cout << "Matrix A:" << endl;
  A = read_matrix(r, c);
  cout << "Matrix B:" << endl;
  vector<vector<int>> B = read_matrix(r, c);
  cout << "\nSum Matrix:" << endl;
  print_matrix(add_matrices(A, B));
  int r_A, c_A, r_B, c_B;
  cout << "\n PART C: Multiplication " << endl;
  cout << "Enter number of rows for Matrix A: ";
  cin >> r_A;
  cout << "Enter cols for A / rows for B: ";
  cin >> c_A;
  cout << "Enter number of columns for Matrix B: ";
  cin >> c_B;
  cout << "Matrix A:" << endl;
  A = read_matrix(r_A, c_A);
  cout << "Matrix B:" << endl;
  B = read_matrix(c_A, c_B);
  cout << "\nProduct Matrix:" << endl;
  print_matrix(multiply_matrices(A, B));
  return 0;
}

