/*
Brandon Salazar
Professor Santosh
Summer 2020 
CSE 100
August 9th
Lab XII The Bellman-Ford Algorithm
*/
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
  int vertices; // no. of vertices
  int edges; // no. of edges
  
  cin >> vertices;
  cin >> edges;
  
  int** W = new int*[vertices];
  
  for(int i = 0; i < vertices; i++)
     W[i] = new int[vertices];

  vector<int>* G = new vector<int>[vertices];
  
  for(int i = 0; i < edges; i++){
    int u;
    int v;
    int w;
    
    cin >> u;
    cin >> v;
    cin >> w;
    
    W[u][v] = w;
    G[u].push_back(v);
  }//end i loop

  // INITIALIZE-SINGLE -SOURCE
  int* dist = new int[vertices];

  for(int i = 0; i < vertices; i++)
    dist[i] = INT_MAX;
  
  dist[0] = 0;
  
  for(int i = 0; i < vertices-1; i++){
    for(int u = 0; u < vertices; u++){
      for(int v : G[u]){
        if(dist[u] != INT_MAX && dist[v] > dist[u] + W[u][v]){
          dist[v] = dist[u] + W[u][v];
        }//end if
      }//end v loop
    }//end u loop
  }// end i loop

  for(int u = 0; u < vertices; u++){
    for(int v : G[u]){
    if (dist[u] != INT_MAX && dist[v] > dist[u] + W[u][v]){
        cout << "FALSE" << endl;
        return 0;
      }//end if statement
    }// end v loop
  }//end u loop

  cout << "TRUE" << endl;

  // print out array 'dist'
  for(int i = 0; i < vertices; i++){
    if(dist[i] == INT_MAX){
      cout << "INFINITY" << endl;
    }
    else{
      cout << dist[i] << endl;
    }//end if else
  }//end i loop
}//end main function

/*
The Bellman-Ford Algorithm

In this assignment, you are asked to implement the Bellman-Ford Algorithm which solves the
single-source shortest-paths problem. Specifically, you are given as input a directed graph G =
(V, E) with weight w(u, v) on each edge (u, v) ∈ E along with a source vertex s ∈ V . Edges may
have negative weights.

Input
The input has the following format. There are two integers on the first line. The
first integer represents the number of vertices, |V |. The second integer is the number of edges,
|E|. Vertices are indexed by 0, 1, . . . , |V | − 1. Each of the following |E| lines has three integers
u, v, w(u, v) , which represent an edge (u, v) with weight w(u, v). Vertex 0 is the source vertex.

Output
The output falls into two possible cases.
Case (i): There is no negative-weight cycle reachable from s. In this case, you must output
TRUE on the first line, followed by the shortest distance from s to each vertex in the graph.
More precisely, you must output TRUE, δ(0, 0), δ(0, 1), . . . , δ(0, |V | − 1), one per line. Recall
that δ(u, v) denotes the shortest distance from u to v. If a vertex v is not reachable, output
INFINITY in place of δ(0, v).
Case (ii): There is a negative-weight cycle reachable from s. You must output FALSE.

Examples of Input and Output

Input 1
6 10
0 1 6
1 2 5
1 3 -4
1 4 8
2 1 -2
3 0 2
3 2 7
3 4 9
4 0 7
5 2 5

Output 1
TRUE
0
6
9
2
11
INFINITY

Input 2
6 11
0 1 6
1 2 5
1 3 -4
1 4 8
2 1 -2
3 0 2
3 2 7
3 4 9
3 5 -14
4 0 7
5 2 5

Output 2
FALSE

Note that every line is followed by an enter key.
*/