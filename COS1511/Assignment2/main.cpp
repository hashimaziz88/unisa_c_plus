#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


void checkFile(ifstream& infile)
{
    char ch;
    infile.get(ch);
    while (!infile.eof())
    {
        cout << ch;
        infile.get(ch);
    }
}

int main()
{
    char convert[8] = {'s','g','o','y','v','n','f','j'};
    ifstream infile;
    ofstream outfile;
    ifstream indisplay;
    ifstream outdisplay;
    string inName, outName;

    cout << endl
         << "Enter the input file name. "
         << endl;
    cin >> inName;

    infile.open(inName.c_str());
    if (infile.fail())
    {
        cout << "Cannot open file " << inName << " Aborting!" << endl;
        exit(1);
    }

    cout << endl << "Enter the output file name. " << endl
         << "WARNING: ANY EXISTING FILE WITH THIS NAME WILL"
         << " BE ERASED." << endl;
    cin >> outName;

    outfile.open(outName.c_str());
    if (outfile.fail())
    {
        cout << "Cannot open file " << outName << " Aborting!" << endl;
        exit(1);
    }

    cout << endl;
    char ch;
    int index = 0;

    infile.get(ch);
    while (!infile.eof())
    {
        if (ch >= '0' && ch < '8')
        {
            index = int(ch - '0');
            outfile << convert[index];
        }
        else
            outfile << ch;

        infile.get(ch);
    }

    infile.close();
    outfile.close();


    indisplay.open(inName.c_str());
    if (indisplay.fail())
    {
        cout << "Cannot open file " << inName << " Aborting!" << endl;
        exit(1);
    }

    cout << endl << "The contents of the input file is : " << endl << endl;
    checkFile(indisplay);
    indisplay.close();

    outdisplay.open(outName.c_str());
    if (outdisplay.fail())
    {
        cout << "Cannot open file " << outName << " Aborting!" << endl;
        exit(1);
    }

    cout << endl << endl << "The contents of the output file is : "
         << endl << endl;
    checkFile(outdisplay);
    outdisplay.close();

    cout << endl;
    return 0;
}