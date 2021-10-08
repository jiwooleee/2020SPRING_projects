#include "BinNode.h"

#ifndef BST_H
#define BST_H

class BST {
public:
  BST();
  ~BST();
  bool max(int& retData) const;
  bool min(int& retData) const;
  int depth(const int& item) const;
  int numLeaves() const;
  void reset();
  void insert(const int& item);
  void printInorder() const;
  bool search(const int& item) const;
  void graph() const;
  void graphAux(int indent, BinNode* subR) const;
  void remove(const int& item);
  void search2(const int& item, bool& found,BinNode* & locptr, BinNode* & parent);

private:
  BinNode* root;
  void auxD(BinNode* subR);
  void auxIn(BinNode* subR) const;
  bool maxAux(int& retData, BinNode* subR) const;
  bool minAux(int& retData, BinNode* subR) const;
  int numLeavesAux(BinNode* subR) const;
};

#endif
