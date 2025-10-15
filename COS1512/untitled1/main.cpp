#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "how many students do you have? ";
    cin >> size;
    double* marks = new double[size];
    cout << "enter mark per student:\n";
    for (int i = 0; i < size; i++) {
        cout << "Student" << (i + 1) << " mark :";
        cin >> marks[i];
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    double average = sum / size;
    cout << " the average is " << average << endl;
    delete[] marks;
    return 0;
}