// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
#include <vector>
int getsum(const std::vector<int>& numbers) {
  int total = 0;
  for (int number : numbers) {
    total += number;
  }
  return total;
}
double getaverage(const std::vector<int>& numbers) {
  int total = getsum(numbers);
  return (double)total / numbers.size();
  }
  int getmax(const std::vector<int>& numbers) {
    int highest = numbers[0];
    for (int number : numbers) {
      if (number > highest) {
        highest = number;
      }
    }
    return highest;
}
int getmin(const std::vector<int>& numbers) {
  int lowest = numbers[0];
  for (int number : numbers) {
    if (number < lowest) {
      lowest = number;
    }
  }
  return lowest;
}
int main() {
  int count;
  std::cout << "How many numbers? ";
  std::cin >> count;
  if (count <= 0) {
    std::cout << "Please enter a positive number." << std::endl;
    return 0;
  }
  std::vector<int> numbers;
  for (int i = 1; i < count; ++i) {
    int val;
    std::cout << "Enter number " << i << ": ";
    std::cin >> val;
    numbers.push_back(val);
  }
  std::cout << "\nResults:" << std::endl;
  std::cout << "Sum: " << getsum(numbers) << std::endl;
  std::cout << "Average: " << getaverage(numbers) << std::endl;
  std::cout << "Maximum: " << getmax(numbers) << std::endl;
  std::cout << "Minimum: " << getmin(numbers) << std::endl;
  return 0;
}
