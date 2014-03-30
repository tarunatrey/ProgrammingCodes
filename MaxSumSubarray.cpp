#include <iostream>
#define MAX 9

using namespace std;

int maximumSubArray(int *arr)
{
    	int currentSum=0, maxSum=0;
	for(int i=0;i<MAX;i++)
	{
        	currentSum+=arr[i];
        	if(currentSum > maxSum)
        	{
            		maxSum = currentSum;
        	}
        	else if(currentSum < 0)
        	{
            		currentSum= 0;
        	}
    	}
    	return maxSum;
}
int main()
{
    	int arr[MAX]={-2,1,-3,4,-1, 2, 1,-5,4};
    	cout<<"Maximum Subsquence Sum : "<<maximumSubArray(arr)<<"\n";
    	return 0;
}
