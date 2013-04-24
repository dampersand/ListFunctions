#include <iostream>
#include "dlist.cpp"

using namespace std;

int main()
{
    Dlist<int> testList;

    testList.insertFront(1);
    testList.insertFront(3);
    testList.insertFront(5);
    testList.insertFront(7);
    testList.insertFront(9);

    Dlist<int> copyList(testList);

    for(int i=0; i < 7; i++)
        cout << testList.removeFront() << endl;

    for (int i=0; i < 7; i++)
        cout << copyList.removeFront() << endl;

    return 0;
}
