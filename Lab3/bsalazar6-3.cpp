/*
Brandon Salazar
Professor Santosh
CSE 100 Summer 2020
July 6th
Lab III Solving the Max Subarray Problem via Divide-and-Conquer
*/

#include<iostream>

using namespace std;

int findMaxCrossingSubarray(int A[], int low, int mid, int high){
    //pseudocode
    int lSum = -32768; // holds the gratest sum so far on the left subarray
    int sum = 0; //holds the sum of the entries
    int maxL;
    for(int i = mid; i >= low; i--){
        sum += A[i];    //finding a maximun value of a subarray  on the left half
        if(sum > lSum){//instance where we check to find a subarray with a greater sum 
            lSum = sum; //we set the left sum to the value of the current sum if the if statement hodls true
            //maxL = i;   // Max left records the index i where the nex max was found
        }//end if statment that checks
    }//end first for loop 

    int rSum = -32768; //holds the greatest sum on the right subarray so far
    sum = 0;
    int maxR;
    for(int j = (mid + 1); j <= high; j++){
        sum += A[j];
        if(sum > rSum){
            rSum = sum;
           // maxR = j;
        }//end if statement
    }//end second for loop
    int tSum = (lSum + rSum);

    return tSum; //idk about this line either
}//end function

int findMaxSubarray(int subArr[], int low, int high){
    //pseudocode
    if(high == low)// base case that checks if the subarray being passed is of one element
        return subArr[low];//returning that subarray of one element with it's value
    else{//DIVIDE
        int mid = (low + high)/2; //computing the division of the array into two subarrayas left and right
        //CONQUER
        int lSum = findMaxSubarray(subArr, low, mid);// lLow, lHigh, lSum = findMaxSubarray(subArr[mid], low, mid);
        int rSum = findMaxSubarray(subArr, (mid + 1), high);// rLow, rHigh, rSum = findMaxSubarray(subArr[mid + 1], (mid + 1), high);
        int cSum = findMaxCrossingSubarray(subArr,low, mid, high);// cLow, cHigh, cSum = findMaxCrossingSubarray(subArr,low, mid, high);
        //COMBINE
        // if(lSum > rSum && lSum >cSum){
            // return lSum;
        // }
        // else if(rSum >cSum){
            // return rSum;
            // }
            // else{
                // return cSum;
            // }
        if(lSum >= rSum && lSum >= cSum)
            return lSum;
        else
            if(rSum >= lSum && rSum >= cSum)
                return rSum;
            else
                return cSum;
    }//end last else statement
}//end function

int main(){
    int arrSize;    //initializing the size of the array
    cin >> arrSize;
    int maxSubarr[arrSize];

    for(int i = 0; i < arrSize; i++){
        cin >> maxSubarr[i];
    }//end for loop that takes in the values of the subarray

    int sumArr = findMaxSubarray(maxSubarr, 0, arrSize-1);//what if you need arrSize-1
    cout << sumArr;
}//end main function
//Lab completed on 07/07/2020 @ 1107 hours 