/*
Brandon Salazar
Professor Santosh
Summer 2020 
CSE 100
August 7th
Lab XI Minimum Spannig Tree
*/
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int findMin(vector <bool> MST, vector<int> result, int vertices){
    int min = INT_MAX;
    int vertex = 0;

    for(int i = 0; i < vertices; i++){
        if(MST.at(i) == false){
            if(min > result.at(i)){
                vertex = i;
                min = result.at(i);
            }//end second if statment
        }//end first if statement
    }//end the i loop

    return vertex;
}//end find min function

void MST(vector<vector<int> > weights, int vertices){
    vector <bool> MST;
    MST.resize(vertices);
    
    vector<int>result;
    result.resize(vertices);

    vector <int> parents;
    parents.resize(vertices);

    for(int i = 0; i < vertices; i++){
        MST.at(i) = false;
        result.at(i) = INT_MAX;
    }//end i loop

    result.at(0) = 0;
    parents.at(0) = 0;

    for(int i = 0; i < vertices; i++){
        int vertex1 = findMin(MST, result, vertices);
        MST[vertex1] = true;

        for(int j = 0; j < vertices; j++){
            if(MST.at(j) == false && weights[vertex1][j] < result.at(j) && weights[vertex1][j] != 0){
                parents.at(j) = vertex1;
                result.at(j) = weights[vertex1][j];
            }//END IF STATMENT
        }//END J LOOP
    }//END I LOOP

    for(int i = 1; i < vertices; i++){
        cout << parents[i] << endl;
    }// end i loop
}//end minimum spanning tree algorithm

int main(){
    int vertices, edges;

    cin >> vertices;
    cin >> edges;

    vector <vector<int>> weight;
    weight.resize(vertices);

    for(int i = 0; i < vertices; i++){
        weight[i].resize(vertices);
    }//end i loop

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            weight[i][j] = 0;
        }//end j loop
    }//end i  loop

    int ver1 = 0;
    int ver2 = 0;
    int heavyWeights = 0;

    for(int i = 0; i < edges; i++){
        cin >> ver1;
        cin >> ver2;
        cin >> heavyWeights;
        weight[ver1][ver2] = heavyWeights;
        weight[ver2][ver1] = heavyWeights;
    }

    MST(weight, vertices);
}//end main function
/*
Minimum Spanning Tree

Description

In the Minimum Spanning Tree problem, we are given as input an undirected
graph G = (V, E) together with weight w(u, v) on each edge (u, v) ∈ E. The goal is to find
a minimum spanning tree for G. Recall that we learned two algorithms, Kruskal’s and Prim’s
in class. In this assignment, you are asked to implement Prim’s algorithm. The following is a
pseudo-code of Prim’s algorithm.

Initialize a min-priority queue Q.
for all u ∈ V do
    u.key = ∞.
    u.π = NIL.
    Insert (Q, u).
end for
Decrease-key(Q, r, 0).
while Q 6 = ∅ do
    u = Extract-Min(Q).
    for all v ∈ Adj[u] do
        if v ∈ Q and w(u, v) < v.key then
            v.π = u.
            Decrease-Key(Q, v, w(u, v)).
        end if
    end for
end while

Input
The input is G, w, and r, where r is an arbitrary vertex the user can specify as root.
The input has the following format. There are two integers on the first line. The first integer
represents the number of vertices, |V |. The second integer is the number of edges, |E|. Vertices
are indexed by 0, 1, . . . , |V | − 1. Each of the following |E| lines has three integers u, v, w(u, v)
representing an edge (u, v) with weight w(u, v). Use vertex 0 as the root r.

Output
The above pseudo-code stores the MST by π, where v.π = u means that u is v’s
unique parent; here, r.π = NIL since r has no parent. Output the MST by outputting the π
value of a vertex in each line, in the order 1, 2, . . . , |V | − 1. (Do not output the root’s parent.)

Implementation Issues
Prim’s algorithm requires a min-priority queue that supports the
DecreaseKey operation which is not supported by the standard C++ priority queue. You are
allowed to use an “inefficient” priority queue that supports each operation in O(|V |) time. Suchan inefficient priority queue can be easily implemented using an array. Then, the running time
of your implementation is roughly O(|E||V |). However, you may still use the C++ priority
queue with a simple “invalidation trick” and have your code to run in O(|E| log |V |). Instead of
decreasing an element’s key, just mark the element as invalid and push a new (valid) element with
the new key value to the queue. Then you just have to be careful when extracting a minimum
element because what you really want is a minimum element that is valid. So extracting a valid
min element could take a few iterations. However, at any point in time, the priority queue has
at most O(|E|) elements, so each ExtractMin operation takes O(log |E|) = O(log |V |) time.
Since you extract minimum elements at most O(|E|) times, you only need O(|E| log |V |) time
for extracting valid min elements. To use invalidation trick, you just need to maintain a boolean
variable for each vertex to track if it is included in the current MST: when you extract a vertex
from the min priority queue, it is valid only if it is not yet part of the current MST.

Example of input and output

Input

9
14
0 1 40
0 7 85
1 2 80
1 7 110
2 3 70
2 5 45
2 8 22
3 4 90
3 5 140
4 5 100
5 6 25
6 7 10
6 8 60
7 8 75

(The input is a graph with weights given per edge.)

Output

0
1
2
3
2
5
6
2

Here, the first number refers to the parent of vertex 1, and the second number to the parent of
vertex 2, and so on. Note that every line is followed by an enter key.











*/