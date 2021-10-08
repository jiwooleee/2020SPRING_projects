/*
cards.h

Author: Jiwoo Lee

Short description of this file: defines class Card
*/

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Card {
  private:
    char suit;
    char rank;
  public:
    Card();
    Card(char r, char s) : rank(r), suit(s) {}
    string toString() const;
    int getValue() const;
};

#endif
