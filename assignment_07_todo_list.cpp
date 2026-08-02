// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> tasks;
void addtask() {
  std::string task;
  std::cout << "Enter task: ";
  std::getline(std::cin >> std::ws, task);
  tasks.push_back(task);
  std::cout << "Task added:\""<< task <<"\"\n\n";
}
void viewtasks() {
  if (tasks.empty()) {
    std::cout << "No tasks available.\n\n";
    return;
  }
  std::cout << "Your Tasks:\n";
  for (size_t i = 0; i < tasks.size(); ++i) {
    std::cout << (i + 1) << ". " << tasks[i] << "\n";
  }
  std::cout << "\n";
}
void removetask() {
  if (tasks.empty()) {
    std::cout << "No tasks to remove.\n\n";
    return;
  }
  int taskNum;
  std::cout << "Enter task number to remove: ";
  if (!(std::cin >> taskNum)) {
    std::cin.clear(); 
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid input. Please enter a valid task number.\n\n";
    return;
  }
  if (taskNum >= 1 && taskNum <= static_cast<int>(tasks.size())) {
    std::string removed = tasks[taskNum - 1];
    tasks.erase(tasks.begin() + (taskNum - 1));
    std::cout << "Task \"" << removed << "\" removed.\n\n";
  } else {
    std::cout << "Invalid task number.\n\n";
  }
}
void showmenu() {
  std::cout << "=======================\n";
  std::cout << "  TO-DO LIST MENU\n";
  std::cout << "=======================\n";
  std::cout << "1. Add Task\n";
  std::cout << "2. View Tasks\n";
  std::cout << "3. Delete Task\n";
  std::cout << "4. Quit\n";
}
int main() {
  int choice;
  while (true) {
    showmenu();
    std::cout << "Enter your choice: ";
    if (!(std::cin >> choice)) {
      std::cin.clear(); 
      std::cin.ignore(10000, '\n');
      std::cout << "Invalid input. Please enter a number between 1 and 4.\n\n";
      continue;
    }
    if (choice == 1) {
      addtask();
    } else if (choice == 2) {
      viewtasks();
    } else if (choice == 3) {
      removetask();
    } else if (choice == 4) {
      std::cout << "Exiting the program. Goodbye!\n";
      break;
    } else {
      std::cout << "Invalid choice. Please select a number between 1 and 4.\n\n";
    }
  }
  return 0;
} 

