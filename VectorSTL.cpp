#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> numbers;
    //numbers.push_back(0);       //how to insert into a vector
    
    for (int i = 1; i <= 10; i++){
        numbers.push_back(i);
    }
   
    //Insert, Erase, and Pop_Back functions. 
    numbers.insert(numbers.begin() + 5, 88);
    numbers.erase(numbers.begin() + 4);
    numbers.pop_back();
   
   for (auto n : numbers)
   cout << n << endl;
   
   
   
   
   
   //Built in Vector functions
    /*cout << "Size: " << numbers.size() << endl;
    cout << "Max Size: " << numbers.max_size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    numbers.resize(5);
    cout << "Size: " << numbers.size() << endl;
    if (numbers.empty()) {
        cout << "Vector is emty\n";
    }
    else
        cout << "Vector is not empty\n";
    cout << "Element[0] is: " << numbers[0] << endl;
    cout << "Elemant at(0) is: " << numbers.at(0) << endl;
    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;
    numbers.clear();
    cout << "Size: " << numbers.size() << endl;*/
    





   //cbegin and cend constant iterators
   /*for (auto it=numbers.cbegin(); it!=numbers.cend(); it++) { 
       
       cout << *it << endl; // value of element
   }*/
      
    // Arithmetic addition using iterators to traverse vector
    /*auto it = numbers.begin();
    cout << *(it + 5);*/
 
    //print using iterators
    /*for (auto it=numbers.begin(); it!=numbers.end(); it++) { 
       // cout << it << endl;  causes error cannot print iterator
       cout << *it << endl; // value of element
       cout << &it << endl; // address of iterator 
       cout << &(*it) << endl; // address of the element
    }*/

    //print using without iterators
    /*for (int number : numbers) 
    cout << number << endl;*/

    return 0;
}