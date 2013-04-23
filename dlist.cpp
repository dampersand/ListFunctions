#include "dlist.h"

//constructors and destructors
template<class T>
Dlist<T>::Dlist()
{
    makeEmpty();
}

template<class T>
Dlist<T>::~Dlist()
{
    removeAll();
    makeEmpty();
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
    Dlist<T>::node* dummyNode = new node;
    dummyNode->next = 0;
    dummyNode->prev = 0;
    dummyNode->o = 0;

    this->first = dummyNode;
    this->last = dummyNode;
    //delete dummyNode;
}

template<class T>
void Dlist<T>::removeAll()
{
    Dlist<T>::node* dummyNode = new node;
    dummyNode->next = 0;
    dummyNode->prev = 0;
    while (this->last != this->first)
    {
        dummyNode = this->last->prev;
        this->last = dummyNode;
        delete this->last->next;
    }

    delete this->first;
    delete this->last;
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
    Dlist<T>::node* dummyNode = new node;
    dummyNode = this->first;
    if (dummyNode == this->last)
    {
        delete dummyNode;
        return true;
    }
    else
    {
        delete dummyNode;
        return false;
    }
}


//Heads up - the inserter pointer must be deleted by the destructor.
template<class T>
void Dlist<T>::insertFront(const T &o)
{
    Dlist<T>::node* inserter = new node;
    inserter->next = this->first;
    inserter->prev = 0;
    inserter->o = o;
    this->first->prev = inserter;
    this->first = inserter;
    return;
}

template<class T>
void Dlist<T>::insertBack(const T &o)
{
    Dlist<T>::node* inserter = new node;
    inserter->next = 0;
    inserter->prev = this->last;
    inserter->o = o;
    this->last->next = inserter;
    this->last = inserter;
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
        delete *this->last->next;
        return temporary;
    }

    catch(emptyList e)
    {
        temporary = 0;
        return temporary;
    }


}
