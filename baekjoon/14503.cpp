#include <iostream>

#define pos(i, j) ((i + 1) * 52 + (j + 1))

using namespace std;

int N, M;
int cdir;
int ci, cj;

int dir_i[4] = { -1, 0, 1, 0 };
int dir_j[4] = { 0, 1, 0, -1 };

int map[52 * 52];

int cleaned_num;

bool clean_and_move()
{
	if (map[pos(ci, cj)] == 0)
	{
		map[pos(ci, cj)] = 2;
		cleaned_num++;
	}

	for (int i = 0; i < 4; i++)
	{
		int left_dir = (cdir + 3) % 4;
		int left_i = ci + dir_i[left_dir];
		int left_j = cj + dir_j[left_dir];

		if (map[pos(left_i, left_j)] == 0)
		{
			cdir = left_dir;
			ci = left_i;
			cj = left_j;
			return true;
		}
		else
			cdir = left_dir;
	}

	int back_dir = (cdir + 2) % 4;
	int back_i = ci + dir_i[back_dir];
	int back_j = cj + dir_j[back_dir];

	if (map[pos(back_i, back_j)] == 1)
		return false;

	ci = back_i;
	cj = back_j;

	return true;
}

int main()
{
	cin >> N >> M;
	cin >> ci >> cj >> cdir;

	for (int i = 0; i < 52 * 52; i++)
		map[i] = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[pos(i, j)];

	while (clean_and_move());

	cout << cleaned_num;

	return 0;
}