// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
void printFirstNTerms() {
  int n; 
  std::cout << "How many terms? ";
  std::cin >> n;
  if (n <= 0) {
    std::cout << "Please enter a positive number.\n";
    return;
}
long long a = 0, b = 1;
std::cout << "Fibonacci Series: ";
for (int i = 0; i < n; ++i) {
  std::cout << a << (i == n - 1 ? "" : " ");
  long long next = a + b;
    a = b;
    b = next;
  }
  std::cout << "\n";
}
void checkIfFibonacci() {
  long long num;
  std::cout << "Enter a number to check:";
  std::cin >> num;
  if (num < 0) {
    std::cout << "Please enter a non-negative number.\n";
    return;
  }
  long long a = 0, b = 1;
  while (a < num) {
    long long next = a + b;
    a = b;
    b = next;
  }
  if (a == num) {
    std::cout << num << " is in the Fibonacci series.\n";
  } else {
    std::cout << num << " is not in the Fibonacci series.\n";
  }
}
int main() {
  printFirstNTerms();
  std::cout << "\n";
  checkIfFibonacci();
  return 0; 
}
