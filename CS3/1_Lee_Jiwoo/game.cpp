/*
game.cpp

Author: Jiwoo Lee

Short description of this file: defines functions of class Game
*/
#include "game.h"

// constructor
Game::Game() {}

/*
* Function: setDeck
* ---------------------
* set the deck of the p
* returns: pass-by-reference, a player's deck with a newly dealt card
*/
void Game::setDeck(int player, Deck& deck) {
  Card card;
  deck.dealFromTop(card);
  if (player == 1) {
    deck1.addToBottom(card);
  }
  else if (player == 2) {
    deck2.addToBottom(card);
  }
  else if (player == 3) {
    deckD.addToBottom(card);
  }
  return;
}

bool Game::busted(int player) {
  if (player == 1) {
    if (deck1.getTotalHandValue() > 21) {
      return true;
    }
    else return false;
  }
  else if (player == 2) {
    if (deck2.getTotalHandValue() > 21) {
      return true;
    }
    else return false;
  }
  else {
    if (deckD.getTotalHandValue() > 21) {
      return true;
    }
    else return false;
  }
}

/*
* Function: checkWin
* ---------------------
* check the winner
* returns: pass-by-reference, bool w1, w2, wD
*/
void Game::checkWin(bool& w1, bool& w2, bool& wD,
                    const bool& b1, const bool& b2, const bool& bD)
{
  int total1 = deck1.getTotalHandValue(), total2 = deck2.getTotalHandValue(),
      totalD = deckD.getTotalHandValue();

  // if dealer is busted
  if (bD) {
    if (b1) {
      // tie = dealer wins
      w1 = false;
      wD = true;
    }
    else if (!b1) {
      w1 = true;
      wD = false;
    }
    if (b2) {
      // tie = dealer wins
      w2 = false;
      wD = true;
    }
    else if (!b2) {
      w2 = true;
      wD = false;
    }
  }
  // if dealer is not busted
  else if (!bD) {
    if (b1) {
      w1 = false;
      wD = true;
    }
    else if (!b1) {
      if (total1 > totalD) {
        w1 = true;
        wD = false;
      }
      else {
        w1 = false;
        wD = true;
      }
    }

    if (b2) {
      w2 = false;
      wD = true;
    }
    else if (!b2) {
      if (total2 > totalD) {
        w2 = true;
        wD = false;
      }
      else {
        w2 = false;
        wD = true;
      }
    }
  }
}

