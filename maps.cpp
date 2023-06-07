#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include<list>

using namespace std;


int main()
{
    //complex data type example
    map<string,list<string>> saiyandex;

    list<string> vegetaAttacks {"Big Bang Attack", "Galick Gun", "Final Flash"};
    list<string> gokuAttacks {"Kamehameha", "Spirit Bomb"};
    list<string> brolyAttacks {"Eraser Cannon", "Gigantic Meteor"};
    
    saiyandex.insert(pair<string, list<string>>("Vegeta", vegetaAttacks));
    saiyandex.insert(pair<string, list<string>>("Goku", gokuAttacks));
    saiyandex.insert(pair<string, list<string>>("Broly", brolyAttacks));
    
    for (auto pair : saiyandex) {
        cout << pair.first << " - ";
        for (auto attack : pair.second) {
            cout << attack << ", ";
        }
        cout << endl;
    }
    
    
    
    
    
    
    //Basic data type example
    /*map<string,string> myDictionary;
    unordered_map<string,string> myDictionary;
    myDictionary.insert(pair<string,string>("strawberry", "die Erdbeere"));
    myDictionary.insert(pair<string,string>("orange", "die Orange, die Apfelsine"));
    myDictionary.insert(pair<string,string>("apple", "der Apfel"));
    myDictionary.insert(pair<string,string>("banana", "die Banane"));
    
    
    myDictionary["strawberry"] = "Die erdbeere";
    //myDictionary.clear(); // clears entire map
    myDictionary.erase("orange");
    cout << myDictionary.size() << endl;


    for (auto pair : myDictionary) {
        cout << pair.first << " - " << pair.second << endl;
    }*/
    
    
    return 0;
}