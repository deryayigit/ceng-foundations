#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

#define N 125

class Student {
private:
    string* name;
    string* studentNo;
    float* midterm;
    float* secondExam;
    float* assignment;
    float* final;
    int* attendance;
    float* avrg;

    int studentCount; // Dynamically track the number of students

public:
    Student();
    ~Student();
    void readFromCSV(const string& filename);
    void average();
    void print(int a = -1, const string& fl = "");
};

Student::Student() {
    name = new string[N];
    studentNo = new string[N];
    midterm = new float[N];
    secondExam = new float[N];
    assignment = new float[N];
    final = new float[N];
    attendance = new int[N];
    avrg = new float[N];
    studentCount = 0; // Initially, number of students is zero
}

Student::~Student() {
    delete[] name;
    delete[] studentNo;
    delete[] midterm;
    delete[] secondExam;
    delete[] assignment;
    delete[] final;
    delete[] attendance;
    delete[] avrg;
}

void Student::readFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "File could not be opened! " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip the header line

    int i = 0;
    while (getline(file, line) && i < N) {
        stringstream ss(line);
        string temp;

        getline(ss, name[i], ',');
        getline(ss, studentNo[i], ',');
        getline(ss, temp, ',');
        midterm[i] = stof(temp);
        getline(ss, temp, ',');
        secondExam[i] = stof(temp);
        getline(ss, temp, ',');
        assignment[i] = stof(temp);
        getline(ss, temp, ',');
        final[i] = stof(temp);
        getline(ss, temp, '\n');
        attendance[i] = stoi(temp);

        i++;
    }

    studentCount = i; // Save the number of students read
    file.close();
}

void Student::average() {
    for (int i = 0; i < studentCount; i++) {
        avrg[i] = midterm[i] * 0.2 + secondExam[i] * 0.2 + assignment[i] * 0.2 + final[i] * 0.4;
    }
}

void Student::print(int a, const string& fl) {
    ofstream file;
    if (!fl.empty()) {
        file.open(fl);
        if (!file.is_open()) {
            cerr << "Output file could not be written!" << endl;
            return;
        }
    }

    ostream& output = fl.empty() ? cout : file;

    // Print formatted header
    output << left << setw(25) << "Student Name" << right << setw(10) << "Number"
           << right << setw(10) << "Average" << endl;
    output << string(45, '-') << endl;

    for (int i = 0; i < studentCount; i++) {
        if ((a == 0 && avrg[i] < 50) || (a == 1 && avrg[i] >= 50) || a == -1) {
            output << left << setw(25) << name[i]
                   << right << setw(10) << studentNo[i]
                   << right << setw(10) << fixed << setprecision(2) << avrg[i] << endl;
        }
    }

    if (file.is_open()) {
        file.close();
    }
}

int main() {
    Student student;
    
    // Check if the file path is correct
    student.readFromCSV("input.csv");

    // Get user input for which list to display
    int a;
    cout << "How would you like to view the student list?" << endl;
    cout << "0: Failed, 1: Passed, -1: All" << endl;
    cout << "Enter your choice: ";
    cin >> a;

    // Calculate averages
    student.average();

    // Print students to console or file
    student.print(a, "out");

    return 0;
}
