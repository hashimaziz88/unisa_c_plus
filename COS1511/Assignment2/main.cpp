#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getScore() {
    int score;
    do {
        cout << "Enter a test score: ";
        cin >> score;
        if (score < 0 || score > 100) {
            cout << "Invalid score. Please enter a score between 0 and 100." << endl;
            }
    } while (score < 0 || score > 100);
    return score;
}
int findLowest(const vector<int>& scores) {
    return *min_element(scores.begin(), scores.end());
}
float calcAverage(const vector<int>& scores) {
    int lowest_score = findLowest(scores);
    int total = 0;
    for (int score : scores) {
        if (score != lowest_score) {
            total += score;
        }
    }
    return static_cast<float>(total) / 4;
}
void displayOutput(float average) {
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "After dropping the lowest test score, the test average is " <<
    fixed << average << endl;
}
int main() {
    vector<int> scores;
    for (int i = 0; i < 5; ++i) {
        int score = getScore();
        scores.push_back(score);
    }
    float average = calcAverage(scores);
    displayOutput(average);
    return 0;
}