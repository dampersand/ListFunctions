Fooling around with C++ templates in an object-oriented setting.

dampersand

This program is supposed to create a stack of cards - the caveat is that it uses a predefined "dlist.h," which makes my life harder (no recursion :'( ). 

Mixing pointers and classes - not something I've had a lot of practice with.  Thus, I'm working my way through this project.

As of 4/22/2013, the program compiles, but I have the sneaking suspicion there are memory leaks.  I'll get to them as I test different sections of the program out.

Currently tested:
-insertFront: I would call this a memory leak, but in reality I CAN'T allow those nodes to be destroyed, lest the memory address get used by a different node.  And it can.  Which sucks.  No matter, removeFront, removeBack, and removeAll should eliminate these leaks.
-removeFront: no memory leaks... but for some reason is returning in reverse order, starting from the front? wtf?