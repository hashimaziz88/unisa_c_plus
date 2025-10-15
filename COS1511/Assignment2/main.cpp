#include<iostream>
#include<fstream>
#include<cstdlib>
int main()
{
    using namespace std;
    char inFileName;
    cout << "Enter the input file name:\n";
    cin >> inFileName;
    ofstream fout;
    fout.open("competition.txt", ios::app);
    if(fout.fail())
    {
        cout << "Input opening file failed.\n";
        exit(1);
    }
    fout << "We hope that you enjoyed the activity.\n"
    << "After you have completed the activity,\n"
    << "send your result to: The Activity Competition,\n"
    << "Betty Davis Street 99, Aucklad Park, 8989,\n"
 << "and stand a chance to win a hamper consisting\n"
 << "of colouring and activity books, colouring pencils\n"
 << "and pens.\n";
    fout.close();
    return 0;
}