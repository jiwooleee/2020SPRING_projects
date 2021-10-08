#include "BST.h"

BST::BST() {
  root = nullptr;
}

BST::~BST() {
  auxD(root);
}

void BST::auxD(BinNode* subR) {
  if (subR != nullptr) {
    auxD(subR->left);
    auxD(subR->right);
    delete subR;
  }
}

void BST::insert(const int& item) {
  BinNode* curr = root;
  BinNode* curr_parent = nullptr;

  bool found = false;
  while (!found && curr != nullptr) {
    curr_parent = curr;
    if (item < curr->data)
      curr = curr->left;
    else if (curr->data < item) {
      curr = curr->right;
    }
    else
      found = true;
  }

  if (!found) {
    curr = new BinNode(item);

    if (curr_parent == nullptr)
      root = curr;
    else if (item < curr_parent->data)
      curr_parent->left = curr;
    else
      curr_parent->right = curr;
  }
  else
    cout << "Item already in the tree" << endl;
}

void BST::printInorder() const {
  BinNode* temp = root;
  auxIn(temp);
  cout << endl;
}

void BST::auxIn(BinNode* subR) const {
  if (subR != nullptr) {
    auxIn(subR->left);
    cout << subR->data << " ";
    auxIn(subR->right);
  }
}

bool BST::search(const int& item) const {
  BinNode* curr = root;

  while(curr != nullptr) {
    if (item < curr->data)
      curr = curr->left;
    else if (item > curr->data)
      curr = curr->right;
    else
      return true;
  }

  return false;
}

void BST::graph() const {
  BinNode* subR = root;
  graphAux(0, subR);
  cout << endl;
}

void BST::graphAux(int indent, BinNode* subR) const {
  if (subR != nullptr) {
    graphAux(indent + 4, subR->right);
    cout << setw(indent) << " " << subR->data << endl;
    graphAux(indent + 4, subR->left);
  }
}

void BST::remove(const int& item) {
  bool found;
  BinNode* x;
  BinNode* parent;

  search2(item, found, x, parent);

  if(!found) {
    cout << "Item not in the BST" << endl;
    return;
  }

  if (x->left != nullptr && x->right != nullptr) {
    BinNode* xSucc = x->right;
    parent = x;

    while (xSucc -> left != 0) {
      parent = xSucc;
      xSucc = xSucc->left;
    }

    x->data = xSucc->data;
    x = xSucc;
  }

  BinNode* subtree = x->left;
  if (subtree == nullptr) {
    subtree = x->right;
  }
  if (parent == nullptr) {
    root = subtree;
  }
  else if (parent->left == x) {
    parent->left = subtree;
  }
  else
    parent->right = subtree;

  delete x;
}

void BST::search2(const int& item, bool& found,BinNode* & locptr, BinNode* & parent)
{
  locptr = root;
  parent = nullptr;
  found = false;
  while (!found && locptr != nullptr) {
    if (item < locptr->data) {
      parent = locptr;
      locptr = locptr->left;
    }
    else if (locptr->data < item) {
      parent = locptr;
      locptr = locptr->right;
    }
    else
      found = true;
  }
}

void BST::reset() {
  auxD(root);
  root = nullptr;
}

bool BST::max(int& retData) const {
  return maxAux(retData, root);
}

bool BST::maxAux(int& retData, BinNode* subR) const {
  if (subR == nullptr) {
    return false;
  }
  if (subR->right == nullptr) {
    retData = subR->data;
    return true;
  }
  return maxAux(retData, subR->right);
}



bool BST::min(int& retData) const {
  return minAux(retData, root);
}

bool BST::minAux(int& retData, BinNode* subR) const {
  if (subR == nullptr) {
    return false;
  }
  if (subR->left == nullptr) {
    retData = subR->data;
    return true;
  }
  return minAux(retData, subR->left);
}

int BST::numLeaves() const {
  BinNode* subR = root;
  return numLeavesAux(subR);
}

int BST::numLeavesAux(BinNode* subR) const {
  if (subR == nullptr) {
    return 0;
  }
  if (subR->left == nullptr && subR->right == nullptr) {
    return 1;
  }
  else {
    return numLeavesAux(subR->left) + numLeavesAux(subR->right);
  }
}

int BST::depth(const int& item) const {
  BinNode* curr = root;
  int depth = 0;
  bool found = false;

  while(curr != nullptr && !found) {
    if (item < curr->data) {
      curr = curr->left;
      depth++;
    }
    else if (item > curr->data) {
      curr = curr->right;
      depth++;
    }
    else
      found = true;
  }

  if (found) {
    return depth;
  }
  else return -1;
}
