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

void shellSort(Student arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].name > temp.name; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
        {17, "Kuldeep", 7.6},
        {14, "Kunal", 7.4},
        {50, "Om", 9.0},
        {17, "Don", 7.0},
        {7, "Aman", 8.7}
    };

    shellSort(students, SIZE);

    cout << "\nSorted student data alphabetically:" << endl;
    printArray(students, SIZE);

    return 0;
}