#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

char input[1000];	//輸入字串
int table[1000][1000] = { { -1 } }; //DP表格紀錄結果
int mark[1000][1000] = { {-1 } };	//DP表格紀錄結果

int main() {

	int n; //輸入有幾筆測資
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		int len = strlen(input);//字串長度
		
		//table最上列及最左行初始化為0
		for (int j = 0; j <= len; j++)
			table[j][0] = 0;
		for (int j = 0; j <= len; j++) 
			table[0][j] = 0;
		
		//做字串與字串reverse比對，以LCS填入table
		for (int j = 1; j <= len; j++) {
			for (int k = 1; k <= len; k++) {
				if (input[j - 1] == input[len - k]) {
					table[j][k] = table[j - 1][k - 1] + 1;
					mark[j][k] = 0;	//若字元相同，標記為0
				}
				else {
					if (table[j - 1][k] >= table[j][k - 1]) {
						table[j][k] = table[j - 1][k];
						mark[j][k] = 1;
					}
					else {
						table[j][k] = table[j][k - 1];
						mark[j][k] = 2;
					}
				}
			}
		}
		cout << table[len][len] << endl; //印出最大長度
		
		int j = len, k = len;
		// 依據LCS的table輸出結果
		while (1) {    
			if (j <= 0 || k <= 0)break;
			if (mark[j][k] == 0) {		//印出所求字串
				cout << input[j - 1];
				j--;
				k--;
			}
			else if (mark[j][k] == 1) 
				j--;
			else if (mark[j][k] == 2) 
				k--;
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}