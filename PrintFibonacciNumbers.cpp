/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Given X, print first X numbers in Fibonacci series  
// Complexity : O(N)
/////////////////////////////////

#include <iostream>

using namespace std;

void PrintFibonacciNumbers(int iNum)
{
    long int iNum1, iNum2, iTemp;
    iNum1 = 0;
    iNum2 = 1;   

    if(iNum == 0)
    {
        return;
    }
    
    cout<<iNum1;
    if(iNum == 1)
    {
        return;    
    }
    
    cout<<" "<<iNum2;
    if(iNum == 2)
    {
        return;
    }
    iNum = iNum-2;
    while(iNum > 0)
    {
        iTemp = iNum1 + iNum2;
        iNum1 = iNum2;
        iNum2 = iTemp;
        cout<<" "<<iNum2;
        iNum--;
    }
}

int main()
{
    int iNum;

    cout<<"\n Enter the no of Fibonacci numbers you want to print : ";
    cin>>iNum;
    
    cout<<"\n Fibonacci series : ";
    PrintFibonacciNumbers(iNum);
    cout<<"\n";    

    return 0;
}
