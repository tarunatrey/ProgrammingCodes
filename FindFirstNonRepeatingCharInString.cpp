/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Given a string, find first non-repeating char
// Complexity : O(N)
/////////////////////////////////

#include <iostream>
#include <string>
#include <map>

using namespace std;

int FindFirstNonRepeatingChar(string strInput)
{
    int iLen;
    iLen = strInput.length();

    map <char, int> mapCharCount;

    for(int i=0; i<iLen; i++)
    {
        if(mapCharCount.count(strInput[i]))
        {
            mapCharCount[strInput[i]]++;
        }
        else
        {
            mapCharCount[strInput[i]] = 1;
        }
    }

    for(int i=0; i<iLen; i++)
    {
        if(mapCharCount[strInput[i]] == 1)
        {
            return i;
        }     
    }
    return -1;
}

int main()
{
    string strInput;
    
    cout<<"\n Enter the string : ";
    cin>>strInput;

    int iResultIndex;
    iResultIndex = FindFirstNonRepeatingChar(strInput);

    if(iResultIndex != -1)
    {
        cout<<"\n First non-repeating character : "<<strInput[iResultIndex];
    }
    else
    {
        cout<<"\n There is no non-repeating character in the string!";
    }
    cout<<"\n";

    return 0;
}
