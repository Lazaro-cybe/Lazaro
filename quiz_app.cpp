#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Question {
    string question;
    vector<string> options;
    int correctAnswer;
};

class Quiz {
private:
    vector<Question> questions;
    string quizFile;
    int score;

public:
    Quiz(string filename) : quizFile(filename), score(0) {}

    void createQuiz() {
        int numQuestions;
        cout << "Enter the number of questions: ";
        cin >> numQuestions;
        cin.ignore(); // Clear the input buffer

        for (int i = 0; i < numQuestions; i++) {
            Question q;
            cout << "\nEnter question " << i + 1 << ": ";
            getline(cin, q.question);

            cout << "Enter 4 options:\n";
            for (int j = 0; j < 4; j++) {
                string option;
                cout << "Option " << j + 1 << ": ";
                getline(cin, option);
                q.options.push_back(option);
            }

            cout << "Enter the number of the correct option (1-4): ";
            cin >> q.correctAnswer;
            cin.ignore(); // Clear the input buffer

            questions.push_back(q);
        }

        saveQuiz();
        cout << "Quiz saved successfully!\n";
    }

    void saveQuiz() {
        ofstream file(quizFile);
        if (!file) {
            cerr << "Error: Unable to save quiz to file.\n";
            return;
        }

        for (const auto &q : questions) {
            file << q.question << endl;
            for (const auto &option : q.options) {
                file << option << endl;
            }
            file << q.correctAnswer << endl;
        }
        file.close();
    }

    void loadQuiz() {
        ifstream file(quizFile);
        if (!file) {
            cerr << "Error: Unable to load quiz from file.\n";
            return;
        }

        questions.clear();
        string line;
        while (getline(file, line)) {
            Question q;
            q.question = line;

            for (int i = 0; i < 4; i++) {
                getline(file, line);
                q.options.push_back(line);
            }

            file >> q.correctAnswer;
            file.ignore(); // Clear the input buffer

            questions.push_back(q);
        }
        file.close();
    }

    void takeQuiz() {
        loadQuiz();
        if (questions.empty()) {
            cout << "No questions available. Please create a quiz first.\n";
            return;
        }

        score = 0;
        for (size_t i = 0; i < questions.size(); i++) {
            cout << "\nQuestion " << i + 1 << ": " << questions[i].question << endl;
            for (size_t j = 0; j < questions[i].options.size(); j++) {
                cout << j + 1 << ". " << questions[i].options[j] << endl;
            }

            int answer;
            cout << "Your answer (1-4): ";
            cin >> answer;

            if (answer == questions[i].correctAnswer) {
                score++;
            }
        }

        cout << "\nQuiz completed! Your score: " << score << " out of " << questions.size() << "\n";
    }

    void viewResults() {
        cout << "Last quiz score: " << score << "\n";
    }
};

int main() {
    Quiz quiz("quiz_data.txt");
    int choice;

    do {
        cout << "\nQuiz Application\n";
        cout << "1. Create Quiz\n";
        cout << "2. Take Quiz\n";
        cout << "3. View Results\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                quiz.createQuiz();
                break;
            case 2:
                quiz.takeQuiz();
                break;
            case 3:
                quiz.viewResults();
                break;
            case 4:
                cout << "Exiting application. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
