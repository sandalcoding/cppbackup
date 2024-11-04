#include <fstream>
#include <iostream>

using namespace std;

class Task {
private:
  string description, due_date;

public:
  Task() : description(""), due_date("") {}

  Task(string d, string dd) {
    description = d;
    due_date = dd;
  }

  void setDescription(string d) { description = d; }

  void setDate(string dd) { due_date = dd; }

  string getDescription() { return description; }

  string getDate() { return due_date; }
};

class TaskManager {
private:
  int max_size;

protected:
  Task *task_arr;
  int top;
  string filename;

public:
  TaskManager(int ms, string f) {
    max_size = ms;
    task_arr = new Task[max_size];
    top = -1;
    filename = f;
  }

  void addTask(string description, string due_date) {
    if (top >= max_size - 1) {
      cout << "Task Manager Stack Overflow" << endl;
    } else {
      task_arr[++top] = Task(description, due_date);
    }
  }

  void removeLastTask() {
    if (top < 0) {
      cout << "Task Manager Stack Underflow" << endl;
    } else {
      top--;
    }
  }

  void displayTasks() {
    cout << "List of Tasks:" << endl;

    for (int i = 0; i <= top; i++) {
      cout << "Description: " << task_arr[i].getDescription()
           << ", Due Date: " << task_arr[i].getDate() << endl;
    }
  }

  void saveTasks(string f) {
    ofstream file(f);

    if (file.is_open()) {
      for (int i = 0; i <= top; i++) {
        file << task_arr[i].getDescription() << "," << task_arr[i].getDate()
             << endl;
      }
    } else {
      cout << "Unable to open file for saving." << endl;
    }
  }

  void loadTasks(string f) {
    ifstream file(f);

    if (file.is_open()) {
      top = -1;
      string task_description, task_due_date;

      while (file >> task_description >> task_due_date) {
        addTask(task_description, task_due_date);
      }
    } else {
      cout << "Unable to open file for loading." << endl;
    }
  }
};

class AdvancedTaskManager : public TaskManager {
public:
  AdvancedTaskManager(int max_size, string filename)
      : TaskManager(max_size, filename) {}

  int countTasks() const { return top + 1; }
};

int main() {
  int max_stack_size, choice;
  string filename, task_description, task_due_date;
  cout << "Enter the maximum amount of tasks at a time: ";
  cin >> max_stack_size;
  cout << "Enter the name of the file to store the tasks: ";
  cin >> filename;

  AdvancedTaskManager task_manager(max_stack_size, filename);

  task_manager.loadTasks(filename);
  cout << "Successfully loaded tasks from file." << endl;

  while (true) {
    cout << "***Task Manager***" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Remove the last task" << endl;
    cout << "3. Display all tasks" << endl;
    cout << "4. Count the number of tasks" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cin.ignore();
      cout << "Enter the task description: ";
      getline(cin, task_description);
      cout << "Enter the due date (dd/mm/yyyy): ";
      cin >> task_due_date;
      task_manager.addTask(task_description, task_due_date);
      cout << "Task added successfully!" << endl;
      break;
    case 2:
      task_manager.removeLastTask();
      cout << "Last task removed successfully!" << endl;
      break;
    case 3:
      task_manager.displayTasks();
      break;
    case 4:
      cout << "Number of tasks: " << task_manager.countTasks() << endl;
      break;
    case 5:
      task_manager.saveTasks(filename);
      cout << "Successfully saved tasks to file." << endl;
      return 0;
    default:
      cout << "Invalid choice" << endl;
      break;
    }
  }

  return 0;
}