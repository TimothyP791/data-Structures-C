#include <iostream>
using namespace std;

int main() 
{
    // total, average, inTwoYears
    int arraySize = 10;
    float monthsArray[arraySize]; //= {100, 220, 300, 0, 200, 250};
    

    float total = 0;
    for (int i = 0; i < arraySize; i++){
        cout << "Enter amount for month " << i+1 << ":" << endl;
        cin >> monthsArray[i];
        total += monthsArray[i];
    } 

    float average = total/ arraySize;
    float inTwoYears = average * 24;

    cout << "total = " << total << endl;
    cout << "average = " << average << endl;
    cout << "inTwoYears = " << inTwoYears << endl; 



    return 0;
}