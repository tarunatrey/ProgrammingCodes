/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Implementation of atoi
// Complexity : O(N), N is the length of the char array
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int MyAtoI(const char* pCharArr)
{
    int iIndex, iSign, iSum;

    iIndex = 0;     //Keep track of pointer in the string
    iSign = 1;      //Keep track of -ve sign in the number (if present)
    iSum = 0;       //Keep track of the sum
    
    if(pCharArr[0] == '-')
    {
        iSign = -1;
        iIndex++;
    }

    while(pCharArr[iIndex] != '\0')
    {
        iSum = iSum * 10 + (int) (pCharArr[iIndex] - '0');
        iIndex++;
    }

    return (iSign * iSum);
}

int main()
{
    string strInput;
    cout<<"\n Enter the string : ";
    cin>>strInput;   
    cout<<"\nAtoI output for '"<<strInput<<"' : "<<MyAtoI((strInput).c_str())<<"\n";
     
    return 0;
}
