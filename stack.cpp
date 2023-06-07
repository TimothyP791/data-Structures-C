#include <iostream>
#include <stack>
using namespace std;

void printStackElements(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
}

int main()
{
    //empty, size, push, pop, top
    stack<int>numbersStack;
    numbersStack.push(5);
    numbersStack.push(9);
    numbersStack.push(7);
    numbersStack.pop();

    printStackElements(numbersStack);
    /*if(numbersStack.empty()) {
        cout << "Stack is empty" << endl;
    
    }
    else
        cout << "Stack is not empty" << endl;
    cout << "Stack size is " << numbersStack.size() << endl;*/


    return 0;
}