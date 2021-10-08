/*
card.cpp

Author: Jiwoo Lee

Short description of this file: defines functions of class Card
*/
#include "card.h"

// constructor
Card::Card() {}

/*
* Function: toString
* ---------------------
* combines rank and suit into a string
* returns: string that consists of rank and suit
*/
string Card::toString() const {
  string card = "";
  card += rank;
  card += suit;
  return card;
}

/*
* Function: getValue
* ---------------------
* computes the value of the card
* returns: integer value of the card
*/
int Card::getValue() const {
  // if rank is digit, return face value
  if (isdigit(rank)) {
    int value = rank - '0';
    return value;
  }
  // else return 11 for Ace and 10 for others
  else {
    if (rank == 'A')
      return 11;
    else return 10;
  }
}
