/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Find longest palindromic substring in a given string
// Complexity : O(N^2) time, O(1) space
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

string LongestPalindromicSubstring(string strInput)
{
    int iLen;
    iLen = strInput.length();

    int iOutputStartIndex, iOutputLen;
    iOutputStartIndex = 0;
    iOutputLen = 1;
    
    int iMinIndex, iMaxIndex;
    
    for(int i=1; i<iLen; i++)
    {
        //Find longest even length with i-1 and i as center points
        iMinIndex = i-1;
        iMaxIndex = i;
        
        while( iMinIndex>=0 && iMaxIndex<iLen && strInput[iMinIndex]==strInput[iMaxIndex] )
        {
            if( iMaxIndex-iMinIndex+1 > iOutputLen )
            {
                iOutputLen = iMaxIndex-iMinIndex+1;
                iOutputStartIndex = iMinIndex;
            }
            iMinIndex--;
            iMaxIndex++;
        }
    

        //Find longest odd length with i as center point
        iMinIndex = i-1;
        iMaxIndex = i+1;
        
        while( iMinIndex>=0 && iMaxIndex<iLen && strInput[iMinIndex]==strInput[iMaxIndex] )
        {
            if( iMaxIndex-iMinIndex+1 > iOutputLen )
            {
                iOutputLen = iMaxIndex-iMinIndex+1;
                iOutputStartIndex = iMinIndex;
            }
            iMinIndex--;
            iMaxIndex++;
        }
    }

    string strOutput="";

    for(int i=0; i<iOutputLen; i++)
    {
        strOutput += strInput[iOutputStartIndex++];
        
    }
    return strOutput;
}

int main()
{
    string strInput, strOutput;
    int iLen;

    cout<<"\n Enter the string : ";
    getline(cin,strInput);

    strOutput = LongestPalindromicSubstring(strInput);
    
    cout<<"\n Longest palindromic substring : ";
    cout<<strOutput;
    cout<<"\n";

    return 0;
}
