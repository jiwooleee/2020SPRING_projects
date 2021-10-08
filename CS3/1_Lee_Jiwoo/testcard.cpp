#include "card.h"
#include <fstream>
int main() {

  Card a = Card('A', 'S');
  Card b = Card('2', 'H');
  Card c = Card('K', 'C');
  Card d = Card('Q', 'D');
  Card e = Card('J', 'S');
  cout << "a is " << a.toString() << endl;
  cout << "a = " << a.getValue() << endl;
  cout << "b is " << b.toString() << endl;
  cout << "b = " << b.getValue() << endl;
  cout << "c is " << c.toString() << endl;
  cout << "c = " << c.getValue() << endl;
  cout << "d is " << d.toString() << endl;
  cout << "d = " << d.getValue() << endl;
  cout << "e is " << e.toString() << endl;
  cout << "e = " << e.getValue() << endl;

 string filename, p1, p2;
 char rank, suit;
 int money1, money2;
 cout << "Please enter the file name: ";
 cin >> filename;
 ifstream inFS;
 inFS.open(filename);

 inFS >> p1 >> money1 >> p2 >> money2;
 inFS >> rank >> suit;
 cout << p1 << money1 << p2 << money2;
 Card card = Card(rank, suit);
 cout << "The card you read in is " << card.toString() << endl;
 cout << "Card = " << card.getValue() << endl;



  return 0;
}
