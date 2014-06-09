/////////////////////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Print all anagrams of a given string
// Complexity : O(N*N!) 
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

void printAnagram(string str, unsigned int pos)
{
    if(pos == str.length())
	{
        	cout<<" "<<str<<"\n";
        	return;
	}
	for(unsigned int i = pos; i < str.length(); ++i)
	{
        	//deal with duplicate
        	if(str[i] == str[pos] && i != pos)
            		continue;
		swap(str, i, pos);
		printAnagram(str, pos + 1);
		swap(str, i, pos);
	}
}

int main()
{
	string str;
	cout<<"\n Enter a string : ";
	cin>>str;
	cout<<"\n All the anagrams are listed below:-\n";
	printAnagram(str, 0);
	return 0;
}
