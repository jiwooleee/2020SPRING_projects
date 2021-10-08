#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

template <class T>
void merge(const vector<T> L1, unsigned n1, const vector<T> L2,
                        unsigned n2, vector<T> &a, unsigned n) {
  unsigned i = 0, j = 0, k = 0;

  while (i < n1 && j < n2) {
    if (L1.at(i) <= L2.at(j)) {
      a.at(k) = L1.at(i);
      i++;
    }
    else {
      a.at(k) = L2.at(j);
      j++;
    }
    k++;
  }

  if (i == n1) {
    while (j < n2) {
      a.at(k) = L2.at(j);
      k++;
      j++;
    }
  }
  else {
    while (i < n1) {
      a.at(k) = L1.at(i);
      k++;
      i++;
    }
  }
}

template <class T>
void mergeSort(vector<T> &a, unsigned n) {
  if(n > 1) {
    vector<T> L1, L2;
    int i = 0;
    for (T item : a) {
      if (i < (n / 2)) {
        L1.push_back(item);
      }
      else {
        L2.push_back(item);
      }
      i++;
    }
    mergeSort(L1, (n / 2));
    mergeSort(L2, (n - (n / 2)));
    merge(L1, (n / 2), L2, (n - (n / 2)), a, n);
  }
}

template <class T>
void bubbleSort(vector<T>& a, unsigned n) {
  unsigned end = n;
  bool sorted = false;
  while (end > 1 && !sorted) {
    sorted = true;
    for (int i = 1; i < end; i++) {
      if (a.at(i - 1) > a.at(i)) {
        int temp = a.at(i);
        a.at(i) = a.at(i - 1);
        a.at(i - 1) = temp;
        sorted = false;
      }
    }
    end--;
  }
}

template <class T>
int split(vector<T>& a, int first, int last) {
  T pivot = a.at(first);
  int left = first;
  int right = last;

  while (left < right) {
    while (pivot < a.at(right)) {
      right--;
    }
    while (left < right && a.at(left) <= pivot) {
      left++;
    }
    if (left < right) {
      T temp = a.at(left);
      a.at(left) = a.at(right);
      a.at(right) = temp;
    }
  }
  a.at(first) = a.at(left);
  a.at(left) = pivot;
  return left;
}

template <class T>
void quickSort(vector<T>& a, int first, int last) {
  int pos;
  if (first < last) {
    pos = split(a, first, last);
    quickSort(a, first, pos - 1);
    quickSort(a, pos + 1, last);
  }
}
