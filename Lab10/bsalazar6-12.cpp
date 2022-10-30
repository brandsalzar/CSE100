/*
Brandon Salazar
Professor Santosh
Summer 2020 
CSE 100
August 5th
Lab X Strongly Connected Components
*/
#include <iostream>
#include <climits> 
#include <vector>
#include <stack>

using namespace std;

int *print;
stack<int> DFS;

struct Graph{
  int vertex, min, edges;
  vector<int> *edgeArr;

  Graph(int vertex, int edges);

  void SCC(bool * arr);
  void edgeCreate(int a, int b);
  void DFSTrav(int vertex, bool arr[]);
  void visit(int edge, bool arr[], stack<int> &Stack);

  Graph graphTranspose();
};//end struct for graphs

Graph::Graph(int vertex, int edges){
  this->edges = edges;
  this->vertex = vertex;

  min = INT_MAX;
  print = new int[vertex];
  edgeArr = new vector<int>[edges];
}//end graph

void Graph::DFSTrav(int vertex, bool arr[]){
  DFS.push(vertex);

  if(vertex < this->min)
      this->min = vertex;

  arr[vertex] = true;

  for (vector<int>::iterator i = edgeArr[vertex].begin(); i != edgeArr[vertex].end(); ++i){
    if (arr[*i] == false)
        DFSTrav(*i, arr);
  }//end i loop
}//End Traversal of DFS

Graph Graph::graphTranspose(){
  Graph graph(vertex, edges);

  for (int j = 0; j < edges; j++){
    for(vector<int>::iterator i = edgeArr[j].begin(); i != edgeArr[j].end(); ++i){
        graph.edgeArr[*i].push_back(j);
    }//end j loop
  }//end i loop

    return graph;
}//end of GraphTranspose

void Graph::edgeCreate(int a, int b){
  edgeArr[a].push_back(b);
}//end edge Creator

void Graph::visit(int edge, bool arr[], stack<int> &Stack){
  arr[edge] = true;

  for(vector<int>::iterator i = edgeArr[edge].begin(); i != edgeArr[edge].end(); ++i)
    if(!arr[*i]){
          visit(*i, arr, Stack);
    }//end i loop

    Stack.push(edge);
}//end visit

void Graph::SCC(bool *arr){
  stack<int> stackPrinter;

  for(int i = 0; i < edges; i++){
      if(arr[i] == false)
          visit(i, arr, stackPrinter);
  }//end i loop

  Graph tranGraph = graphTranspose();

  for(int i = 0; i < edges; i++){
    arr[i] = false;
  }//end i  loop

  for(int i = stackPrinter.size(); i > 0;i--){
    int vertex = stackPrinter.top();
    stackPrinter.pop();

    if (arr[vertex] == false)
      tranGraph.DFSTrav(vertex, arr);
    
    while (DFS.empty()==false) {
      int vertex = DFS.top();
      DFS.pop();
      print[vertex] = tranGraph.min;
    }//end while loop
    
      tranGraph.min = 100000;
  }//end i loop
}//end SCC

int main(){
  int a, b;
  int vertex, edges;

  cin >> edges;
  cin >> vertex;
  
  Graph graph(vertex, edges);

  for(int i = 0; i < vertex; i++){
    cin >> a;
    cin >> b;
    graph.edgeCreate(a, b);
  }

  bool *goToArr = new bool[edges];

  for(int i = 0; i < edges; i++){
    goToArr[i] = false;
  }

  graph.SCC(goToArr);

  for(int i = 0; i < edges; i++){
    cout << *(print+i) << endl;
  }
}//end of main function
/*
Strongly Connected Components

Description
A strongly connected component (SCC) of a directed graph G = (V, E) is defined as a
maximal set of vertices C ⊆ V such that for every pair of vertices u and v in C, the two vertices are
reachable from each other. In this lab assignment, you are asked to decompose a given directed graph
G = (V, E) into a collection of SCCs.

Input
The input will have the following format. The first integer refers to the number of vertices,
|V |. The second integer is the number of edges, |E|. Vertices are indexed by 0, 1, ..., |V | − 1. Then,
two numbers u v appearing in each line means an edge (u, v). See the example given below.

Output
Output the SCC ID of every vertex. A SCC’s ID is defined as the smallest index of any
vertex in the SCC. In other words, you have to output, for each vertex v, the ID of the unique SCC the
vertex v belongs to. You must output the ID for each vertex, considering vertices in the order of 0, 1,
..., |V | − 1.

Examples of Input and Output

Input

8
13
0 1
1 2
1 4
1 5
2 3
2 6
3 2
3 7
4 0
4 5
5 6
6 5
6 7

Ouput for problem 2

0
0
2
2
0
5
5
7

What this answer implies is that the graph is decomposed into four SCCs, {0, 1, 4}, {2, 3}, {5, 6}, {7}.
Note that all vertices in the same SCC have the same label, which is equal to the smallest index of all
vertices in the same component. For example, vertices 0,1 and 4 are all labeled with 0
*/