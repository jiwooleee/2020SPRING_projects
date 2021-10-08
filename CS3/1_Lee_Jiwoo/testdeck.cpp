#include "deck.h"

int main() {

  Deck deck;
  Card card1('A', 'H');
  Card card2('2', 'S');
  Card card3('T', 'C');
  Card card4;

  cout << deck.size();
  if (deck.isEmpty()) {
    cout << "Empty" << endl;
  }
  else {
    cout << "Not empty" << endl;
  }

  deck.addToBottom(card1);
  deck.addToBottom(card2);
  deck.addToBottom(card3);

  cout << deck.toString() << endl;
  cout << deck.size();
  deck.dealFromTop(card4);

  cout << card4.toString() << endl;
  return 0;
}
