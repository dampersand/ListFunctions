#ifndef __DLIST_H__
#define __DLIST_H__

/***************************************
* Do not modify the class declarations!
***************************************/

class emptyList {
// OVERVIEW: an exception class
};

template <typename T>
class Dlist {
// OVERVIEW: contains a double-ended list of Objects

public:

// Operational methods
bool isEmpty() const;
// EFFECTS: returns true if list is empty, false otherwise

void insertFront(const T &o);
// MODIFIES this
// EFFECTS inserts o at the front of the list

void insertBack(const T &o);
// MODIFIES this
// EFFECTS inserts o at the back of the list

T removeFront();
// MODIFIES this
// EFFECTS  removes and returns first object from non-empty list
//          throws an instance of emptyList if empty

T removeBack();
// MODIFIES this
// EFFECTS  removes and returns last object from non-empty list
//          throws an instance of emptyList if empty

// Maintenance methods
Dlist();                            // ctor
Dlist(const Dlist &l);              // copy ctor
Dlist &operator=(const Dlist &l);   // assignment
~Dlist();                           // dtor

private:
// A private type
struct node {
 node *next;
 node *prev;
 T o;
};

node *first; // The pointer to the first node (0 if none)
node *last; // The pointer to the last node (0 if none)

// Utility methods

void makeEmpty();
// EFFECT: called by constructors to establish empty
// list invariant

void removeAll();
// EFFECT: called by destructor and operator= to remove and destroy
// all list nodes

void copyAll(const Dlist &l);
// EFFECT: called by copy constructor/operator= to copy nodes
// from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/
/***************************************
* Member function implementations follow
***************************************/


/* this must be at the end of the file */
#endif /* __DLIST_H__ */