/*
* Function: playRound
* ---------------------
* plays one round of the game
* returns: none
*/
void Game::playRound(Deck& deck) {
  int bet1, bet2, moneyD = 0;
  char draw1, draw2, drawD;
  bool win1, win2, winD, bust1 = false, bust2 = false, bustD = false;

  cout << "Time for everyone to place their bet!" << endl;
  cout << "-----------------------" << endl;
  cout << name1 << ", how much would you like to bet? ";
  cin >> bet1;
  cout << name2 << ", how much would you like to bet? ";
  cin >> bet2;
  cout << endl;

  cout << name1 << " bets $" << bet1 << endl;
  cout << name2 << "bets $" << bet2 << endl;
  cout << endl;

  cout << "The initial starting cards are:" << endl;
  cout << "-----------------------" << endl;

  setDeck(1, deck);
  setDeck(2, deck);
  setDeck(3, deck);
  setDeck(1, deck);
  setDeck(2, deck);
  setDeck(3, deck);

  cout << name1 << "'s current hand: " << deck1.toString() << endl;
  cout << deck1.getTotalHandValue() << " points" << endl;
  cout << name2 << "'s current hand: " << deck2.toString() << endl;
  cout << deck2.getTotalHandValue() << " points" << endl;
  cout << "Dealer's current hand: " << deckD.toString() << endl;
  cout << deckD.getTotalHandValue() << " points" << endl;

  cout << endl;

  // player1
  cout << name1 << "'s turn: " << endl;
  cout << "-----------------------" << endl;
  cout << name1 << "'s current hand: " << deck1.toString() << endl;
  cout << deck1.getTotalHandValue() << " points" << endl;
  cout << "Would you like to draw another card? (Y or N) : ";
  cin >> draw1;
  if (draw1 == 'Y') {
    cout << name1 << " chooses to draw" << endl;
    setDeck(1, deck);
    cout << name1 << "'s current hand: " << deck1.toString() << endl;
    cout << deck1.getTotalHandValue() << " points" << endl;
    // check if busted
    bust1 = busted(1);
    // if busted, don't let them draw again
    if (bust1) {
      cout << name1 << " is busted" << endl;
      draw1 = 'N';
    }
  }
  else {
    cout << name1 << " chooses to stay" << endl;
  }
  cout << endl;

  // player2
  cout << name2 << "'s turn: " << endl;
  cout << "-----------------------" << endl;
  cout << name2 << "'s current hand: " << deck2.toString() << endl;
  cout << deck2.getTotalHandValue() << " points" << endl;
  cout << "Would you like to draw another card? (Y or N) : ";
  cin >> draw2;
  if (draw2 == 'Y') {
    cout << name2 << " chooses to draw" << endl;
    setDeck(2, deck);
    cout << name2 << "'s current hand: " << deck2.toString() << endl;
    cout << deck2.getTotalHandValue() << " points" << endl;
    // check if busted
    bust2 = busted(2);
    // if busted, don't let them draw again
    if (bust2) {
      cout << name2 << " is busted" << endl;
      draw2 = 'N';
    }
  }
  else {
    cout << name2 << " chooses to stay" << endl;
  }
  cout << endl;

  // dealer
  cout << "Dealer's turn: " << endl;
  cout << "-----------------------" << endl;
  cout << "Dealer's current hand: " << deckD.toString() << endl;
  cout << deckD.getTotalHandValue() << " points" << endl;
  // play by the house rule: draw if deck <= 16, otherwise stay
  if (deckD.getTotalHandValue() <= 16) {
    cout << "Dealer chooses to draw" << endl;
    drawD = 'Y';
    setDeck(3, deck);
    cout << "Dealer's current hand: " << deckD.toString() << endl;
    cout << deckD.getTotalHandValue() << " points" << endl;
    // check if busted
    bustD = busted(3);
    // if busted, don't let them draw again
    if (bustD) {
      cout << "Dealer is busted" << endl;
      drawD = 'N';
    }
  }
  else {
    cout << "Dealer chooses to stay" << endl;
    drawD = 'N';
  }
  cout << endl;

  while (draw1 == 'Y' || draw2 == 'Y' || drawD == 'Y') {

    if (draw1 == 'Y') {
      cout << name1 << "'s turn: " << endl;
      cout << "-----------------------" << endl;
      cout << name1 << "'s current hand: " << deck1.toString() << endl;
      cout << deck1.getTotalHandValue() << " points" << endl;
      cout << "Would you like to draw another card? (Y or N) : ";
      cin >> draw1;
      if (draw1 == 'Y') {
        cout << name1 << " chooses to draw" << endl;
        setDeck(1, deck);
        cout << name1 << "'s current hand: " << deck1.toString() << endl;
        cout << deck1.getTotalHandValue() << " points" << endl;
        bust1 = busted(1);
        if (bust1) {
          cout << name1 << " is busted" << endl;
          draw1 = 'N';
        }
      }
      else {
        cout << name1 << " chooses to stay" << endl;
      }
      cout << endl;
    }

    if (draw2 == 'Y') {
      cout << name2 << "'s turn: " << endl;
      cout << "-----------------------" << endl;
      cout << name2 << "'s current hand: " << deck2.toString() << endl;
      cout << deck2.getTotalHandValue() << " points" << endl;
      cout << "Would you like to draw another card? (Y or N) : ";
      cin >> draw2;
      if (draw2 == 'Y') {
        cout << name2 << " chooses to draw" << endl;
        setDeck(2, deck);
        cout << name2 << "'s current hand: " << deck2.toString() << endl;
        cout << deck2.getTotalHandValue() << " points" << endl;
        bust2 = busted(2);
        if (bust2) {
          cout << name2 << " is busted" << endl;
          draw2 = 'N';
        }
      }
      else {
        cout << name2 << " chooses to stay" << endl;
      }
      cout << endl;
    }

    if (drawD == 'Y') {
      cout << "Dealer's turn: " << endl;
      cout << "-----------------------" << endl;
      cout << "Dealer's current hand: " << deckD.toString() << endl;
      cout << deckD.getTotalHandValue() << " points" << endl;
      if (deckD.getTotalHandValue() <= 16) {
        cout << "Dealer chooses to draw" << endl;
        setDeck(3, deck);
        cout << "Dealer's current hand: " << deckD.toString() << endl;
        cout << deckD.getTotalHandValue() << " points" << endl;
        bustD = busted(3);
        if (bustD) {
          cout << "Dealer is busted" << endl;
          drawD = 'N';
        }
      }
      else {
        cout << "Dealer chooses to stay" << endl;
        drawD = 'N';
      }
      cout << endl;
    }
  }
  checkWin(win1, win2, winD, bust1, bust2, bustD);

  cout << "Let's see how it turned out:" << endl;
  cout << "-----------------------" << endl;
  if (win1) {
    cout << "Yowzah! " << name1 << " wins $" << bet1 << endl;
    money1 += bet1;
  }
  else {
    cout << "Ouch! " << name1 << " loses $" << bet1 << endl;
    money1 -= bet1;
    moneyD += bet1;
  }

  if (win2) {
    cout << "Yowzah! " << name2 << " wins $" << bet2 << endl;
    money2 += bet2;
  }
  else {
    cout << "Ouch! " << name2 << " loses $" << bet2 << endl;
    money2 -= bet2;
    moneyD += bet2;
  }

  cout << endl;
  cout << "The standings so far:" << endl;
  cout << "-----------------------" << endl;
  cout << name1 << " $" << money1 << endl;
  cout << name2 << " $" << money2 << endl;
  cout << "Dealer is up $" << moneyD << endl << endl;

  // moves cards from the players' decks back to the original deck
  Card temp;
  while (!deck1.isEmpty()) {
    deck1.dealFromTop(temp);
    deck.addToBottom(temp);
  }

  while (!deck2.isEmpty()) {
    deck2.dealFromTop(temp);
    deck.addToBottom(temp);
  }

  while (!deckD.isEmpty()) {
    deckD.dealFromTop(temp);
    deck.addToBottom(temp);
  }
}
