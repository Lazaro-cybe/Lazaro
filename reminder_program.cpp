#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure for reminders
struct Reminder {
    string task;     // Description of the task
    string date;     // Date for the reminder
    string time;     // Time for the reminder
};

vector<Reminder> reminders;  // Vector to store reminders

// Function to set a reminder
void setReminder() {
    Reminder newReminder;
    
    // Get task details from user
    cout << "Enter task (e.g., Post on Instagram, Check Facebook): ";
    getline(cin, newReminder.task);  // Get the task

    cout << "Enter the date for the reminder (e.g., 2024-12-15): ";
    getline(cin, newReminder.date);  // Get the date

    cout << "Enter the time for the reminder (e.g., 14:30): ";
    getline(cin, newReminder.time);  // Get the time

    // Store the new reminder in the reminders vector
    reminders.push_back(newReminder);

    cout << "Reminder set successfully!" << endl;
}

// Function to view all reminders
void viewReminders() {
    if (reminders.empty()) {
        cout << "No reminders set." << endl;
        return;
    }

    cout << "Your reminders are:" << endl;
    for (size_t i = 0; i < reminders.size(); ++i) {
        cout << i + 1 << ". Task: " << reminders[i].task 
             << ", Date: " << reminders[i].date 
             << ", Time: " << reminders[i].time << endl;
    }
}

// Function to delete a reminder
void deleteReminder() {
    if (reminders.empty()) {
        cout << "No reminders to delete." << endl;
        return;
    }

    viewReminders();  // Show current reminders
    int index;
    cout << "Enter the number of the reminder to delete: ";
    cin >> index;

    if (index < 1 || index > reminders.size()) {
        cout << "Invalid number. No reminder deleted." << endl;
    } else {
        reminders.erase(reminders.begin() + (index - 1));  // Remove the selected reminder
        cout << "Reminder deleted successfully!" << endl;
    }
}

// Function to search for reminders by task name
void searchReminder() {
    if (reminders.empty()) {
        cout << "No reminders to search." << endl;
        return;
    }

    string keyword;
    cout << "Enter a keyword to search for in task names: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (size_t i = 0; i < reminders.size(); ++i) {
        if (reminders[i].task.find(keyword) != string::npos) {
            cout << "Found: Task: " << reminders[i].task 
                 << ", Date: " << reminders[i].date 
                 << ", Time: " << reminders[i].time << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No reminders matched your search." << endl;
    }
}

// Function to edit a reminder (NEW FEATURE)
void editReminder() {
    if (reminders.empty()) {
        cout << "No reminders to edit." << endl;
        return;
    }

    viewReminders();  // Show current reminders
    int index;
    cout << "Enter the number of the reminder to edit: ";
    cin >> index;

    if (index < 1 || index > reminders.size()) {
        cout << "Invalid number. No reminder edited." << endl;
        return;
    }

    Reminder &reminderToEdit = reminders[index - 1];
    cout << "Editing Reminder: Task: " << reminderToEdit.task 
         << ", Date: " << reminderToEdit.date 
         << ", Time: " << reminderToEdit.time << endl;

    cout << "Enter new task (leave blank to keep unchanged): ";
    cin.ignore();
    string newTask;
    getline(cin, newTask);
    if (!newTask.empty()) reminderToEdit.task = newTask;

    cout << "Enter new date (leave blank to keep unchanged): ";
    string newDate;
    getline(cin, newDate);
    if (!newDate.empty()) reminderToEdit.date = newDate;

    cout << "Enter new time (leave blank to keep unchanged): ";
    string newTime;
    getline(cin, newTime);
    if (!newTime.empty()) reminderToEdit.time = newTime;

    cout << "Reminder updated successfully!" << endl;
}

// Main function
int main() {
    int choice;
    while (true) {
        cout << "\n--- Social Media Reminder Program ---" << endl;
        cout << "1. Set Reminder" << endl;
        cout << "2. View Reminders" << endl;
        cout << "3. Delete Reminder" << endl;
        cout << "4. Search Reminder" << endl;
        cout << "5. Edit Reminder" << endl;  // NEW OPTION
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                setReminder();  // Call function to set a reminder
                break;
            case 2:
                viewReminders();  // Call function to view all reminders
                break;
            case 3:
                deleteReminder();  // Call function to delete a reminder
                break;
            case 4:
                searchReminder();  // Call function to search reminders
                break;
            case 5:
                editReminder();  // Call function to edit a reminder
                break;
            case 6:
                cout << "Exiting program..." << endl;
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
