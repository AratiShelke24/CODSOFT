#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

void showMenu() {
    cout << "\n==== TO-DO LIST MENU ====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

void addTask(vector<Task> &tasks) {
    string taskDesc;
    cout << "Enter task description: ";
    cin.ignore(); // to flush leftover newline
    getline(cin, taskDesc);
    tasks.push_back(Task(taskDesc));
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks in your list.\n";
        return;
    }

    cout << "\nYour To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "✓" : " ") << "] " << tasks[i].description << endl;
    }
}

void markCompleted(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int index;
    viewTasks(tasks);
    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int index;
    viewTasks(tasks);
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> taskList;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(taskList);
                break;
            case 2:
                viewTasks(taskList);
                break;
            case 3:
                markCompleted(taskList);
                break;
            case 4:
                removeTask(taskList);
                break;
            case 5:
                cout << "Exiting To-Do List. Have a productive day!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
