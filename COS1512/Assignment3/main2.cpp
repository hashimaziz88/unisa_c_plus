//
// Created by Hashim Aziz Muhammad on 2025/06/22.
//
//
// Created by Hashim Aziz Muhammad on 2025/06/22.
//
#include <iostream>
using namespace std;
int main()
{
    typedef int* IntArrayPtr;
    IntArrayPtr examMarks;
    int size, total, average;
    cout << " How many exam marks will be entered? ";
    cin >> size;
    examMarks = new int[size];
    cout << "Please enter " << size << " exam marks: " <<endl;
    for (int i = 0; i < size; i ++)
        cin >> examMarks[i];
    total = 0;
    for (int i = 0; i < size; i ++)
        total = total + examMarks[i] ;
    average = int(total/size);
    cout << endl << "The average exam mark is " << average << endl;
    delete [] examMarks;
    return 0;
}