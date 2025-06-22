#include <iostream>
using namespace std;
// overloaded function for tuition fees - first time modules only
// Pre: first time enrolled modules + fees
// Post: returned value is tuition fees
double calcFees (int nrFirstTime, double feeFirst);
// overloaded function for tuition fees - first time and repeated modules
// Pre: first time + repeat modules + respective fees
//Post: returned value is tuition fees
double calcFees (int nrFirstTime, const double feeFirst,
 int nrRepeat, const double feeRepeat);
const double feeFirst = 1050.00;
const double feeRepeat = 900.00;

//overloaded function for first time modules only
double calcFees (int nrFirstTime, const double feeFirst)
{
    return (feeFirst * nrFirstTime);
}
//overloaded function for first time modules and modules that are repeated
double calcFees (int nrFirstTime, const double feeFirst, int nrRepeat,
const double feeRepeat)
{
    return (feeFirst * nrFirstTime + feeRepeat * nrRepeat);
}

int main()
{
    char answer;
    int nrFirstTime = 0, nrRepeat = 0;
    double tuitionAmount = 0.00;
    cout << "Does the student repeat any modules? y or n: " << endl;
    cin >> answer;
    if ((answer == 'y') || (answer == 'Y'))
    {
        cout << "How many modules will be repeated? : ";
        cin >> nrRepeat;
    }
    cout << "How many modules are first time modules? : ";
    cin >> nrFirstTime;
    if (nrRepeat == 0)
        tuitionAmount = calcFees (nrFirstTime, feeFirst);
    else
        tuitionAmount = calcFees(nrFirstTime,feeFirst,nrRepeat, feeRepeat);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << endl << "The total tuition fee for this student is : R"
    << tuitionAmount << endl;
    return 0;
}