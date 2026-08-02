// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>
struct Student {
    std::string name;
    std::string id;
    std::vector<double> scores;
};
std::vector<Student> students;
void addStudent() {
  Student s;
  std::cout << "Student name: ";
  std::getline(std::cin >> std::ws, s.name);
  std::cout << "Student ID: ";
  std::cin >> s.id;
  int numScores;
  std::cout << "How many scores? ";
  std::cin >> numScores;
  for (int i = 0; i < numScores; ++i) {
    double score;
    std::cout << "Enter score " << i  << ": ";
    std::cin >> score;
    s.scores.push_back(score);
  }
  students.push_back(s);
  std::cout << "Student\"" << s.name << "\" added successfully.\n\n";
}
void displayAllStudent() {
  if (students.empty()) {
    std::cout << "No students available.\n\n";
    return;
  }
  std::cout << std::left << std::setw(15) << "Name" 
            << std::setw(12) << "ID" 
            << std::setw(18) << "Scores" 
            << std::setw(8) << "Average" << "\n";
  std::cout << std::string(53, '-') << "\n";
  for (const auto& s : students) {
    double sum = 0;
    std::string scoresStr = "";
    for (size_t i = 0; i < s.scores.size(); ++i) {
      sum += s.scores[i];
      scoresStr += std::to_string(static_cast<int>(s.scores[i]));
      if (i < s.scores.size() - 1) {
        scoresStr += ", ";
      }
    }
    double avg= s.scores.empty() ? 0.0 : sum / s.scores.size();
    std::cout << std::left << std::setw(15) << s.name
              << std::setw(12) << s.id
              << std::setw(18) << scoresStr
              << std::fixed << std::setprecision(2) << avg << "\n";
  }
  std::cout << "\n";
}
void calculateAverageScore() {
  std::string targetID;
  std::cout << "Enter student ID: ";
  std::cin >> targetID;
  for (const auto& s : students) {
    if (s.id == targetID) {
      if (s.scores.empty()) {
        std::cout << "No scores available for student " << s.name << ".\n\n";
        return;
      }
      double sum = 0;
      for (double score : s.scores) {
        sum += score;
      }
      double avg = sum / s.scores.size();
      std::cout << s.name << "'s average score: "
                << std::fixed << std::setprecision(2) << avg << "\n\n";
      return;
    }
  }
  std::cout << "Student ID not found.\n\n";
}
void showMenu() {
  std::cout << "==============================\n";
  std::cout << "  STUDENT RECORD SYSTEM MENU\n";
  std::cout << "==============================\n";
  std::cout << "1. Add Student\n";
  std::cout << "2. Display All Students\n";
  std::cout << "3. Calculate Average Score\n";
  std::cout << "4. Quit\n";
}
int main() {
  int choice;
  while (true) {
    showMenu();
    std::cout << "Enter your choice: ";
    if (!(std::cin >> choice)) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Invalid input. Please enter a number between 1 and 4.\n\n";
      continue;
    }
    if (choice == 1) {
      addStudent();
    } else if (choice == 2) {
      displayAllStudent();
    } else if (choice == 3) {
      calculateAverageScore();
    } else if (choice == 4) {
      std::cout << "Exiting the program. Goodbye!\n";
      break;
    } else {
      std::cout << "Invalid choice. Please select a number between 1 and 4.\n\n";
    }
  }
  return 0;
} 
