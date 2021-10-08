/*
deck.cpp

Author: Jiwoo Lee

Short description of this file: defines functions of class Deck
*/
#include "deck.h"

// constructor
Deck::Deck() {}

/*
* Function: dealFromTop
* ---------------------
* removes the first card from the deck if the deck is not empty
* returns: pass-by-reference, the first card
*/
void Deck::dealFromTop(Card& card) {
  // return if the deck is empty
  if (isEmpty()) {
    return;
  }
  else {
    Card temp = cards.at(0);
    cards.erase(cards.begin());
    card = temp;
  }
}

/*
* Function: addToBottom
* ---------------------
* adds a card to the deck
* returns: none
*/
void Deck::addToBottom(const Card& card) {
  cards.push_back(card);
  return;
}

/*
* Function: size
* ---------------------
* returns: the size of the deck
*/
int Deck::size() const{
  return cards.size();
}

/*
* Function: isEmpty
* ---------------------
* returns: whether the deck is empty or not
*/
bool Deck::isEmpty() const{
  if (cards.size() == 0)
    return true;
  else
    return false;
}

/*
* Function: toString
* ---------------------
* combines every card in the deck into a string
* returns: string that consists of every card in the deck
*/
string Deck::toString() const{
  if (isEmpty())
    return "[]";
  else {
    string deck = "["+ (cards.at(0)).toString();

    for (int i = 1; i < cards.size(); i++) {
      deck += " ";
      deck += (cards.at(i)).toString();
    }

    deck += "]";

    return deck;
  }
}

/*
* Function: getTotalHandValue
* ---------------------------
* computes the total hand value of the deck
* when a deck has Ace(s), chooses whichever value (1 or 11) is best
* for the player
* returns: the total hand value
*/
int Deck::getTotalHandValue() const {
  int numAce = 0;
  int totalVal = 0;
  int cardVal;

  for (Card card : cards) {
    cardVal = card.getValue();
    if (cardVal == 11) {
      // computes the number of Ace(s)
      numAce++;
    }
    else {
      totalVal += cardVal;
    }
  }

  while (numAce != 0) {
      // When total value + (numAce - 1) * 1 + 11 <= 21,
      // it's better to use Ace as 11
      if (totalVal + (numAce - 1) + 11 <= 21) {
        totalVal += 11;
      }
      // else adds 1
      else {
        totalVal++;
      }

      numAce--;
  }

  return totalVal;
}
