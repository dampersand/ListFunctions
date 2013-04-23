#include "dlist.h"
#include <iostream>

//constructors and destructors
template<class T>
Dlist<T>::Dlist()
{
    std::cout << "Constructor Called\n\n";
    makeEmpty();
    std::cout << "Constructor completed\n\n";
}

template<class T>
Dlist<T>::~Dlist()
{
    std::cout << "Destructor called\n\n";
    removeAll();
    makeEmpty();
    delete this->first;
    delete this->last;
    std::cout << "Destructor completed\n\n";
}

template<class T>
Dlist<T>::Dlist(const Dlist &l)
{
    makeEmpty();
    copyAll(l);
}







//utility classes
template<class T>
void Dlist<T>::makeEmpty()
{
    std::cout << "makeEmpty called\n";
    Dlist<T>::node emptyNode;
    emptyNode.next = 0;
    emptyNode.prev = 0;
    emptyNode.o = 0;
    this->first = &emptyNode;
    this->last = &emptyNode;
    std::cout << "makeEmpty completed\n\n";

    return;
}

template<class T>
void Dlist<T>::removeAll()
{
    Dlist<T>::node* dummyNode = new node;
    while (this->last != this->first)
    {
        dummyNode = this->last->prev;
        dummyNode->next = this->last;
        this->last = dummyNode;
        delete this->last->next;
    }

    delete this->last;
    delete this->first;
    delete dummyNode;
    return;
}

template<class T>
void Dlist<T>::copyAll(const Dlist &l)
{
    Dlist<T>::node newEnd = new Dlist<T>::node;
    this->first = &newEnd;
    this->last = &newEnd;
    newEnd.o = l.last->o;
    newEnd.next = 0;
    newEnd.prev = 0;

    Dlist<T>::node* fakeLast = new Dlist<T>::node*;
    fakeLast = l.last;

    while (fakeLast != l.first);
    {
        Dlist<T>::insertFront(fakeLast->o);
        fakeLast = fakeLast->prev;
    }

        Dlist<T>::insertFront(fakeLast->o);
}







//member functions
template<class T>
bool Dlist<T>::isEmpty() const
{
    Dlist<T>::node* testNode;
    testNode = this->first;
    if (testNode == this->last)
    {
        delete testNode;
        return true;
    }
    else
    {
     //   delete testNode;
        return false;
    }
}


//Heads up - the inserter pointer must be deleted by the destructor.
//cout tested - definitely inserting the correct numbers.
template<class T>
void Dlist<T>::insertFront(const T &o)
{
    std::cout << "insertFront called \n";
    std::cout << "first data " << this->first->o << " is at address " << this->first << std::endl;
    std::cout << "next data " << this->first->next->o << " is at address " << this->first->next << std::endl;

    Dlist<T>::node* oldFirst = this->first;
    this->first = new node;
    this->first->next = oldFirst;
    this->first->o = o;
    this->first->prev =0;
    this->first->next->prev = this->first;

    std::cout << "\nfirst data is now " << this->first->o << " and is at new address " << this->first << std::endl;
    std::cout << "next data is now " << this->first->next->o << " and is at new address " << this->first->next << std::endl;
    std::cout << "insertFront completed\n\n";

    return;
}

template <typename T>
void Dlist<T>::insertBack(const T &o)
{
    std::cout << "insertBack called \n";
    std::cout << "last data " << this->flast->o << " is at address " << this->last << std::endl;
    std::cout << "previous data " << this->last->prev->o << " is at address " << this->last->prev << std::endl;

    Dlist<T>::node* oldLast = this->last;
    this->last = new node;
    this->last->prev = oldLast;
    this->last->o = o;
    this->last->next =0;
    this->last->prev->next = this->last;

    std::cout << "\nlast data is now " << this->last->o << " and is at new address " << this->last << std::endl;
    std::cout << "last data is now " << this->last->prev->o << " and is at new address " << this->last->prev << std::endl;
    std::cout << "insertBack completed\n\n";

    return;
}

template<class T>
T Dlist<T>::removeFront()
{

    Dlist<T>::node* dummyNode = new node;
    T temporary;
    try
    {
        if (this->isEmpty())
        {
            emptyList excepted;
            throw excepted;
        }
        temporary = this->first->o;
        dummyNode = this->first->next;
        this->first = dummyNode;
        delete this->first->prev;
        delete dummyNode;
    }
    catch(emptyList e)
    {
        temporary = 0;
        delete dummyNode;
        return temporary;
    }
    return (temporary);


}

template <class T>
T Dlist<T>::removeBack()
{

    T temporary;
    try
    {
        if (this->isEmpty())
        {
            emptyList excepted;
            throw excepted;
        }
        temporary = this->last->o;
        this->last = this->last->prev;
        delete this->last->next;
        delete this->last->next;
        return temporary;
    }

    catch(emptyList e)
    {
        temporary = 0;
        return temporary;
    }


}
