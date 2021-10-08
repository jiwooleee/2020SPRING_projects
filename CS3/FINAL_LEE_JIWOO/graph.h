#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
  Graph() {
    size = 0;
    reset();
  }
  Graph(int s) {
    size = s + 1;
    reset();
  }
  void reset();
  void insertEdge(int from, int to, int weight);
  void printGraph() const;
  void dijkstra(int start);
  void writeFile(int start);
  int INF = 1000000; // assume infinity = million
  int dist[100];
  int prev[100];
  bool visited[100];
private:
  int a[100][100];
  int size;
  void writeAux(int start, int curr, ofstream& outFile);
};

#endif
