/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : In a list of strings, print anagrams together
// Complexity : O(M + N logN) where M is max number of chars in one word and N is number of words
/////////////////////////////////

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Unused function
string SortStringChars(string strWord)
{
    int iLen;
    iLen = strWord.length();
    
    char cTemp;
    
    for(int i=0; i<iLen-1; i++)
    {
        for(int j=0; j<(iLen-i-1); j++)
        {
            if(strWord[j] > strWord[j+1])
            {
                cTemp = strWord[j];
                strWord[j] = strWord[j+1];
                strWord[j+1] = cTemp;
            }
        }
    }
    return strWord;
}

long int SumStringChars(string strWord)
{
    int iLen;
    iLen = strWord.length();

    long int iSum=0;

    for(int i=0; i<iLen; i++)
    {
        iSum = iSum + pow(2,(strWord[i]-'a'));
    }

    return iSum;
}

void PrintAnagramsTogether(string strArr[], int iNum)
{
    int* iArrIndexSorted;
    iArrIndexSorted = new int[iNum];

    long int* iArrStrSum;
    iArrStrSum = new long int[iNum];

    for(int i=0; i<iNum; i++)
    {
        iArrIndexSorted[i] = i;
        iArrStrSum[i] = SumStringChars(strArr[i]);
    }
    
    int iSumTemp; // for swapping
    int iTemp;

    for(int i=0; i<iNum-1; i++)
    {
        for(int j=0; j<iNum-i-1; j++)
        {
            if(iArrStrSum[j] > iArrStrSum[j+1])
            {
                iSumTemp = iArrStrSum[j];
                iArrStrSum[j] = iArrStrSum[j+1];
                iArrStrSum[j+1] = iSumTemp;

                iTemp = iArrIndexSorted[j];
                iArrIndexSorted[j] = iArrIndexSorted[j+1];
                iArrIndexSorted[j+1] = iTemp;              
            }
        }
    } 

    cout<<"\n Anagrams together:-";
    for(int i=0; i<iNum; i++)
    {
        cout<<"\n "<<strArr[iArrIndexSorted[i]];
    }
}

int main()
{
    string strArr[] = {"abc","feda","cab","arel","pos","bac","deaf","sop"};

    int N;
    N = sizeof(strArr)/sizeof(strArr[0]);

    cout<<"\n Original array of strings :-";            
    for(int i=0; i<N; i++)
    {
        cout<<"\n "<<strArr[i];
    }
    cout<<"\n";
    
    PrintAnagramsTogether(strArr,N);
    cout<<"\n";

    return 0;
}
