/*
deck.h

Author: Jiwoo Lee

Short description of this file: defines class Deck

*/
#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck : public Card {
  private:
    vector <Card> cards;
  public:
    Deck();
    void dealFromTop(Card& card);
    void addToBottom(const Card& card);
    int size() const;
    bool isEmpty() const;
    string toString() const;
    int getTotalHandValue() const;
};
#endif
