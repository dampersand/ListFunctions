#include <iostream>
#include "dlist.cpp"

using namespace std;

int main()
{
    Dlist<int> testList;
    testList.insertFront(1);
    testList.insertFront(2);
    testList.insertFront(3);
    testList.insertBack(8);
    testList.insertFront(4);

    cout << testList.removeFront() << endl;
    cout << "followed by: " << testList.removeFront() << endl;
    cout << "and then: " << testList.removeFront() << endl;
    cout << "from the back now: " << testList.removeBack() << endl;
    cout << "one more: " << testList.removeFront() << endl;
    cout << "returning empty?: " << testList.removeBack() << endl;
    return 0;
}
