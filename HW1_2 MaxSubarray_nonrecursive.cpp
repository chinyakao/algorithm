// Name: B10532011高靖雅
// Date: March 6, 2019
// Last Update: March 6, 2019
// Problem statement: Profit Maximization Problem by non-recursive method

#include<iostream>
using namespace std;
//宣告一個function找出最大subarray 
int maxSubSeqSum(int arr[],int n);

int main() {
	int n; //while迴圈可以不斷輸入 
	while (cin >> n) {
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		//將整個arr代進function
        maxSubSeqSum(arr,n);  
	}
	return 0;
}

int maxSubSeqSum(int arr[],int n){
        int temp=0, tempi=0;
		int max=0, maxi=0, maxj=0;
		
        for(int i=0; i < n; i++)
		{	//arr一個一個加上去 
			temp=temp+arr[i];
			//當加到某一個數使得整個值遠小於之前的值，則歸零 
			//(這邊設定成當值變為負的時候來判斷) 
			if(temp<0)
			{
				temp=0; 
				tempi=i+1;//此時Start位置從for迴圈往後一個 
			}
			//當新的值大於之前儲存的最大值，則更新最大值
			//且同時儲存位置 
            else if(temp > max)
			{
                max = temp;
                maxi = tempi; //start位置為陣列開始加的位置 
				maxj = i; //end位置為for迴圈所加的位置 
			} 
        }
        cout<<maxi<<" "<<maxj<<" "<<max<<endl;
}

