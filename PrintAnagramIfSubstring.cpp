/////////////////////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Print anagram of a given string if its a substring of another input string
// Complexity : O(N*N!) * O(string::find) 
/////////////////////////////////
#include<iostream>
#include<string>

using namespace std;

bool swap(string& str, int i, int j)
{
	char c = str[i];
	str[i] = str[j];
	str[j] = c;
    return true;
}

string printAnagram(string strInput1, string strInput2, unsigned int iPos)
{
    if(iPos == strInput1.length())
	{
        if(strInput2.find(strInput1) != string::npos)
        {
            return strInput1;
        }
	}
    string strReturnString;
	for(unsigned int i = iPos; i < strInput1.length(); ++i)
	{
        //deal with duplicate
        if(strInput1[i] == strInput1[iPos] && i != iPos)
        {
            continue;
        }
		swap(strInput1, i, iPos);
        strReturnString = printAnagram(strInput1, strInput2, iPos + 1);
        if(strReturnString != "")
        {
            return strReturnString;
        }
		swap(strInput1, i, iPos);
	}
    return "";
}

int main()
{
	string strInput1, strInput2;
	cout<<"\n Enter a string : ";
	cin>>strInput1;
	cout<<"\n Enter second string : ";
    cin>>strInput2;

    strInput2 = printAnagram(strInput1, strInput2, 0);

    if(strInput2 != "")
    {
        cout<<"\n Anagram "<<strInput2<<" is a substring of second string!\n";
    }
    else
    {
        cout<<"\n No anagram is substring of second string!\n";
    }

	return 0;
}
