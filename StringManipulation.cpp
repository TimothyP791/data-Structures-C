// StringManipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line, time1, time2, meridiem1, meridiem2;
    int hour1, hour2, minute1, minute2;
    int index = 0, totMin = 0;
    getline(cin, line);
    
    while (index < line.length()) {         //Separate time1 and time2 using - breakpoint
        time1 += line[index];
        if (line[index] == '-') {
            line.erase(0, index + 2);       //Erase string up to first time to later store in time2
            break;
        }
        index++;
    }
    time1 = time1.erase(time1.find('-') - 1, time1.find('-'));
    time2 = line;
    for (int i = 0; i < time1.size(); i++) {
        if (time1[i] == ':') {                                                      //Separate out the hour time
            hour1 = stoi(time1.substr(0, i));
        }
        if (time1[i] == ' ') {                  
            minute1 = stoi(time1.substr(time1.find(':') + 1, i));                   //Separate out the minute time
            time1.erase(0, i + 1);
            meridiem1 = time1;                                                      //Separate out AM and PM
        }
    }
    
    for (int j = 0; j < time2.size(); j++) {                                        //Repeat for time 2
        if (time2[j] == ':') {
            hour2 = stoi(time2.substr(0, j));
        }
        if (time2[j] == ' ') {
            minute2 = stoi(time2.substr(time2.find(':') + 1, j));
            time2.erase(0, j + 1);
            meridiem2 = time2;
        }
    }
    if (meridiem1 == "PM" && meridiem2 == "AM") { // convert to 24 hour clock for calcuation
        hour1 = 12 - hour1;
        totMin = ((hour1 + hour2) * 60 + (minute2 - minute1));
    }
    if (meridiem1 == "AM" && meridiem2 == "AM") {
        totMin = ((hour2 - hour1) * 60 + (minute2 - minute1));
    }
    if (meridiem1 == "PM" && meridiem2 == "PM") {
        totMin = ((hour2 - hour1) * 60 + (minute2 - minute1));
    }
    if (meridiem1 == "AM" && meridiem2 == "PM") {
        hour2 += 12;
        totMin = ((hour2 - hour1) * 60 + (minute2 - minute1));
    }
    cout  << totMin;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
