#include <iostream> // for screen/keyboard i/o
#include <fstream>  // for file
#include <cstdlib>  // for exit
using namespace std;

// Precondition:
// The input file is a text file.
// The input file has been opened.
//
// Postcondition:
// The output file is a text file.
// The output file has been opened.
// Output file will be similar to input file except for all numbers 0 to 7
// that will be replaced with the character as specified in the question

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
            index = int(ch - '0'); // This gives us the numeric version
                                   // (i.e. 0 – 7 of the characters '0' - '7').
            outfile << convert[index];
        }
        else
            outfile << ch;

        infile.get(ch);
    } // end while !infile.eof

    infile.close();
    outfile.close();

    // This part was not required, but it is always a good idea to read the file
    // that was created to make sure it is correct.
    // We first read the original input file, and display its content

    indisplay.open(inName.c_str());
    if (indisplay.fail())
    {
        cout << "Cannot open file " << inName << " Aborting!" << endl;
        exit(1);
    }

    cout << endl << "The contents of the input file is : " << endl << endl;
    checkFile(indisplay);
    indisplay.close();

    // Now we read the file that was created as an output file and display the
    // content

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