#ifndef BINNODE_H
#define BINNODE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class BinNode {
public:
  BinNode() {
    left = nullptr;
    right = nullptr;
  }
  BinNode(int d) {
    data = d;
    left = nullptr;
    right = nullptr;
  }
  int data;
  BinNode *left;
  BinNode *right;
};

#endif
