#include <iostream>

using namespace std;

int n, m;
int num[500][500];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int sum_tet(int depth, int sum, int x, int y, int dir, int prevdir)
{
    // boundary check
    if (x >= n || x < 0 || y >= m || y < 0)
        return -1;

    // add num
    sum += num[x][y];

    // if depth is 3 (4 blocks), finish tetromino
    if (depth >= 3)
        return sum;

    int max = sum, new_sum;
    for (int i = 0; i < 4; i++) // 4 directions
    {
        if (dir == i || dir / 2 != i / 2) // can't go back to previous position
        {
            new_sum = sum_tet(depth + 1, sum, x + dx[i], y + dy[i], i, dir);
            max = new_sum > max ? new_sum : max;
        }
    }

    // check non-DFS shape: ㅗ
    if (depth == 2 && dir == prevdir) // when shape is: === 
    {
        // make shape ㅜ or ㅏ (if direction is reversed, ㅗ or ㅓ)
        int newx = x - dx[dir] + (dy[dir] != 0 ? dy[dir] : 0);
        int newy = y - dy[dir] + (dx[dir] != 0 ? dx[dir] : 0);

        new_sum = sum_tet(depth + 1, sum, newx, newy, -99, -99);
        max = new_sum > max ? new_sum : max;
    }

    return max;
}

int main()
{
    cin >> n >> m;

    // input number map
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> num[i][j];

    // DFS to each position
    int max = 0, sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            sum = sum_tet(0, 0, i, j, -99, -99);
            max = sum > max ? sum : max;
        }

    cout << max << endl;

    return 0;
}