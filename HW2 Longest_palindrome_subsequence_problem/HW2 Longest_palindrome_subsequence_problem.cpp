#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

char input[1000];	//��J�r��
int table[1000][1000] = { { -1 } }; //DP���������G
int mark[1000][1000] = { {-1 } };	//DP���������G

int main() {

	int n; //��J���X������
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		int len = strlen(input);//�r�����
		
		//table�̤W�C�γ̥����l�Ƭ�0
		for (int j = 0; j <= len; j++)
			table[j][0] = 0;
		for (int j = 0; j <= len; j++) 
			table[0][j] = 0;
		
		//���r��P�r��reverse���A�HLCS��Jtable
		for (int j = 1; j <= len; j++) {
			for (int k = 1; k <= len; k++) {
				if (input[j - 1] == input[len - k]) {
					table[j][k] = table[j - 1][k - 1] + 1;
					mark[j][k] = 0;	//�Y�r���ۦP�A�аO��0
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
		cout << table[len][len] << endl; //�L�X�̤j����
		
		int j = len, k = len;
		// �̾�LCS��table��X���G
		while (1) {    
			if (j <= 0 || k <= 0)break;
			if (mark[j][k] == 0) {		//�L�X�ҨD�r��
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