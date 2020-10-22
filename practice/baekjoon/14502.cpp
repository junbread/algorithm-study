#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define pos(i, j) ((i + 1) * 10 + (j + 1))

using namespace std;

int N, M;

int lab[10 * 10];

vector<pair<int, int>> virus;
vector<pair<int, int>> clean;

void propagate(int* map, int i, int j)
{
	if (map[pos(i, j)] != 0)
		return;

	map[pos(i, j)] = 2;

	propagate(map, i + 1, j);
	propagate(map, i - 1, j);
	propagate(map, i, j + 1);
	propagate(map, i, j - 1);
}

int main()
{
	for (int i = 0; i < 100; i++)
		lab[i] = 1;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> lab[pos(i, j)];
			if (lab[pos(i, j)] == 0)
				clean.push_back(make_pair(i, j));
			else if (lab[pos(i, j)] == 2)
				virus.push_back(make_pair(i, j));
		}
	
	vector<int> mask(clean.size());
	mask[clean.size() - 1] = 1;
	mask[clean.size() - 2] = 1;
	mask[clean.size() - 3] = 1;

	int max_safe_area = 0, cur_safe_area;
	do
	{
		int map[100];
		memcpy(map, lab, sizeof(map));

		for (int i = 0; i < clean.size(); i++)
			if (mask[i] == 1)
				map[pos(clean[i].first, clean[i].second)] = 1;

		for (int i = 0; i < virus.size(); i++)
		{
			map[pos(virus[i].first, virus[i].second)] = 0;
			propagate(map, virus[i].first, virus[i].second);
		}

		cur_safe_area = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[pos(i, j)] == 0) cur_safe_area++;

		if (cur_safe_area > max_safe_area)
			max_safe_area = cur_safe_area;

	} while (next_permutation(mask.begin(), mask.end()));
	
	cout << max_safe_area;

	return 0;
}