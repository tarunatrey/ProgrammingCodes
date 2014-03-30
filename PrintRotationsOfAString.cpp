#include<iostream>
#include<string>

using namespace std;

int main()
{
    	string str;
    	int len;

	cout<<"\n Enter string : ";
	cin>>str;
	len = str.length();

    	int k;
    	for(int i=0; i<len; i++)
    	{
        		cout<<"\n Rotation "<<i+1<<" : ";
        		for(int j=i; j<=(i+len-1); j++)
        		{
            			k= j%len;
            			cout<<str[k];
        		}
    	}
	cout<<"\n";
    	return 0;
}
