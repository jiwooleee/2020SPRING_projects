#include "graph.h"

// initialize adjacency matrix to infinity
void Graph::reset() {
  for (int i = 1; i < size; i++) {
    for (int j = 1; j < size; j++) {
      a[i][j] = INF;
    }
  }
}

// insert an edge
void Graph::insertEdge(int from, int to, int weight) {
  a[from][to] = weight;
}

// print the adjacency matrix
void Graph::printGraph() const {
  for (int i = 1; i < size; i++) {
    for (int j = 1; j < size; j++) {
      if (a[i][j] != INF) {
        cout << " " << a[i][j] << "  ";
      }
      else cout << "INF ";
    }
    cout << endl;
  }
}

// perform Dijkstra
void Graph::dijkstra(int start) {

  // initialize dist, prev, and visited to infinity and false
  for (int i = 1; i < size; i++) {
    if (i != start) {
      dist[i] = INF;
      prev[i] = INF;
      visited[i] = false;
    }
  }

  // initialize distance and visited of start to 0 and false
  dist[start] = 0;
  visited[start] = false;

  // initialize queue and enqueue start
  vector <int> queue;
  queue.push_back(start);
  prev[start] = start;

  while (!queue.empty()) {

    // find the minimum distance in the queue
    int min = INF;
    int minInd = -1;
    int minVertex = -1;

    for (int j = 0; j < queue.size(); j++) {
      if (visited[queue.at(j)] == false && min > dist[queue.at(j)]) {
        min = dist[queue.at(j)];
        minInd = j;
        minVertex = queue.at(j);
      }
    }

    // dequeue the minimum and set visited to true
    queue.erase(queue.begin() + minInd);
    visited[minInd] = true;

    // loop and update distances of adjacent vertices
    for (int k = 1; k < size; k++) {
      int adj = k;
      if (a[minVertex][adj] != INF && visited[adj] == false) {
          queue.push_back(adj);
          int newDist = dist[minVertex] + a[minVertex][adj];
          if (newDist < dist[adj]) {
            dist[adj] = newDist;
            prev[adj] = minVertex;
          }
        }
      }
    }
}

// write the result from dijkstra into a file
void Graph::writeFile(int start) {
  ofstream outFile;
  string outfilename;

  // get file name
  cout << "Enter name of output file: ";
  cin >> outfilename;
  cout << endl;

  outFile.open(outfilename);

  // check if the file is created
  if (!outFile) {
    cerr << "Unable to create a file." << endl;
    return;
  }

  // start writing
  for (int i = 1; i < size; i++) {
    // vertex number:
    int currVertex = i;
    outFile << currVertex << ": ";

    // start vertex
    if (currVertex == start) {
      outFile << dist[currVertex] << " [" << currVertex << "]" << endl;
    }
    // vertices that have no path to the start vertex
    else if (dist[currVertex] == INF) {
      outFile << "NO PATH" << endl;
    }
    // else
    else {
      outFile << dist[currVertex] << " ";
      // write recursively
      writeAux(start, currVertex, outFile);
      outFile << "]" << endl;
    }
  }

  // close the file
  outFile.close();
}

// auxiliary function for writeFile
void Graph::writeAux(int start, int curr, ofstream &outFile) {
  if (curr == start) {
    outFile << "[" << start;
    return;
  }
  else {
    writeAux(start, prev[curr], outFile);
    outFile << ", " << curr;
  }
}
