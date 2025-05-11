#include <iostream>
#include <vector>
#include <string>
using namespace std;
void getData(int &height, int &width, int &length) {
    cout << "Enter the height of the room: ";
    cin >> height;
    cout << "Enter the width of the room: ";
    cin >> width;
    cout << "Enter the length of the room: ";
    cin >> length;
}
int calculateVolume(int theHeight, int theWidth, int theLength) {
    return theHeight * theWidth * theLength;
}
void displayOutput(int height, int width, int length, int volume) {
    cout << "The volume of a room with height " << height << ", width " <<
    width << ", and length " << length << " is " << volume << ".\n";
    // Determine the size of the room
    string size;
    if (volume < 100)
        size = "Small";
    else if (volume >= 100 && volume <= 500)
        size = "Medium";
    else
        size = "Large";
    cout << "Size: " << size << endl;
}
int main() {
    for (int i = 0; i < 5; ++i) {
        int theHeight, theWidth, theLength;
        getData(theHeight, theWidth, theLength);
        int volume = calculateVolume(theHeight, theWidth, theLength);
        displayOutput(theHeight, theWidth, theLength, volume);
    }
    return 0;
}