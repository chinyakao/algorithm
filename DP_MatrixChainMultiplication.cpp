// This code implemented using Algorithm in Coremen book

#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;
int m[1000][1000] = { {0} };
int s[1000][1000] = { {0} };

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n

int MatrixChainMultiplication( vector<int> p, int size)
{
	int i, j, k, len, q;

	//Here len is chain length. It varies from length 2 to length n.
	for (len = 2; len < size; len++)
	{
		for (i = 1; i < size - len + 1; i++)
		{
			j = i + len - 1;
			m[i][j] = INT_MAX;  //assigning to maximum value

			for (k = i; k < j ; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					s[i][j] = k;
					m[i][j] = q;    //if number of multiplications found less that number will be updated.
				}
			}
		}
	}

	return m[1][size - 1];   //returning the final answer which is M[1][n]

}

void Print(int i, int j) {
	if (i == j) 
		cout << "A" << i;
	else {
		cout << "(";
		Print(i, s[i][j]);
		Print(s[i][j] + 1, j);
		cout << ")";
	}
}

int main()
{
	int size, i;
	vector<int> arr;
	cin >> size;
	for (int j = 0; j < size; j++) {
		cin >> i;
		arr.push_back(i);
	}
	cout << "Minimum multiplication: " << MatrixChainMultiplication(arr, size) << endl;
	cout << "Order: ";
	Print(1, size-1);
	cout << endl;

	system("pause");
	return 0;
}