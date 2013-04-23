#include <iostream>
#include "dlist.cpp"

using namespace std;

int main()
{
    Dlist<int> testList;
    testList.insertFront(1);
    testList.insertFront(2);
    testList.insertFront(3);
    testList.insertFront(4);
    testList.insertFront(5);
    testList.insertFront(6);
    testList.insertFront(7);

    //Output should be 76543... but it's backwards.  wat.
    cout << testList.removeFront() << testList.removeFront() << testList.removeFront() << testList.removeFront() << testList.removeFront();
    return 0;
}
