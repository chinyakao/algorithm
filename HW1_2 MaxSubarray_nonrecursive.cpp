// Name: B10532011���t��
// Date: March 6, 2019
// Last Update: March 6, 2019
// Problem statement: Profit Maximization Problem by non-recursive method

#include<iostream>
using namespace std;
//�ŧi�@��function��X�̤jsubarray 
int maxSubSeqSum(int arr[],int n);

int main() {
	int n; //while�j��i�H���_��J 
	while (cin >> n) {
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		//�N���arr�N�ifunction
        maxSubSeqSum(arr,n);  
	}
	return 0;
}

int maxSubSeqSum(int arr[],int n){
        int temp=0, tempi=0;
		int max=0, maxi=0, maxj=0;
		
        for(int i=0; i < n; i++)
		{	//arr�@�Ӥ@�ӥ[�W�h 
			temp=temp+arr[i];
			//��[��Y�@�Ӽƨϱo��ӭȻ��p�󤧫e���ȡA�h�k�s 
			//(�o��]�w������ܬ��t���ɭԨӧP�_) 
			if(temp<0)
			{
				temp=0; 
				tempi=i+1;//����Start��m�qfor�j�驹��@�� 
			}
			//��s���Ȥj�󤧫e�x�s���̤j�ȡA�h��s�̤j��
			//�B�P���x�s��m 
            else if(temp > max)
			{
                max = temp;
                maxi = tempi; //start��m���}�C�}�l�[����m 
				maxj = i; //end��m��for�j��ҥ[����m 
			} 
        }
        cout<<maxi<<" "<<maxj<<" "<<max<<endl;
}

