#include "graph.h"

int main() {
  srand(time(0));
  ifstream myFile;

  string filename, line;
  int arraySize, from, to, weight;

  // get file name
  cout << "Enter name of graph file: ";
  cin >> filename;

  myFile.open(filename);

  myFile >> arraySize;
  Graph g(arraySize);

  // read from the file
  while (!myFile.eof()){
    myFile >> from >> to >> weight;
    g.insertEdge(from, to, weight);
  }
  myFile.close();

  int startVertex;

  // get the starting vertex
  cout << "Enter a valid vertex id for the starting vertext: ";
  cin >> startVertex;

  // set the timer
  auto start = high_resolution_clock::now();
  g.dijkstra(startVertex);
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);
  cout << "Total time (in seconds) to apply Dijkstra's algorithm: ";
  cout << duration.count() << " seconds" << endl;

  // write the file
  g.writeFile(startVertex);

  return 0;
}
