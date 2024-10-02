#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float SGPA;

    void showData() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", SGPA: " << SGPA << endl;
    }
};

void radixSort(Student arr[], int n) {
    float maxSGPA = arr[0].SGPA;

    for (int i = 1; i < n; i++) {
        if (arr[i].SGPA > maxSGPA) {
            maxSGPA = arr[i].SGPA;
        }
    }

    for (int exp = 1; static_cast<int>(maxSGPA * 100) / exp > 0; exp *= 10) {
        Student* output = new Student[n];

        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            int digit = static_cast<int>(arr[i].SGPA * 100) / exp % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = static_cast<int>(arr[i].SGPA * 100) / exp % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        delete[] output;
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

    radixSort(students, SIZE);

    cout << "\nSorted student data by SGPA:" << endl;
    printArray(students, SIZE);

    return 0;
}