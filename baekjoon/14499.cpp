#include <iostream>
#include <cstring>

#define T 0
#define N 1
#define E 2
#define S 3
#define W 4
#define F 5

using namespace std;

int n, m, x, y, k;
int map[20][20];

int dx[5] = {0, 0, 0, -1, 1}; // padding 0
int dy[5] = {0, 1, -1, 0, 0};

int dice[6] = {
    0,
}; // t, n, e, s, w, f;

void move(int dir)
{
    int new_x = x + dx[dir];
    int new_y = y + dy[dir];

    if (new_x >= n || new_x < 0)
        return;
    if (new_y >= m || new_y < 0)
        return;

    x = new_x;
    y = new_y;

    int old_dice[6];
    memcpy(&old_dice, &dice, sizeof(int) * 6);

    switch (dir)
    {
    case 1: // E
        dice[T] = old_dice[W];
        dice[N] = old_dice[N];
        dice[E] = old_dice[T];
        dice[S] = old_dice[S];
        dice[W] = old_dice[F];
        dice[F] = old_dice[E];
        break;
    case 2: // W
        dice[T] = old_dice[E];
        dice[N] = old_dice[N];
        dice[E] = old_dice[F];
        dice[S] = old_dice[S];
        dice[W] = old_dice[T];
        dice[F] = old_dice[W];
        break;
    case 3: // N
        dice[T] = old_dice[S];
        dice[N] = old_dice[T];
        dice[E] = old_dice[E];
        dice[S] = old_dice[F];
        dice[W] = old_dice[W];
        dice[F] = old_dice[N];
        break;
    case 4: // S
        dice[T] = old_dice[N];
        dice[N] = old_dice[F];
        dice[E] = old_dice[E];
        dice[S] = old_dice[T];
        dice[W] = old_dice[W];
        dice[F] = old_dice[S];
        break;
    }

    int *map_pos = &(map[x][y]);
    if (*map_pos == 0)
        *map_pos = dice[F];
    else
    {
        dice[F] = *map_pos;
        *map_pos = 0;
    }

    cout << dice[T] << endl;
}

int main()
{
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0, dir = 0; i < k; i++)
    {
        cin >> dir;
        move(dir);
    }

    return 0;
}