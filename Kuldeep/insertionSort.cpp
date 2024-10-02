#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float SGPA;

    void getData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter SGPA: ";
        cin >> SGPA;
    }

    void showData() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", SGPA: " << SGPA << endl;
    }
};

void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].rollNo > key.rollNo) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].showData();
    }
}

int main() {
    const int SIZE = 5;
    Student students[SIZE] = {
        {118, "Kuldeep", 9},
        {81, "Kunal", 6},
        {90, "om", 7},
        {12, "Ayush", 5},
        {50, "Amna", 8.7}
    };

    insertionSort(students, SIZE);

    cout << "\nSorted student data by Roll No:" << endl;
    printArray(students, SIZE);

    return 0;
}