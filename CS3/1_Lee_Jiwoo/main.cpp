/*
main.cpp

Author: Jiwoo Lee

Short description of this file: implements game.cpp & lets the user play blackjack

Extra credit: allows the user to shuffle the deck
*/
#include "game.h"

/*
* Function: shuffle
* ---------------------
* generates and shuffles a deck
* returns: a shuffled deck
*/
Deck shuffle() {
  char ranks[] = {'1', '2', '3', '4', '5', '6', '7', '8','9', 'T', 'J', 'Q', 'K',
                  'A'};
  char suits[] = {'D', 'S', 'C', 'H'};
  // temporary vector to store cards
  vector <Card> cards;
  Deck deck;
  int cardInd = -1;

  // generate a vector of cards
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      Card card(ranks[j], suits[i]);
      cards.push_back(card);
    }
  }

  // adds to deck, delete from cards
  while (cards.size() != 0) {
    cardInd = rand() % (cards.size());
    deck.addToBottom(cards.at(cardInd));
    cards.erase(cards.begin() + cardInd);
  }

  return deck;
}

int main() {
  srand(time(0));
  char display = 'n';

  cout << "Hello! Enter 'y' if you want to see the rules. ";
  cin >> display;

  if (display == 'y') {
    cout << "Each player is asked how much they would like to bet on each round."
         << endl;
    cout << "(Minimum bet is $1 at our table)" << endl;
    cout << "You can bet more money than you have." << endl;
    cout << "The dealer gives every player, including themselves, two cards,";
    cout << " one card face up and the other face down." << endl;
    cout << "Each player can look at both of their cards but ";
    cout << "they can't see the other players' face down card." << endl;
    cout << "The goal of each player is to get as close to 21 without going over.";
    cout << endl << "Numbered cards are worth their numbered value and face cards";
    cout << " have the value 10." << endl;
    cout << "Aces can coutn as 1 or 11.";
    cout << "You can take a hit until you no longer want any more or your hand ";
    cout << "value excees 21, meaning that you are busted." << endl;
    cout << "If you bust, then you automaticallly lose." << endl;
    cout << "All ties with the dealer go to the dealer." << endl;
  }

  string filename, line, player1, player2;
  int money1, money2;
  char rank, suit, doShuffle, keepGoing;
  Deck startDeck;

  cout << "Please enter the text file name: ";
  cin >> filename;

  // read in from the file
  ifstream inFS;
  inFS.open(filename);
  inFS >> player1 >> money1;
  inFS >> player2 >> money2;
  inFS.ignore();
  while(!inFS.eof()) {
    getline(inFS, line);
    istringstream inCard(line);
    inCard >> rank >> suit;
    Card card = Card(rank, suit);
    startDeck.addToBottom(card);
  }

  Game g = Game(player1, player2, money1, money2);

  do {
    // shuffle
    cout << "Do you want to shuffle the deck? (Y or N): ";
    cin >> doShuffle;
    if (doShuffle == 'Y') {
      cout << "Will do!" << endl;
      startDeck = shuffle();
    }
    else {
      cout << "Aight! No shuffling" << endl;
    }

    // play blackjack
    g.playRound(startDeck);

    cout << "Another round? (Y or N) : ";
    cin >> keepGoing;

  } while (keepGoing == 'Y');

  cout << "Thanks for playing! Hope to see you again soon :D" << endl;
  return 0;
}
