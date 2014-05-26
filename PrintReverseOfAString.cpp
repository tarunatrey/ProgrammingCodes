/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Reverse a string
// Complexity : O(N)
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

string ReverseString(string strInput)
{
    int iLen;
    iLen = strInput.length();
    
    char cTemp;
    for(int i=0; i<iLen/2; i++)
    {
        cTemp = strInput[i];
        strInput[i] = strInput[iLen-i-1];
        strInput[iLen-i-1] = cTemp;
    }

    return strInput;
}

int main()
{
    string strInput, strOutput;
    int iLen;

    cout<<"\n Enter the string : ";
    getline(cin,strInput);

    strOutput=ReverseString(strInput);
    
    cout<<"\n Reversed string : ";
    cout<<strOutput;
    cout<<"\n";

    return 0;
}
