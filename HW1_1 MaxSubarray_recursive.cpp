// Name: B10532011���t��
// Date: March 6, 2019
// Last Update: March 6, 2019
// Problem statement: Profit Maximization Problem by recursive method
// A Divide and Conquer based program for maximum subarray sum problem

#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

//��struct�s���ת��T�ӭȡAstart�Bend�Bsum 
struct ANS{int low, high, sum;};

// ��X��󤤶����̤j�� 
ANS maxCrossingSum(int *arr, int l, int m, int h)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    int maxlow=0;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum){
          left_sum = sum;
          maxlow=i;
		  }
    }
    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    int maxhigh=0;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum){
          right_sum = sum;
          maxhigh=i;
      	}
    }
 	ANS array;
 	array.low=maxlow;
 	array.high=maxhigh;
 	array.sum=left_sum + right_sum;
    // Return sum of elements on left and right of mid
    return array;
}
 
// Returns sum of maxium sum subarray in aa[l..h] 
ANS maxSubArraySum(int *arr, int l, int h)
{	
	ANS subarrayleft,subarrayright,subarraycross;
   	// Base Case: Only one element
   	if (l == h){
   		subarrayleft.low=l;
   		subarrayleft.high=h;
   		subarrayleft.sum=arr[l];
		return subarrayleft;
	}else{
    	
	//��X������ 
   	int m = (l + h)/2;
   	
   	subarrayleft=maxSubArraySum(arr, l, m);
	subarrayright=maxSubArraySum(arr, m+1, h);	
	subarraycross=maxCrossingSum(arr, l, m, h);
 
   	
    if (subarrayleft.sum>=subarrayright.sum&&subarrayleft.sum>=subarraycross.sum)
    	return subarrayleft;
    else if(subarrayright.sum>+subarrayleft.sum&&subarrayright.sum>=subarraycross.sum)
    	return subarrayright;
    else 
    	return subarraycross;
	}
}

int main() {
	ANS answer; 
	int n; //while�j��i�H���_��J 
	while (cin >> n) {
		int *arr=new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		//�N���arr�N�ifunction�A�Ǧ^max_sum 
        answer= maxSubArraySum(arr, 0, n-1);
        cout<<answer.low<<" "<<answer.high<<" "<<answer.sum<<endl;
        delete[] arr;
	}
	return 0;
}
