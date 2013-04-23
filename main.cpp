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

    cout << testList.removeFront() << endl;
    cout << "followed by: " << testList.removeFront() << endl;
    cout << "and then: " << testList.removeFront();
    return 0;
}
