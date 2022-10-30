/*
Brandon Salazar
Professor Santosh
Summer 20202 CSE 100
July 24th
Lab VII Dynamic Programming: Rod Cutting
*/
#include <iostream>
#include <climits>

using namespace std;

int max(int a, int b) { return (a > b)? a : b;} //borrowed utility

// int MemoizedCutRodAux(int p[], int n, int r[], int s[]){
//     // int q;
//     // int s[n];

//     // if(r[n] >= 0)
//     //     return r[n];
    
//     // if(n == 0){
//     //     q = 0;
//     // }else{
//     //     q = INT_MIN;                                   
//     //     for(int i = 1; i <= n; i++){
//     //         q = FindMax(q, p[i] + MemoizedCutRodAux(p, (n-i), r)); ///need to figure out max
//     //         s[i] =  i;
//     //     }
//     // }
//     // r[n] = q;
//     // return q;// and s;
//     int q;
//     if(r[n] > 0){ return r[n]; }
//     if(n == 0) { q = 0; }
//     else{
//         q = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             int val = MemoizedCutRodAux(p,n-i-1,r,s);
//             if(q < (p[i] + val)){
//                 q = p[i] + val;
//                 s[n] = i;
//             }
//         }
//     }
//     r[n] = q;
//     return q;
// // }
// }//end Memoized Cut Rod Aux Function

// int MemoizedCutRod(int p[], int n){
//     // int r[n];
    
//     // for(int i = 0; i<=n; i++)
//     //     r[i] = INT_MIN;
//     // return MemoizedCutRodAux(p, n, r);

//     int r[n+1];
//     int s[n+1];
    
//     for(int i = 0; i < n+1; i++)
//     {
//         r[i] = INT_MIN;
//     }
//     int val = MemoizedCutRodAux(p,n,r,s);
//     int j = n;
//     while (j > 0){
//         cout << s[j];
//         j = j - s[n];
//     }
// }//end memoized rod cutting function

void PrintCutRodSolution(int s[], int n, int r[]){
    int i = n-1;

    while(i > 0){
        cout<<r[s[i]]<<"\n"<< "cut(s) : "<<s[i]<<endl;//cout << s[n];
        i = i - s[n-1];//n = n - s[n];
    }
}//end of the print function

int ExtendedBottomUpCutRod(int p[], int n, int r[], int s[]){
    int q;
    r[0] = 0;
    s[0] = 0;
    
    for(int j = 1; j < (n+1); j++)
    {
        q = INT_MIN;
        
        for(int i = 0; i < j; i++)
        {
            if(q < (p[i] + r[j-i-1]))
            {
                q = p[i] + r[j-i -1];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return q;// and s;
}//end of function



int main(){
    int n;
    cin >> n;

    int rodPrize[n];
    int size[n];
    int rev[n];

    for(int i = 0; i < n; i++)
         cin >> rodPrize[i];

    int value = ExtendedBottomUpCutRod(rodPrize, n, rev, size);

    PrintCutRodSolution(size, n, rev);
}//end of main function 

/*
Dynamic Programming: Rod Cutting

Description In this assignment you are asked to implement a dynamic programming algorithm
for the Rod Cutting Problem (chapter 15.1). In the Rod Cutting problem, you are given an
integer n ≥ 1, along with a sequence of positive prices, p 1 , p 2 , ..., p n , where p i is the market price
of a rod of length i. The goal is to figure out a best way of cutting the given rod of length n
to generate the maximum revenue. You can assume that the given prices p 1 , p 2 , ..., p n are all
integers.

Input 
The input has the following format. The input starts with n. Then, p 1 , p 2 , ..., p n follow,
one per each line.

Output I
n the first line, output the maximum revenue (r n ), followed by an enter key. In the
second line, sequentially output the length of each piece in your optimal cutting, followed by a
space key. The second line must end by -1 and an enter key.
Examples of input and output

Input
7
1
5
8
9
10
17
17

Output
18
1 6 -1

   The following is the output with white characters shown.
18(enter)
1(space)6(space)-1(enter)

Alternatively, the second line can be replaced with “6 1 -1”, “2 2 3 -1”, “2 3 2 -1”, or “3 2
2 -1”. That is, any sequence of piece lengths giving the maximum revenue will be considered to
be correct.
See the lab guidelines for submission/grading, etc., which can be found in Files/Labs.*/

