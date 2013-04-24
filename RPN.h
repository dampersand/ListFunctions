#ifndef RPN_H_INCLUDED
#define RPN_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "dlist.h"

using namespace std;

void RPN()
{
    Dlist<float> RPNStack;
    char userInc;
    int userIn;
    float firstNum, secNum;
    int operandCounter = 0; //created because the required exception schema is very weak
    cout << string( 100, '\n' ); //clearscreen

    cout << "Welcome to the Reverse Polish Notation Calculator." << endl << endl;
    cout << "[0-9] Place this number onto the top of the stack\n[+] Add the top two numbers and place the result back on top\n";
    cout << "[-] Subtract the top number from the second and place the result back on top\n[*] Multiply the top two numbers and place the result back on top\n";
    cout << "[/] Divide the second number in the stack by the first number and place the result back on top\n";
    cout << "[n] Make the top number on the stack negative\n[d] Duplicate the top number of the stack; push the duplicate onto the front\n";
    cout << "[r] Swap the top two numbers on the stack\n[p] Prints the top number on the stack\n[c] Clears (empties) the stack\n";
    cout << "[a] Print all the numbers on the stack\n[q] Return to the main menu\n\n\nPlease enter your input.\n\n>";
    cin.sync();
    cin >> userInc;
    userIn = userInc;

    while (userIn!= 113 && userIn!= 81)
        {
            switch(userIn)
            {
                case 48: //hey, did anyone ever notice how the ascii code for 0 is 48?  stupid, huh?
                case 49: // and 1 is 49?  derp.
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                case 56:
                case 57:
                    RPNStack.insertFront(userIn-48);
                    cout << endl << endl << userIn-48 << " has been added to the front of the stack\n" << endl;
                    operandCounter += 1;
                    break;
                case 43: //addition
                    if (operandCounter < 2)
                        cout << "There are not enough operands in the stack to perform this function.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        secNum = RPNStack.removeFront();
                        cout << "Adding " << firstNum << " and " << secNum << "...\nPlacing the sum, " << (firstNum + secNum) << " on top.\n" << endl;
                        RPNStack.insertFront(firstNum+secNum);
                        operandCounter -=1;
                    }
                    break;
                case 45: //subtraction
                    if (operandCounter < 2)
                        cout << "There are not enough operands in the stack to perform this function.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        secNum = RPNStack.removeFront();
                        cout << "Subtracting " << firstNum << " from " << secNum << "...\nPlacing the difference, " << (secNum - firstNum) << " on top.\n" << endl;
                        RPNStack.insertFront(secNum - firstNum);
                        operandCounter -=1;
                    }
                    break;
                case 42: //multiplication
                    if (operandCounter < 2)
                        cout << "There are not enough operands in the stack to perform this function.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        secNum = RPNStack.removeFront();
                        cout << "Multiplying " << firstNum << " and " << secNum << "...\nPlacing the product, " << (secNum * firstNum) << " on top.\n" << endl;
                        RPNStack.insertFront(secNum * firstNum);
                        operandCounter -=1;
                    }
                    break;
                case 47: //division
                    if (operandCounter < 2)
                        cout << "There are not enough operands in the stack to perform this function.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        if (firstNum == 0 || firstNum == -0)
                        {
                            cout << "Cannot divide by zero.\n" << endl;
                            RPNStack.insertFront(firstNum);
                            break;
                        }
                        secNum = RPNStack.removeFront();
                        cout << "Dividing " << firstNum << " out of " << secNum << "...\nPlacing the quotient, " << (secNum / firstNum) << " on top.\n" << endl;
                        RPNStack.insertFront(secNum / firstNum);
                        operandCounter -=1;
                    }
                    break;
                case 110: // negation
                case 78:
                    if (operandCounter < 1)
                        cout << "There are not enough operands in the stack to perform this function.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        secNum = -firstNum;
                        cout << "Negating " << firstNum << "...\nPlacing the result, " << (secNum) << " on top.\n" << endl;
                        RPNStack.insertFront(secNum);
                    }
                    break;
                case 100: //duplication
                case 68:
                    if (operandCounter < 1)
                        cout << "There are not enough operands in the stack to perform this function.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        cout << "Duplicating " << firstNum << "...\nPlacing the result, " << firstNum << " on top.\n" << endl;
                        RPNStack.insertFront(firstNum);
                        RPNStack.insertFront(firstNum);
                        operandCounter += 1;
                    }
                    break;
                case 114: //reversal
                case 82:
                    if (operandCounter < 2)
                        cout << "There are not enough operands in the stack to perform this function.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        secNum = RPNStack.removeFront();
                        cout << "Reversing " << firstNum << " and " << secNum << "...\nPlacing them on top in reverse order.\n" << endl;
                        RPNStack.insertFront(firstNum);
                        RPNStack.insertFront(secNum);
                    }
                    break;
                case 65: //print All
                case 97:
                    if (operandCounter < 1)
                        cout << "There are no operands in the stack.\n" << endl;
                    else
                    {
                        Dlist<float> printList(RPNStack);
                        for (int i = operandCounter; i > 0; i--)
                            {cout << printList.removeFront() << " ";
                            }
                        cout << endl << endl;
                    }
                    break;
                case 112: //print one
                case 80:
                    if (operandCounter < 1)
                        cout << "There are no operands in the stack.\n" << endl;
                    else
                    {
                        firstNum = RPNStack.removeFront();
                        cout << "The top number of the stack is " << firstNum << endl << endl;
                        RPNStack.insertFront(firstNum);
                    }
                    break;
                case 99: //clear
                case 67:
                    if (operandCounter < 1)
                        cout << "Stack cleared.\n" << endl;
                    else
                    {
                        for(operandCounter; operandCounter > 0; operandCounter--)
                        RPNStack.removeFront();
                        cout << "Stack cleared.\n" << endl;
                    }
                    break;
                default:
                    cout << "Invalid input; please try again.\n" << endl;
                    break;

            }
            cout << "[0-9] Place this number onto the top of the stack\n[+] Add the top two numbers and place the result back on top\n";
            cout << "[-] Subtract the top number from the second and place the result back on top\n[*] Multiply the top two numbers and place the result back on top\n";
            cout << "[/] Divide the second number in the stack by the first number and place the result back on top\n";
            cout << "[n] Make the top number on the stack negative\n[d] Duplicate the top number of the stack; push the duplicate onto the front\n";
            cout << "[r] Swap the top two numbers on the stack\n[p] Prints the top number on the stack\n[c] Clears (empties) the stack\n";
            cout << "[a] Print all the numbers on the stack\n[q] Return to the main menu\n\n\nPlease enter your input.\n\n>";
            cin.sync();
            cin >> userInc;
            userIn = userInc;
        }
    return;
}



#endif // RPN_H_INCLUDED
