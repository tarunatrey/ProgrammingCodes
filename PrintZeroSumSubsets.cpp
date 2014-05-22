/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Find all subsets of an integer array with sum zero
// Complexity : O(N)
/////////////////////////////////

#include<iostream>

using namespace std;

int arr[]={1,2,3,-2,-1,4,-5,1};

int main()
{
    int iNumOfElements;
    iNumOfElements = sizeof(arr)/sizeof(int);
    
    int *sumarr = new int[iNumOfElements*sizeof(int)];
    for(int i=0; i<iNumOfElements; i++)
    {
        if(i==0)
	    {
            sumarr[i] = arr[i];
	    }
        else
	    {
            sumarr[i] = sumarr[i-1] + arr[i];
	    }
    }

    cout<<"\n Original array : ";
    for(int i=0; i<iNumOfElements; i++)
    {
        cout<<" "<<arr[i];
    }

    cout<<"\n Calculated sum array : ";
    for(int i=0; i<iNumOfElements; i++)
    {
        cout<<" "<<sumarr[i];
    }

    cout<<"\n Subsets with sum zero :-";
    for(int i=0; i<iNumOfElements-1; i++)
    {
        for(int j=i+1; j<iNumOfElements; j++)
        {
            if(sumarr[i] == sumarr[j])
            {
                cout<<"\n";
                for(int k=i+1; k<=j; k++)
                    cout<<" "<<arr[k];
            }  
        }
    }
    cout<<"\n";

    return 0;
}
