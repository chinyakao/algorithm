#include <iostream>
#include <map>
#include <vector>
#include <bitset>
using namespace std;
int adj[1000][1000];
int root;
bool ans;
map<int, vector<int> > node;
bitset<900> check;

void goDeep(int k, int l) {
	check[k] = 1;
	int pointTo = node[k][l];
	if (check[pointTo] == 1) {
		return;
	}
	if (adj[root][pointTo] == 1 && k != root) {
		ans = false;
		return;
	}
	adj[root][pointTo] = 1;
	check[pointTo] = 1;
	for (int j = 0; j < node[pointTo].size(); j++) {
		goDeep(pointTo, j);
	}
	return;
}

int main() {

	int n, vec, edg;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vec >> edg;
		for (int s = 0; s < 1000; s++) {
			for (int d = 0; d < 1000; d++) {
				adj[s][d] = 0;
			}
		}
		int j;
		int x, y;
		ans = true;
		for (j = 0; j < edg; j++) {
			cin >> x >> y;
			if (adj[x][y]) {
				ans = false;
				break;
			}
			node[x].push_back(y);
			adj[x][y] = 1;
		}
		for (; j < edg; j++)
			cin >> x >> y;
		for (int k = 0; k < vec; k++) {
			if (!ans) 
				break;
			for (int l = 0; l < node[k].size(); l++) {
				check.reset();
				root = k;
				goDeep(k, l);
			}
		}
		if (ans)
			cout << i + 1 << " YES" << endl;
		else
			cout << i + 1 << " NO" << endl;
		node.clear();
	}
	//system("pause");
	return 0;
}