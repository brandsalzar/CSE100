/*
Brandon Salazar
Professor Santosh
CSE 100 Summer 2020
June 26th
Lab 1 Insertion Sort
*/ 

#include <iostream>

using namespace std;

int main(int argc, char**argv){
    int* Sequence;
    int arraySize = 1;

    // Get the size of elements
    cin >> arraySize;
    Sequence = new int[arraySize];
    
    // Read the sequence
    for(int i=0; i<arraySize; i++)
        cin >> Sequence[i];

    // Insertion Sort algorithm implementation
    for(int i = 1; i < arraySize; i++){
        int key = Sequence[i];
        int j = i - 1;
        
        while(j >= 0 && Sequence[j] > key){
            Sequence[j+1] = Sequence[j]; 
            j = j - 1;
        }//end while loop

        Sequence[j+1] = key; 

        if(i >= 1){                         //Checks if i is greater than the value of 1
            for (int k = 0; k <= i; k++){  
                cout << Sequence[k] << ";";  
            }//end second for loop
            cout << endl;
        }//end if statement
    }//end first for loop 
    delete[] Sequence;// Free allocated space
}//end of function

//Lab Completed on June 27th, 2020 at 18:55hrs.