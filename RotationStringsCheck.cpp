#include<iostream>
#include<string>

using namespace std;

int main()
{
    	string str1;
    	string str2;
	cout<<"\n Enter string 1 : ";
	cin>>str1;
	cout<<"\n Enter string 2 : ";
	cin>>str2;
        str1 = str1 + str1;
        
        if (str1.find(str2) != string::npos && str1.length() == str2.length())
		cout<<"\n Given strings are rotations of each other!\n";
        else
            	cout<<"\n Given strings are not rotations!\n";
    	return 0;
}
