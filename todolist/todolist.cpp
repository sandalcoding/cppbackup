#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Task {
private:
    string name;
    int status; // 0: Pending, 1: Completed

public:
    // Constructor using initializer list
    Task(string n, int s) : name(n), status(s) {}

    void setName(string n) {
        name = n;
    }

    void setStatus(int s) {
        status = s;
    }

    string getName() const {
        return name;
    }

    int getStatus() const {
        return status;
    }

    // Overload the equality operator to compare tasks by name
    bool operator==(const Task& other) const {
        return name == other.name;
    }
};

class ToDoList {
private:
    vector<Task> tasks;
    string filename;

public:
    // Constructor with initializer list
    ToDoList(string fn) : filename(fn) {
        loadData();
    }

    // Save tasks to file
    void saveData() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const Task& task : tasks) {
                // Save task name and status as a number (0 or 1)
                file << task.getName() << " " << task.getStatus() << endl;
            }
            file.close();
        } else {
            cout << "Error: could not open file." << endl;
        }
    }

    // Load tasks from file
    void loadData() {
        ifstream file(filename);
        if (file.is_open()) {
            string task_name;
            int task_status;
            while (file >> task_name >> task_status) {
                // Read task name and status from file
                tasks.push_back(Task(task_name, task_status));
            }
            file.close();
        } else {
            cout << "Error: could not open file." << endl;
        }
    }

    // Add a new task
    void addTask(string task_name) {
        tasks.push_back(Task(task_name, 0));
        saveData();
    }

    // Remove a task by name
    void removeTask(string task_name) {
        auto it = remove_if(tasks.begin(), tasks.end(), [&](Task& task) {
            return task.getName() == task_name;
        });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            saveData();
        } else {
            cout << "Task not found." << endl;
        }
    }

    // Display all tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            for (const Task& task : tasks) {
                cout << "- " << task.getName() << " (" << (task.getStatus() == 1 ? "Completed" : "Pending") << ")" << endl;
            }
        }
    }

    // Mark a task as completed
    void markCompleted(string task_name) {
        auto it = find_if(tasks.begin(), tasks.end(), [&](Task& task) {
            return task.getName() == task_name;
        });
        if (it != tasks.end()) {
            it->setStatus(1);
            saveData();
        } else {
            cout << "Task not found." << endl;
        }
    }

    // Clear all completed tasks
    void clearCompletedTasks() {
        auto it = remove_if(tasks.begin(), tasks.end(), [](Task& task) {
            return task.getStatus() == 1;
        });
        tasks.erase(it, tasks.end());
        saveData();
    }
};

int main() {
    ToDoList toDoList("to-do_list.txt");
    int choice;

    while (true) {
        cout << "\n***TO-DO LIST***" << endl;
        cout << "1. Add a Task" << endl;
        cout << "2. Remove a Task" << endl;
        cout << "3. Display All Tasks" << endl;
        cout << "4. Mark a Task as Completed" << endl;
        cout << "5. Clear Completed Tasks" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string task_name;

        switch (choice) {
        case 1:
            cout << "Enter task name: ";
            getline(cin, task_name);
            toDoList.addTask(task_name);
            break;
        case 2:
            cout << "Enter task name to remove: ";
            getline(cin, task_name);
            toDoList.removeTask(task_name);
            break;
        case 3:
            toDoList.displayTasks();
            break;
        case 4:
            cout << "Enter task name to mark as completed: ";
            getline(cin, task_name);
            toDoList.markCompleted(task_name);
            break;
        case 5:
            toDoList.clearCompletedTasks();
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}