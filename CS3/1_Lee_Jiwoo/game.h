/*
game.h

Author: Jiwoo Lee

Short description of this file: defines class Game
*/
#ifndef GAME_H
#define GAME_H
#include "deck.h"

class Game : public Deck {
  private:
    Deck deck1, deck2, deckD;
    string name1, name2;
    int money1, money2;
  public:
    Game();
    Game(string n1, string n2, int m1, int m2) : name1(n1), name2(n2),
                                                 money1(m1), money2(m2) {}
    void setDeck(int player, Deck& deck);
    void playRound(Deck& deck);
    bool busted(int player);
    void checkWin(bool& w1, bool& w2, bool& wD,
                  const bool& b1, const bool& b2, const bool& bD);
};
#endif
