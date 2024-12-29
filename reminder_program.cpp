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

// Function to delete a reminder (NEW FEATURE)
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

// Main function
int main() {
    int choice;
    while (true) {
        cout << "\n--- Social Media Reminder Program ---" << endl;
        cout << "1. Set Reminder" << endl;
        cout << "2. View Reminders" << endl;
        cout << "3. Delete Reminder" << endl;  // NEW OPTION
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the leftover newline character in the input buffer

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
                cout << "Exiting program..." << endl;
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
