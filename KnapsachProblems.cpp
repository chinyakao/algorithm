#include<iostream>  
#include<vector>  
using namespace std;
int N = 0, W = 0;

class item {
public:
	int number;
	int weight;
	int value;

	item() {
		number = -1;
		weight = -1;
		value = -1;
	}
	item(int n, int w, int v) {
		number = n;
		weight = w;
		value = v;
	}
	item(int w, int v) {
		number = -1;
		weight = w;
		value = v;
	}
	bool compatible(item a)
	{
		if (a.weight + weight <= W)
		{
			return true;
		}
		else return false;
	}
};

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int temp1 = 0, temp2 = 0, temp3 = 0, max = -1;
		vector<int> index;
		vector<item> list;
		item arr[1000][1000];
		//int arr_v[1000][1000] = { {0} };

		//ªì©l
		for (int j = 1; j < N + 1; j++) {
			for (int k = j; k < N + 1; k++) {
				if (list[j].weight <= W) {
					arr[j][k].weight = list[j].weight;
					arr[j][k].value = list[j].value;
					
					if (arr[j][j].value > max) {
						max = arr[j][j].value;
						index.clear();
						index.push_back(j);
					}
				}
			}
		}


		for (int n = 1; n < N + 1; n++) {
			for (int j = 1; j < N + 1; j++) {
				for (int k = j + 1; k < N + 1; k++) {
					if (list[j].weight <= W) {
						arr[j][k].weight = arr[j][k].weight + list[k + n - 1].weight;
						arr[j][k].value = arr[j][k].value + list[k + n - 1].value;
						
						if (arr[j][k].value > max) {
							max = list[j].value + list[k].value;
							index.clear();
							index.push_back
						}					
					}
					
				}
			}

		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[j][k].weight >= 0 && arr[j][k].weight <= W) {
					if (arr[j][k].value > max) {
						max = arr[j][k].value;
					}
				}
			}
		}

		cout << max;
		system("pause");  
		return 0;
	}
}
