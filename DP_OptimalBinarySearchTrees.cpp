#include<iostream>
#include<vector>
using namespace std;

int cost[1000][1000];
int sum[1000][1000];
int root[1000][1000];


void OptimalBST(vector<int> p, vector<int> q, int n) {
	for (int j = 1; j <= n+1; j++) {
		cost[j][j - 1] = q[j - 1];
		sum[j][j - 1] = q[j - 1];
	}
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= n - l + 1; j++) {
			int k = j + l - 1;
			cost[j][k] = INT_MAX;
			sum[j][k] = sum[j][k - 1] + p[j] + q[j];

			for (int m = j; m <= k; m++) {
				int temp = cost[j][m - 1] + cost[m + 1][k] + sum[j][k];
				if (temp < cost[j][k]) {
					cost[j][k] = temp;
					root[j][k] = m;
				}
			}
		}
	}
}

//void Print(int i, int j) {
//	if (i > 0 && j > 0) {
//		if (i == j) {
//			cout << i;
//			return;
//		}
//		else {
//			int root = r[i][j];
//			cout << "root: K" << root << "	";
//			cout << "left: K";
//			if (i == r[i][root - 1]) {
//				cout << i <<;
//			}
//			Print(i, root - 1);
//			cout << "	right: K";
//			Print(root + 1, j);
//			cout << endl;
//		}
//
//	}
//	else
//		return;
//}

int main() {
	vector<int> key, dum;
	int size, i;
	cin >> size;
	key.push_back(-1);
	for (int j = 1; j <= size; j++) {
		cin >> i;
		key.push_back(i);
	}
	for (int j = 0; j <= size; j++) {
		cin >> i;
		dum.push_back(i);
	}

	OptimalBST(key, dum, size);
	cout << "Cost: " << cost[1][size] << endl;
	cout << "Root: " << root[1][size] << endl;
	//Print(1, size);
	system("pause");
	return 0;
}