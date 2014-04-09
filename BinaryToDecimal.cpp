/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Convert binary representation to decimal value 
// Complexity : O(N) where N is number of digits in binary representation 
/////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

int BinaryToDecimal(long long int iNum)
{
    int iSum, iCount;
    iSum = 0;
    iCount = 0;

    while(iNum != 0)
    {
        iSum = iSum + (iNum%10) * pow(2,iCount);
        iNum = iNum/10;
        iCount++;
    }
    return iSum;
}

int main()
{
    long long int iNum;
    cout<<"\n Enter binary representation : ";
    cin>>iNum;
    
    cout<<"\n Decimal value : "<<BinaryToDecimal(iNum)<<"\n";
    
    return 0;
}
