#include <iostream>
#include <queue>
#include <string>
using namespace std;

void printQueue(queue<string> queue) {
    bool choice;
    while (!queue.empty()) 
    {
        cout << "The next task to be completed is " << queue.front() << endl;
        cout << "Is this task completed enter 1 for Yes and 0 for No" << endl;
        cin >> choice;
        if (choice == 1) {
            queue.pop();
            cout << "Task Completed" << endl;
        }
        else
        cout << "Keep working to complete the task" << endl;
    }
    cout << "All tasks Completed Good job" << endl;
}

int main()
{
    queue<string> myQueue;
    int amountOfTasks;
    string task;
    cout << "Enter number of tasks you would like to complete" << endl;
    cin >>  amountOfTasks;
    for (int i = 0; i < amountOfTasks; i++) {
        cout << "Enter task " << i+1 << ": " << endl;
        cin >> task;
        myQueue.push(task);
    }
    cout << "You are ready to start completing tasks" << endl;

    cout << "The amount of tasks you have to complete today is " << myQueue.size() <<  endl;
    cout << "The first task is " << myQueue.front() << endl;
    cout << "The last task is " << myQueue.back() << endl;

    printQueue(myQueue);


    return 0;
}