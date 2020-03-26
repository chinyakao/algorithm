#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class activity
{
public:
	int number;
	int start;
	int end;
	int value;
	int pre_act;

	activity()
	{
		number = -1;
		start = -1;
		end = -1;
		value = -1;
		pre_act = -1;
	}
	activity(int a, int b, int c, int d)
	{
		number = a;
		start = b;
		end = c;
		value = d;
		pre_act = -1;
	}
	bool compatible(activity a)
	{
		if (a.start >= end || a.end <= start)
		{
			return true;
		}
		else return false;
	}
};

bool comp(activity a, activity b)
{
	return a.end < b.end;
}
bool comp_ans(int a, int b)
{
	return a < b;
}



int main()
{
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		activity dp[999];
		vector<activity>activities;
		
		int m;
		cin >> m;

		for (int j = 0; j < m; j++)//讀測資
		{
			int temp1, temp2, temp3, temp4;
			cin >> temp1 >> temp2 >> temp3 >> temp4;
			if(temp2<=temp3)
				activities.push_back(activity(temp1, temp2, temp3, temp4));
		}

		sort(activities.begin(), activities.end(), comp);

		for (int j = 0; j < m; j++)//初始化
		{
			dp[j] = activities[j];
		}

		for (int k = 1; k < m; k++)
		{

			for (int j = 0; j < k; j++)
			{

				if (activities[k].compatible(activities[j]) && dp[j].value + activities[k].value > dp[k].value)//建表
				{
					dp[k].value = dp[j].value + activities[k].value;
					dp[k].pre_act = dp[j].number;
				}
			}
		}



		int max_ans = -1, max_value = -1;
		for (int k = 0; k < m; k++)
		{
			if (dp[k].value > max_value)
			{
				max_value = dp[k].value;
				max_ans = k;
			}
		}


		vector<int>ans;
		cout << dp[max_ans].value << endl;
		ans.push_back(dp[max_ans].number);
		activity temp = dp[max_ans];

		

		for (int k = 0; k < m ; k++)
		{
			cout <<"K: "<<k<<" "<<"K number: "<< dp[k].number <<" " << "temp pre_act: "<< temp.pre_act << endl;
			if (dp[k].number == temp.pre_act)
			{
				ans.push_back(temp.pre_act);
				temp = dp[k];
				k = -1;
			}
		}

		sort(ans.begin(),ans.end(),comp_ans);
		for (int k = 0; k < ans.size(); k++)
		{
			cout << ans[k];
			if (k != ans.size() - 1)
				cout << " ";
		}
		cout << endl;

	}


	system("pause");
	return 0;
}