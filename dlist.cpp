#ifndef DLIST_CPP
#define DLIST_CPP
#include "dlist.h"
//#include <iostream>

//constructors and destructors
template<class T>
Dlist<T>::Dlist()
{
    //std::cout << "Constructor Called\n\n";
    this->first = new node;
    this->last = new node;
    makeEmpty();
    //std::cout << "Constructor completed\n\n";
}

template<class T>
Dlist<T>::~Dlist()
{
    //std::cout << "Destructor called\n\n";
    removeAll();
    makeEmpty();
    delete this->first;
    delete this->last;
    //std::cout << "Destructor completed\n\n";
}

template<class T>
Dlist<T>::Dlist(const Dlist &l)
{
    //std::cout << "Copy constructor called\n\n";
    this->first = new node;
    this->last = new node;
    makeEmpty();
    copyAll(l);
}







//utility classes
template<class T>
void Dlist<T>::makeEmpty()
{
    //std::cout << "makeEmpty called\n";
    this->first = 0;
    this->last = 0;
   /* this->first->next = 0;
    this->first->prev = 0;
    this->first->o = 0;
    this->last->next = 0;
    this->last->prev = 0;
    this->last->o = 0;
    this->first = this->last;*/
    //std::cout << "makeEmpty completed\n\n";

    return;
}

template<class T>
void Dlist<T>::removeAll()
{
    Dlist<T>::node* dummyNode = new node;
    while (this->last != this->first)
    {
        dummyNode = this->last;
        this->last = this->last->prev;
        delete dummyNode;
    }
    delete dummyNode;
    return;
}

template<class T>
void Dlist<T>::copyAll(const Dlist &l)
{
    //std::cout << "copyAll called\n";
    Dlist<T>::node* fakeLast;
    fakeLast = l.last;

    while (fakeLast != l.first)
    {
        Dlist<T>::insertFront(fakeLast->o);
        fakeLast = fakeLast->prev;
    }
    Dlist<T>::insertFront(fakeLast->o);
    //std::cout << "copyAll completed\n\n";
    return;
}







//member functions
template<class T>
bool Dlist<T>::isEmpty() const
{
    if (this->first == 0 || this->last == 0)
        return true;
    return false;
}


//Working correctly
template<class T>
void Dlist<T>::insertFront(const T &o)
{
    //std::cout << "insertFront called \n";
   // if (this->first !=this->last)
   // {
        //std::cout << "first data " << this->first->o << " is at address " << this->first << std::endl;
        //std::cout << "next data " << this->first->next->o << " is at address " << this->first->next << std::endl;
   // }
    Dlist<T>::node* oldFirst = this->first;
    this->first = new node;
    this->first->next = oldFirst;
    this->first->o = o;
    this->first->prev =0;
    if (Dlist<T>::isEmpty())
        this->last = this->first;
    else
        this->first->next->prev = this->first;

    //std::cout << "\nfirst data is now " << this->first->o << " and is at new address " << this->first << std::endl;
    //if (this->last != this->first)
        //std::cout << "next data is now " << this->first->next->o << " and is at new address " << this->first->next << std::endl;
    //std::cout << "insertFront completed\n\n";

    return;
}

//Working correctly
template <typename T>
void Dlist<T>::insertBack(const T &o)
{
    //std::cout << "insertBack called \n";
    //if (this->first != this->last)
    //{
        //std::cout << "last data " << this->last->o << " is at address " << this->last << std::endl;
        //std::cout << "previous data " << this->last->prev->o << " is at address " << this->last->prev << std::endl;
    //}

    Dlist<T>::node* oldLast = this->last;
    this->last = new node;
    this->last->prev = oldLast;
    this->last->o = o;
    this->last->next =0;
    if (Dlist<T>::isEmpty())
        this->first = this->last;
    else
        this->last->prev->next = this->last;

    //std::cout << "\nlast data is now " << this->last->o << " and is at new address " << this->last << std::endl;
    //if (this->first !=this->last)
    //{
        //std::cout << "last data is now " << this->last->prev->o << " and is at new address " << this->last->prev << std::endl;
        //std::cout << "insertBack completed\n\n";
    //}

    return;
}

//Working correctly
template<class T>
T Dlist<T>::removeFront()
{
    //std::cout << "removeFront called\n";
    Dlist<T>::node* dummyNode;
    T temporary;
    try
    {   if (isEmpty())
        {
            emptyList excepted;
            throw excepted;
        }
    }
    catch(emptyList e)
    {
        temporary = 0;
        delete dummyNode;
        //std::cout << "removeFront returned an empty-list exception\n";
        return temporary;
    }
    //std::cout << "first data (to be removed) is " << this->first->o << " at " << this->first << std::endl;

    temporary = this->first->o;
    dummyNode = this->first;
    if (this->first != this->last)
    {
        this->first = this->first->next;
        this->first->prev = 0;
    }
    else
        makeEmpty();
    delete dummyNode;
    //if(!isEmpty())
        //std::cout << "new first data is " << this->first->o << " at " << this->first << std::endl;
    //std::cout << "removeFront completed.\n\n";
    return (temporary);


}

template <class T>
T Dlist<T>::removeBack()
{
    //std::cout << "removeBack called\n";
    Dlist<T>::node* dummyNode;
    T temporary;
    try
    {   if (isEmpty())
        {
            emptyList excepted;
            throw excepted;
        }
    }
    catch(emptyList e)
    {
        temporary = 0;
        delete dummyNode;
        //std::cout << "removeBack returned an empty-list exception\n";
        return temporary;
    }
    //std::cout << "last data (to be removed) is " << this->last->o << " at " << this->last << std::endl;

    temporary = this->last->o;
    dummyNode = this->last;
    if (this->first != this->last)
    {
        this->last = this->last->prev;
        this->last->next = 0;
    }
    else
        makeEmpty();
    delete dummyNode;
    //if(!isEmpty())
        //std::cout << "new last data is " << this->last->o << " at " << this->last << std::endl;
    //std::cout << "removeBack completed.\n\n";
    return (temporary);
}



#endif // DLIST_CPP
