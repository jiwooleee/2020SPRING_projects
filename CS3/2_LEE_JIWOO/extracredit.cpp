// FILE: Slist.cpp
// B Sanders, Rhodes College
// updated: 2.03.2020 CLION FIX
//
//		Implementation: singly linked list
//
//		Class invariants:
//			- head, tail, and cursor are nonzero
//			- head points at empty head node
//			- tail points at last node
//			- last node has zero next pointer
//    Extra credit:
//      - functions are recursively implemented.
#include	"extracredit.h"


//////// private data type: Node ////////

struct Slist::Node {

// Node constructors

	Node (void) {
		next = 0;
	}
	Node (const DataType& newItem) {
		dataItem = newItem;
		next = 0;
	}

// Node data

	DataType	dataItem;
	Node		*next;
};


//////// public member functions ////////

//// constructor, destructor
Slist::Slist (void) {
	tail = cursor = head = new Node;
}

Slist::~Slist (void) {
	clean ();
	delete head;
}

//// mutators

bool Slist::append (const Slist& other) {
	if (other.empty()) {
		return false;
	}
	if (this == &other) {
		return false;
	}

	moveToEnd();
	Node* temp = (other.head)->next;
  /*
	while(temp) {
		insert(temp->dataItem);
		temp = temp->next;
		moveToEnd();
	}
  */
  appendAux(other, temp);
	reset();
	return true;
}

void Slist::appendAux(const Slist& other, Node* temp) {
  if (!temp) {
    return;
  }
  else {
    insert(temp->dataItem);
    moveToEnd();
    return appendAux(other, temp->next);
  }
}

bool Slist::prepend (const Slist& other) {
	if (other.empty()) {
		return false;
	}
	if (this == &other) {
		return false;
	}

	reset();
  Node* temp = (other.head)->next;
  /*
	while(temp) {
		insert(temp->dataItem);
		temp = temp->next;
		move();
	}
  */
  prependAux(other, temp);
	reset();
	return true;
}

void Slist::prependAux (const Slist& other, Node* temp) {
  if (!temp) {
    return;
  }
  else {
    insert(temp->dataItem);
    move();
    return prependAux(other, temp->next);
  }
}

bool Slist::rotateLeft(unsigned n) {
	if (n == 0) {
		return false;
	}
	reset();
	for (int i = 0; i < n; i++) {
		move();
	}
	if (cursor == nullptr) {
		return false;
	}

	tail->next = head->next;
	head->next = cursor->next;
	cursor->next = nullptr;
	tail = cursor;
	reset();
	return true;
}

bool Slist::rotateRight(unsigned n) {
	if (n > length()) {
		n %= length();
	}
	n = length() - n;
	return rotateLeft(length() - n);
}

int Slist::length() const {
	int length = 0;
	Node* curr = head->next;
	while (curr != nullptr) {
		length++;
		curr = curr->next;
	}
	return length;
}

bool Slist::truncate(DataType item) {
	DataType temp;
  bool isThere;
  Node *index;
  for (int i = 0; i < length(); i++) {
      get(temp);
      if (temp == item) {
          isThere = true;
          index = cursor;
      }
      move();
  }
  if (!isThere) {
      return false;
  }
  cursor = index;
  while(remove()) {
  }
  return true;
}

void Slist::reverse(void) {
	if (length() <= 1) {
		return;
	}
	Node* curr = head->next;
	head->next = tail;
	Node* temp = curr;
	head = cursor;
	tail = temp;
	Node* prev;
	Node* after;
	reverseAux(curr, prev, after);
	tail->next = nullptr;
	reset();
}

void Slist::reverseAux(Node* curr, Node* prev, Node* after) {
  if (!curr) {
    return;
  }
  else {
    after = curr->next;
    curr->next = prev;
    prev = curr;
    curr = after;
    return reverseAux(curr, prev, after);
  }
}

// insert
//		insert newItem after cursor node
void Slist::insert (DataType newItem) {
	Node *pNewNode = new Node (newItem);
	pNewNode -> next = cursor -> next;
	if ((pNewNode -> next) == 0) {
		tail = pNewNode;
	}
	cursor -> next = pNewNode;
}

// remove
//		delete node following cursor node
bool Slist::remove (void) {
	Node *temp = cursor -> next;
	if (temp) {
		if (temp == tail) {
			tail = cursor;
		}
		cursor -> next = cursor -> next -> next;
		delete temp;
		return true;
	}
	return false;
}

// clean
//		delete all nodes
void Slist::clean (void) {
	reset ();
	while (remove ()) {
	}
}

// move
//		move cursor to next node
bool Slist::move (void) {
	if (cursor -> next) {
		cursor = cursor -> next;
		return true;
	}
	return false;
}

// moveToEnd
//		set cursor to point to tail node
void Slist::moveToEnd (void) {
	 cursor = tail;
}

// reset
//		set cursor to point to empty head node
void Slist::reset (void) {
	 cursor = head;
}



//// accessors


// empty
//		return true if list is empty; false otherwise
bool Slist::empty (void) const {
	return (head == tail);
}

// get
//		retrieve data item in node after cursor node
bool Slist::get (DataType& item) const {
	if (cursor -> next) {
		item = cursor -> next -> dataItem;
		return true;
	}
	return false;
}

// printDEBUG	[public wrapper]
//		print all items of the list
//		[for debugging ONLY --- application would normally control all output!]
void Slist::printDEBUG (void) const {
	printDEBUG (head -> next);
}



//////// private member function ////////

// printDEBUG	[private accessor]
//		print data item stored in thisNode and beyond
void Slist::printDEBUG (const Node *thisNode) const {
	if (thisNode) {
		cout << thisNode -> dataItem << ' ';
		printDEBUG (thisNode -> next);
	}
}
