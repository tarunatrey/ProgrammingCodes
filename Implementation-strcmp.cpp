/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Implementation of strcmp
// Complexity : O(N+M), N and M are the lengths of the two strings
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int MyStrcmp(const char* pCharArr1, const char* pCharArr2)
{
    int iIndex;
    iIndex = 0;

    while(pCharArr1[iIndex] != '\0')
    {
        if(pCharArr2[iIndex] == '\0')
        {
            return 1;
        }
        else if(pCharArr1[iIndex] > pCharArr2[iIndex])
        {
            return 1;
        }
        else if(pCharArr1[iIndex] < pCharArr2[iIndex])
        {
            return -1;
        }
        iIndex++;
    }
    return 0;
}

int main()
{
    string strInput1,strInput2;
    cout<<"\n Enter first string : ";
    cin>>strInput1;   
    cout<<"\n Enter second string : ";
    cin>>strInput2;   
    
    if( MyStrcmp((strInput1).c_str(), (strInput2).c_str()) == 0)
    {
        cout<<"\n Two strings are same!";
    }
    else
    {
        cout<<"\n Two strings are different!";
    }
    cout<<"\n";
     
    return 0;
}
