#include "BST.h"

const int MAX = 100;
const int QUIT = 11;

int printMenu();
void add100BST(BST& b);
void add_elementToBST(BST& b);
void remove_elementFromBST(BST& b);
void findMax(const BST& b);
void findMin(const BST& b);
void findDepth(const BST& b);

int main() {

  BST b;

  int opt = printMenu();
  while (opt != QUIT) {
    switch(opt){
      case 1:
        add100BST(b);
        break;
      case 2:
        b.printInorder();
        break;
      case 3:
        b.graph();
        break;
      case 4:
        add_elementToBST(b);
        break;
      case 5:
        remove_elementFromBST(b);
        break;
      case 6:
        b.reset();
        break;
      case 7:
        findMax(b);
        break;
      case 8:
        findMin(b);
        break;
      case 9:
        cout << b.numLeaves() << endl;
        break;
      case 10:
        findDepth(b);
        break;
      case QUIT:
        break;
      default:
        cout << "Invalid choice";
    }
    opt = printMenu();
  }

  //b.printInorder();

  return 0;
}

int printMenu() {

  int option;

  cout << "Welcome to the BST Program. Make a choice." << endl;
  cout << "1. Add 100 new integers from BST file to BST tree" << endl;
  cout << "2. Print InOrder" << endl;
  cout << "3. Graph Print" << endl;
  cout << "4. Add an element to the BST" << endl;
  cout << "5. Remove an element from the BST" << endl;
  cout << "6. Reset the BST (empty it)" << endl;
  cout << "7. Find the Max" << endl;
  cout << "8. Find the Min" << endl;
  cout << "9. Count the number of Leaves" << endl;
  cout << "10. Get the depth of a node" << endl;
  cout << "11. Quit" << endl;
  cout << endl << "What is your choice? ";
  cin >> option;

  return option;
}

void add100BST (BST& b) {
  int a[MAX];
  string input;
  ifstream myReadFile;

  cout << "BST file: ";
  cin >> input;

  myReadFile.open(input);

  for (int i = 0; i < MAX; i++) {
    myReadFile >> a[i];
  }

  myReadFile.close();

  for (int i = 0; i < MAX; i++) {
    b.insert(a[i]);
  }
}

void add_elementToBST(BST& b) {
  int x;
  cout << "What integer would you like to add? ";
  cin >> x;
  b.insert(x);
}

void remove_elementFromBST(BST& b) {
  int x;
  cout << "What integer would you like to remove? ";
  cin >> x;
  b.remove(x);
}

void findMax(const BST& b) {
  int x;
  if (b.max(x)) {
    cout << "The maximum is " << x << endl;
  }
  else {
    cout << "The tree is empty." << endl;
  }
}

void findMin(const BST& b) {
  int x;
  if (b.min(x)) {
    cout << "The minimum is " << x << endl;
  }
  else {
    cout << "The tree is empty." << endl;
  }
}

void findDepth(const BST& b) {
  int x;
  cout << "What integer would you like to know the depth of? ";
  cin >> x;
  cout << endl;

  int depth = b.depth(x);
  if (depth == -1) {
    cout << x << " is not in the tree." << endl;
  }
  else {
    cout << "The depth of the tree is " << depth << endl;
  }
}
