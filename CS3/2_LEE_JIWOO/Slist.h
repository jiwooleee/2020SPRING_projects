// FILE: Slist.h
// B Sanders, Rhodes College
// updated: 1.31.2020 CLION FIX
//
//		Interface: singly linked list
//

#ifndef	SLIST_H
#define	SLIST_H

#include "DataType.h"


class Slist {
public:
//// public member functions:

	Slist (void);					//// constructor, destructor
	~Slist (void);

									//// mutators

	void insert (DataType newItem);	// insert new item after current
	bool remove (void);						// remove item
	void clean (void);						// remove all items

	bool move (void);						// move to next item
	void moveToEnd (void);					// move to end of list
	void reset (void);						// return to beginning of list

	bool append(const Slist& other); // append a copy of another list to
																	 // the end of this list

	bool prepend(const Slist& other); // prepend a copy of another list to
																		// the beginning of this list

	bool rotateLeft(unsigned n); // rotate nodes in this list from front to back
															 // n positions

	bool rotateRight(unsigned n); // rotate nodes in this list from back to front
	 														 // n positions

	int length() const; // return the number of (real) nodes in this list

	bool truncate (DataType item); // delete all of this list including and beyond
																 // the first occurrence of item

	void reverse(void); // reverse the order of nodes in this list

									//// accessors

	bool empty (void) const;				// is list empty?
	bool get (DataType& item) const;		// get current item
	void printDEBUG (void) const;			// print all items [DEBUG]
	


private:
//// private data
	struct Node;		// (pure declaration --- not a definition
	Node *head, *tail, *cursor;

//// private member function:

	void printDEBUG (const Node *thisNode) const;
};



#endif
