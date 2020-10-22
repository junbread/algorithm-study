#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>

#define pos(i, j) ((i + 1) * 52 + (j + 1))

using namespace std;

int N, M;
int lab[52 * 52];

vector<pair<int, int>> clear;
vector<pair<int, int>> virus;

int dir_i[4] = { -1, 0, 1, 0 };
int dir_j[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(false);

	for (int i = 0; i < 52 * 52; i++)
		lab[i] = 1;

	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> temp;

			lab[pos(i, j)] = temp;

			if (temp == 0)
				clear.push_back(make_pair(i, j));
			else if (temp == 2)
				virus.push_back(make_pair(i, j));
		}

	if (clear.empty())
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> mask(virus.size(), 1);
	for (int i = 0; i < M; i++)
		mask[i] = 0;

	int min_p_time = INT_MAX;
	do
	{
		int map[52 * 52];
		memcpy(map, lab, sizeof(map));

		queue<pair<int, pair<int, int>>> propagate;

		vector<pair<int, int>> remain_clear;
		remain_clear.assign(clear.begin(), clear.end());

		for (int i = 0; i < mask.size(); i++)
			if (mask[i] == 0)
				propagate.push(make_pair(0, virus[i]));

		int finish_time = 0;
		while (!remain_clear.empty() && !propagate.empty())
		{
			auto p_info = propagate.front();
			propagate.pop();

			int p_time = p_info.first;
			auto p_pos = p_info.second;

			int status = map[pos(p_pos.first, p_pos.second)];
			if (status == 0 || status == 2)
			{
				if (status == 0)
				{
					map[pos(p_pos.first, p_pos.second)] = 3;

					for (int i = 0; i < remain_clear.size(); i++)
						if (remain_clear[i] == p_pos)
							remain_clear.erase(remain_clear.begin() + i);
				}

				else
					map[pos(p_pos.first, p_pos.second)] = 4;

				for (int i = 0; i < 4; i++)
				{
					int next_status = map[pos(p_pos.first + dir_i[i], p_pos.second + dir_j[i])];
					if (next_status == 0 || next_status == 2) {
						propagate.push(make_pair(p_time + 1, make_pair(p_pos.first + dir_i[i], p_pos.second + dir_j[i])));
					}
				}

				finish_time = p_time;
			}
		}

		bool is_finished = true;
		for (auto c : clear)
			if (map[pos(c.first, c.second)] == 0)
			{
				is_finished = false;
				break;
			}

		if (is_finished && finish_time < min_p_time)
			min_p_time = finish_time;

	} while (next_permutation(mask.begin(), mask.end()));

	if (min_p_time == INT_MAX)
		min_p_time = -1;

	cout << min_p_time << endl;

	return 0;

}