// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
#include <cmath>
#include <iomanip>
double add(double a, double b) {
    return a + b;
}
double subtract(double a, double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
void divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Cannot divide by zero.\n\n";
    } else {
        std::cout << "Result: " << a <<" / " << b << " = " 
                  << std::fixed << std::setprecision(2) << (a / b) << "\n\n";
    }
}
void modulus(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Cannot perform modulus by zero.\n\n";
    } else {
        std::cout << "Result: " << a <<" % " << b << " = " 
                  << std::fmod(a, b) << "\n\n";
    }
}
double power(double a, double b) {
    return std::pow(a, b);
} 
void showMenu() {
    std::cout << "==============================\n";
    std::cout << "  SIMPLE CALCULATOR MENU\n";
    std::cout << "==============================\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Modulus\n";
    std::cout << "6. Power\n";
    std::cout << "7. Quit\n";
}
void getNumbers(double& a, double& b) {
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
}
int main() {
    int choice;
    while(true){
        showMenu();
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n\n";
            continue;
        }
        if (choice == 7) {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        }
        if (choice >= 1 && choice <= 6) {
            double a, b;
            getNumbers(a, b);
            if (choice == 1) {
                std::cout << "Result: " << a << " + " << b << " = " 
                          << std::fixed << std::setprecision(2) << add(a, b) << "\n\n";
            } else if (choice == 2) {
                std::cout << "Result: " << a << " - " << b << " = " 
                          << std::fixed << std::setprecision(2) << subtract(a, b) << "\n\n";
            } else if (choice == 3) {
                std::cout << "Result: " << a << " * " << b << " = " 
                          << std::fixed << std::setprecision(2) << multiply(a, b) << "\n\n";
            } else if (choice == 4) {
                divide(a, b);
            } else if (choice == 5) {
                modulus(a, b);
            } else if (choice == 6) {
                std::cout << "Result: " << a <<" ^ " << b <<" = "
                          << std::fixed << std::setprecision(2) 
                          << power(a, b) << "\n\n";
            }
        } else {
            std::cout << "Invalid choice. Please select a number between 1 and 7.\n\n";
        }
    }
    return 0;
} 
