/*
Brandon Salazar
Professor Santosh
Summer 2020 
CSE 100
July 28
Lab VIII Dynamic Programming: Matrix Chain Multiplication
*/
#include <iostream>
#include <stdio.h>
#include <climits> 

using namespace std; 

void printOptimalParenthesis( int *s, int i, int j, int n){ 
	if (i == j){ 	
        char mtrx = 'A';
        cout << mtrx << (i-1) ; 
		return; 
	} 

	cout << "(";  
	printOptimalParenthesis(s, i, *((s+i*n)+j), n); 
	printOptimalParenthesis(s, *((s+i*n)+j) + 1, j, n); 
	cout << ")"; 
} 

void matrixChainOrder(int *p, int n){ 

	int m[n][n]; 
    int s[n-1][n]; 

	for(int i = 1; i < n; i++) 
		m[i][i] = 0; 

	for(int l = 2; l < n; l++){ 
		for(int i = 1; i < (n - l + 1); i++){ 
			int j = (i + l - 1); 
			m[i][j] = INT_MAX; 
			for(int k = i; k <= (j - 1); k++){ 
				int q = m[i][k] + m[k+1][j] + *(p + i-1) * *(p+k) * *(p+j);// (*p +(i-1)) * (*p+k) * (*p+j);
				if (q < m[i][j]){ 
					m[i][j] = q; 
					s[i][j] = k; 
				}//k loop
			} // i loop
		}// l loop
	}//end function 

	cout << m[1][n-1] << endl; 
	printOptimalParenthesis((int *)s, 1, n-1, n);
} 

int main(){ 
    int mtrxs;
    cin >> mtrxs;

    //int *arr= NULL;
    //arr = new int [mtrxs+1];

   int arr[mtrxs + 1];
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < (mtrxs+1); i++){
        cin >> arr[i];
    }//end i loop

	matrixChainOrder((int *)arr, n);
    printf("\n"); 

    //delete [] arr;
    //arr = NULL;
} 

/*
Dynamic Programming: Matrix Chain Multiplication

Description In this assignment you are asked to implement a dynamic programming algorithm
for the matrix chain multiplication problem (chapter 15.2), where the goal is to find the most
computationally efficient matrix order when multiplying an arbitrary number of matrices in a
row. You can assume that the entire input will be given as integers that can be stored using the
standard C++ int type and that matrix sizes will be at least 1.

Input The input has the following format. The first number, n ≥ 1, in the test case will tell
you how many matrices are in the sequence. The first number will be then followed by n + 1
numbers indicating the size of the dimensions of the matrices. Recall that the given information
is enough to fully specify the dimensions of the matrices to be multiplied.

Output First, you need to output the minimum number of scalar multiplications needed to
multiply the given matrices. Then, print the matrix multiplication sequence, via parentheses,
that minimizes the total number of number multiplications. Each matrix should be named A#,
where # is the matrix number starting at 0 (zero) and ending at n − 1. See the examples below.

Examples of input and output

2
2 3 5
30
(A0A1)
3
10 100 5 50
7500
((A0A1)A2)
3
10 30 5 60
4500
((A0A1)A2)
6
30 35 15 5 10 20 25
15125
((A0(A1A2))((A3A4)A5))

See the lab guidelines for submission/grading, etc., which can be found in Files/Labs.
*/