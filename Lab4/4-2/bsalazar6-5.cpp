/*
Brandon Salazar
Professor Santosh
CSE 100 Summer 2020
July 7th
Lab IV-II Quick-Sort
*/

#include<iostream>

using namespace std;

int Partition(int arr[], int p, int r){
    int x = arr[r];
    int i = (p - 1);

    for(int j = p; j <= (r - 1); j++){
        if(arr[j] <  x){
            i += 1;
            swap(arr[i], arr[j]); 
        } 
    }

    swap(arr[i+1], arr[r]);
    return (i+1); 
}

int QuickSort(int arr[], int p, int r){
    if(p<r){
        int q = Partition(arr, p, r);
        QuickSort(arr, p, (q - 1));
        QuickSort(arr, (q + 1), r );
    } 
}

int main(){
    int arrSize;    //Decalring a variable to store the size of the array
    cin >> arrSize; // Taking the input for the size of the array

    int quickArr[arrSize];  //Declaring an array and passing arrSize as its size

    for(int i= 0; i < arrSize; i++) //for loop taht takes in the values of the array
        cin >>  quickArr[i];

    QuickSort(quickArr, 0, arrSize-1);

    for(int j = 0; j < arrSize; j++)
        cout <<  quickArr[j] << ";" ;

}//end main function

/*Lab Completed on 07/12/2020 @ 1542 hours*/

/*
Quick-Sort

Description This is the second half of Lab04 and is worth 50 points. In this lab 
assignment (Lab04-2), your job is to implement the randomized version of Quick-sort.
That is, you must choose a random pivot from the elements in A[p...r] when 
partitioning the subarray. For more  details, see page 179 of the textbook. The 
following webpage describes a simple way to obtain a random integer: 
http://www.cplusplus.com/reference/cstdlib/rand/

Input structure The input starts with an integer number which indicates the number of
elements (integers) to be sorted, n. Then, the elements follow, one per line.
Output structure Output the elements in non-decreasing order. Each element must be fol-
lowed by ;.

Examples of input and output:

Input
6
5
3
2
1
6
4
Output
1;2;3;4;5;6;

Note that the output is only one line and has no white characters.
See the lab guidelines for submission/grading, etc., which can be found in 
Files/Labs.
*/