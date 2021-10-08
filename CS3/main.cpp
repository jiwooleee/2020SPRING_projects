/*
Assignment 3
Written by: Jiwoo Lee
Date: 03/24/2020
Extra credit: quicksort
*/
#include "SortAlgs.h"

int main() {
  srand(time(0));
  vector<int> a;

  // insert 1000 random integers into the vector
  for (int i = 0; i < 1000; i++) {
    a.push_back(rand() % 1000);
  }

  vector<int> b = a;
  vector<int> c = a;

  // set the timer
  auto start = high_resolution_clock::now();

  unsigned n = a.size();
  mergeSort(a, n);
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Mergesort took " << duration.count() << " microseconds." << endl;

  // set the timer
  start = high_resolution_clock::now();

  n = b.size();
  bubbleSort(b, n);
  stop = high_resolution_clock::now();

  duration = duration_cast<microseconds>(stop - start);
  cout << "Bubblesort took " << duration.count() << " microseconds." << endl;

  // set the timer
  start = high_resolution_clock::now();

  n = c.size();
  quickSort(c, 0, n - 1);
  stop = high_resolution_clock::now();

  duration = duration_cast<microseconds>(stop - start);
  cout << "Quicksort took " << duration.count() << " microseconds." << endl;

  return 0;
}
