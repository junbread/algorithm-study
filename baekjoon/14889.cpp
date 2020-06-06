#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	int synergy[20][20];

	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> synergy[i][j];

	vector<int> team(N, 1);

	for (int i = 0; i < N / 2; i++)
		team[i] = 0;

	int power[2];
	int min_power_diff = INT_MAX;

	do
	{
		power[0] = 0;
		power[1] = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (team[i] == team[j])
					power[team[i]] += synergy[i][j];

		int power_diff = power[0] > power[1] ?
			power[0] - power[1] : power[1] - power[0];

		min_power_diff = power_diff < min_power_diff ? power_diff : min_power_diff;
		
	} while (next_permutation(team.begin(), team.end()));

	cout << min_power_diff << endl;
	
	return 0;
}