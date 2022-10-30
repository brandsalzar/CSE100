/*
Brandon Salazar
Professor Santosh
CSE 100 Summer 2020
June 26th
Lab II Merge-Sort
*/

#include <iostream>

using namespace std;

//Merging function that is called from mergeSort()
void merge(int arrSize[], int left, int mid, int right){
    int sectOne = mid - left + 1; //first index position in both subarrays
    int sectTwo = right - mid;

    int i;
    int j;
    int pos;

    int subArrL[sectOne];//subarray 1
    int subArrR[sectTwo];//subarray 2 

    for( i = 0; i < sectOne; i++){
      subArrL[i] = arrSize[left + i];
    }//Creating a copy from the left side of the array
    
    for( j = 0; j < sectTwo; j++){
      subArrR[j] = arrSize[mid + 1 + j];
    }//creating a copy for the Right side of the array.

    i = 0;//first index of left subarray
    j = 0;//first index of right subarray
    pos = left;//first index in sorted array

//Loop traverses the arrays while we haven't reached the end of both subarrays
    while(i != sectOne && j != sectTwo){
      if(subArrL[i] <= subArrR[j]){//instance when position in the left array is smaller and we insert
        arrSize[pos] = subArrL[i];
        i++;//moving through the left subarray
      }//end condition
      else{//first if implies right side is smaller, so insert it
        arrSize[pos] = subArrR[j];
        j++;//moving through the right subarray
      }//end second condition
      pos++;//moving through the merged array after an insertion either in the left or right subarray
    }//end while loop

//segmentation fault that accounts for the reaminder of either side(instance when the array cannot be split in two equal sides)
    while(i < sectOne){
      arrSize[pos]= subArrL[i];
      i++;
      pos++;
    }///end first while loop
    while(j < sectTwo){//clearing right side
      arrSize[pos] = subArrR[j];
      j++;
      pos++;
    }//end second while loop
}//end of merge function

//Begining od the implementation of the algorithm MergeSort
void mergeSort(int arrSize[], int left, int right){
  
    if(left < right){//instance of when it complies and it is returned
        int mid = left +(right - left)/2;
        mergeSort(arrSize, left, mid);//call to sort the left side of the array
        mergeSort(arrSize, mid + 1, right);//call to sort the right side of the array
        merge(arrSize, left, mid, right);//function call to merge when it is sorted size 1
    }//end if statement
}//end of function mergesort        

int main(){
    //Get the size of the input that will be use for the number of elements
    int arrSize;
    cin >> arrSize;
    int unsortedList[arrSize];

    //Get the value of the elements to be placed in unsortedList
    for(int i = 0; i < arrSize; i++){
        cin >> unsortedList[i];
    }//end of for loop

    mergeSort(unsortedList, 0, arrSize - 1);

    //output of the code
    for(int i = 0; i < arrSize; i++)
        cout << unsortedList[i] << ";";
}//end main function