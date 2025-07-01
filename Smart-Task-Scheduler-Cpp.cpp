#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

const string TASKS_FILE = "tasks.txt";

struct Task {
    int id;
    string description;
    string dueDate;
    int priority;
    bool completed;
};

vector<Task> tasks;

time_t parseDate(const string& dateStr) {
    tm tm = {};
    istringstream ss(dateStr);
    ss >> get_time(&tm, "%Y-%m-%d");
    return mktime(&tm);
}

bool compareTasks(const Task& a, const Task& b) {
    if (a.priority != b.priority)
        return a.priority < b.priority;
    return parseDate(a.dueDate) < parseDate(b.dueDate);
}

void loadTasks() {
    ifstream file(TASKS_FILE);
    if (!file) return;

    tasks.clear();
    Task task;
    while (file >> task.id >> task.dueDate >> task.priority >> task.completed) {
        file.ignore();
        getline(file, task.description);
        tasks.push_back(task);
    }
}

void saveTasks() {
    ofstream file(TASKS_FILE);
    for (const auto& task : tasks) {
        file << task.id << " "
            << task.dueDate << " "
            << task.priority << " "
            << task.completed << " "
            << task.description << "\n";
    }
}

void addTask() {
    Task newTask;
    newTask.id = tasks.empty() ? 1 : tasks.back().id + 1;

    cout << "\nAdd new task:\n";
    cout << "Task description: ";
    cin.ignore();
    getline(cin, newTask.description);

    cout << "Due date (YYYY-MM-DD): ";
    cin >> newTask.dueDate;

    cout << "Priority (1-High, 2-Medium, 3-Low): ";
    cin >> newTask.priority;

    newTask.completed = false;
    tasks.push_back(newTask);
    saveTasks();

    cout << "Task added successfully!\n";
}

void displayTasks() {
    if (tasks.empty()) {
        cout << "\nNo tasks found!\n";
        return;
    }

    sort(tasks.begin(), tasks.end(), compareTasks);

    cout << "\nSmart Task Scheduler:\n";
    cout << "------------------------------------------------------------\n";
    cout << "| ID | Description        | Due Date  | Priority | Status    |\n";
    cout << "------------------------------------------------------------\n";

    time_t now = time(nullptr);
    for (const auto& task : tasks) {
        time_t dueDate = parseDate(task.dueDate);
        double diff = difftime(dueDate, now) / (60 * 60 * 24);

        cout << "| " << setw(2) << task.id << " | "
            << setw(15) << (task.description.length() > 15 ?
                task.description.substr(0, 12) + "..." :
                task.description)
            << " | " << task.dueDate << " | ";

        if (task.priority == 1) cout << "High     | ";
        else if (task.priority == 2) cout << "Medium   | ";
        else cout << "Low      | ";

        if (task.completed) {
            cout << "Completed |";
        }
        else if (diff < 0) {
            cout << "Late      |";
        }
        else if (diff < 3) {
            cout << "Urgent    |";
        }
        else {
            cout << "Pending   |";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------\n";
}

void markTaskCompleted() {
    int id;
    cout << "\nEnter task ID to mark as completed: ";
    cin >> id;

    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            saveTasks();
            cout << "Task status updated!\n";
            return;
        }
    }
    cout << "Task not found!\n";
}

void removeTask() {
    int id;
    cout << "\nEnter task ID to delete: ";
    cin >> id;

    auto it = remove_if(tasks.begin(), tasks.end(),
        [id](const Task& t) { return t.id == id; });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        saveTasks();
        cout << "Task deleted successfully!\n";
    }
    else {
        cout << "Task not found!\n";
    }
}

void showUpcomingTasks() {
    time_t now = time(nullptr);
    vector<Task> upcoming;

    for (const auto& task : tasks) {
        time_t dueDate = parseDate(task.dueDate);
        double diff = difftime(dueDate, now) / (60 * 60 * 24);
        if (!task.completed && diff >= 0 && diff <= 7) {
            upcoming.push_back(task);
        }
    }

    if (upcoming.empty()) {
        cout << "\nNo upcoming tasks!\n";
        return;
    }

    sort(upcoming.begin(), upcoming.end(), compareTasks);

    cout << "\nUpcoming tasks this week:\n";
    cout << "----------------------------------------\n";
    for (const auto& task : upcoming) {
        cout << "• " << task.description << " (" << task.dueDate << ")\n";
    }
    cout << "----------------------------------------\n";
}

void showMenu() {
    cout << "\n\nSmart Task Scheduler\n";
    cout << "1. Add new task\n";
    cout << "2. Show all tasks\n";
    cout << "3. Show upcoming tasks\n";
    cout << "4. Mark task as completed\n";
    cout << "5. Delete task\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    loadTasks();

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: addTask(); break;
        case 2: displayTasks(); break;
        case 3: showUpcomingTasks(); break;
        case 4: markTaskCompleted(); break;
        case 5: removeTask(); break;
        case 6: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}