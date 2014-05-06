/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Check if an input string by user is a palindrome
// Complexity : O(N), check each element once
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

//Using "string" class functions
bool CheckIfStringIsPalindrome1(string strInput)
{
    if(strInput == string(strInput.rbegin(), strInput.rend()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Writing your own palindrome logic
bool CheckIfStringIsPalindrome2(string strInput)
{
    int iLength;
    iLength = strInput.length();

    for(int i=0; i<iLength/2; i++)
    {
        if(strInput[i] != strInput[iLength-i-1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string strInput;

    cout<<"\n Enter the input string : ";
    cin>>strInput;
    
    if(CheckIfStringIsPalindrome2(strInput))
    {
        cout<<"\n Input string is a palindrome!\n";
    }
    else
    {
        cout<<"\n Input string is not a palindrome!\n";
    }

    return 0;
}
