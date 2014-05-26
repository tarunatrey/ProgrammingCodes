/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Reverse words in a string
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

string ReverseWordsString(string strInput)
{
    int iLen;
    iLen = strInput.length();

    //Step 1 : reverse the whole string
    strInput = ReverseString(strInput);

    //Step 2 : reverse each word in the string depending on space positions
    string strOutput,strTemp;
    strOutput = "";
    for(int i=0; i<iLen; i++)
    {
        strTemp = "";
    
        while(strInput[i]!=' ' && i!=iLen)
        {
            strTemp = strTemp + strInput[i];
            i++;
        }

        strTemp = ReverseString(strTemp);
        if(i != iLen)
        {
            strTemp = strTemp + " ";
        }

        strOutput = strOutput + strTemp;
    }

    return strOutput;
}

int main()
{
    string strInput, strOutput;
    int iLen;

    cout<<"\n Enter the string : ";
    getline(cin,strInput);

    strOutput=ReverseWordsString(strInput);
    
    cout<<"\n Reversed words in string : ";
    cout<<strOutput;
    cout<<"\n";

    return 0;
}
