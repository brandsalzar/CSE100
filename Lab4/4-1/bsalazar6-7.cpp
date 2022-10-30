/*
Brandon Salazar
Professor Santosh
CSE 100 Summer 2020
July 7th
Lab IV-I Heap-Sort
*/

#include<iostream> 

using namespace std;

int maxHeapify(int arr[], int i, int arrSize){
    int l = (2*i) + 1; // largest  A[Left(i)]
    int r = (2*i) + 2; //largest A[Right(i)]; might need an additional function for both sides
    int largest = i;

    if(l < arrSize && arr[l] > arr[largest])
        largest = l;
    if(r < arrSize && arr[r] > arr[largest])
        largest = r;
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, arrSize);
    }  
}//end maxHeapify 

void buildMaxHeap(int arr[], int arrSize){
    for(int i = arrSize/2-1; i >= 0; i--)
        maxHeapify(arr, i, arrSize);
}//end function 

int heapsort(int arr[], int arrSize){
    buildMaxHeap(arr, arrSize);
    for(int i = arrSize-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}//end Heapsort Algorithm

int main(){
    int arrSize;
    cin >> arrSize;
    
    int arrHeap[arrSize];

    for(int i = 0; i < arrSize; i++){
        cin >> arrHeap[i];
    }//end for loop filling the array
    
    heapsort(arrHeap, arrSize);
    
    for(int j = 0; j < arrSize; j++){
        cout << arrHeap[j] <<";";
  }
}//end main function

/*Lab Completed on 07/12/2020 @ 1456 hours*/

/*
Heap-Sort
Description In this lab assignment (lab 04-1), your job is to implement heap-sort. 
This is the first half of lab 04 and is worth 50 points.

Input structure The input starts with an integer number which indicates the number 
of elements (integers) to be sorted, n. Then, the elements follow, one per line.
Output the elements in non-decreasing order. Each element must be followed by ;.

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

Note that the output has only one line and has no white characters.
See the lab guidelines for submission/grading, etc., which can be found in Files/Labs.
*/