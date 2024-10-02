#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    int empID;
    string empName;
    float empSalary;

    void showData() const {
        cout << "EMP-ID: " << empID << ", EMP-Name: " << empName << ", EMP-Salary: " << empSalary << endl;
    }
};

void swap(Employee &a, Employee &b) {
    Employee temp = a;
    a = b;
    b = temp;
}

int partition(Employee arr[], int low, int high) {
    int pivot = arr[high].empID; // Pivot is the last element
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j].empID < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return (i + 1);
}

void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].showData();
    }
}

int main() {
    const int SIZE = 7;
    Employee employees[SIZE] = {
        {72, "Kuldeep", 70000},
        {70, "Kunal", 64000},
        {56, "piyush", 75000},
        {91, "Manish", 66000},
        {20, "Om", 40000},
        {52, "Aman", 10000},
        {82, "Ashish", 20000}
    };

    quickSort(employees, 0, SIZE - 1);

    cout << "\nSorted employee data by EMP-ID:" << endl;
    printArray(employees, SIZE);

    return 0;
}