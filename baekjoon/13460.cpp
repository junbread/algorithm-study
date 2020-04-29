#include <iostream>
#include <queue>

using namespace std;

class Point
{
public:
    int x;
    int y;

    bool operator==(const Point &other) const
    {
        return this->x == other.x && this->y == other.y;
    }
};

class State
{
public:
    Point r;
    Point b;
    int level;
};

queue<State> states;

int h, w;
char **A;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

Point o;

int solution()
{
    while (!states.empty())
    {
        State st = states.front();
        states.pop();

        if (st.level > 10)
            break;

        Point r = st.r;
        Point b = st.b;

        int min = -1;
        for (int i = 0; i < 4; i++)
        {
            Point new_r, new_b;
            char new_r_val, new_b_val;

            new_r.x = r.x;
            new_r.y = r.y;
            while (A[new_r.x + dx[i]][new_r.y + dy[i]] != '#')
            {
                new_r.x += dx[i];
                new_r.y += dy[i];

                if (A[new_r.x][new_r.y] == 'O')
                    break;
            }

            new_b.x = b.x;
            new_b.y = b.y;
            while (A[new_b.x + dx[i]][new_b.y + dy[i]] != '#')
            {
                new_b.x += dx[i];
                new_b.y += dy[i];

                if (A[new_b.x][new_b.y] == 'O')
                    break;
            }

            if (new_r == o && new_b == o)
                continue;

            // correct location
            if (new_r == new_b)
            {
                if (r.x < b.x) // r b
                {
                    if (dx[i] > 0)
                        new_r.x -= dx[i];
                    else
                        new_b.x -= dx[i];
                }
                else
                { // b r
                    if (dx[i] > 0)
                        new_b.x -= dx[i];
                    else
                        new_r.x -= dx[i];
                }

                if (r.y < b.y) // r b
                {
                    if (dy[i] > 0)
                        new_r.y -= dy[i];
                    else
                        new_b.y -= dy[i];
                }
                else
                { // b r
                    if (dy[i] > 0)
                        new_b.y -= dy[i];
                    else
                        new_r.y -= dy[i];
                }
            }

            if (new_r == o)
                min = st.level;
            else if (!(new_b == o) && !(new_b == b && new_r == r))
            {
                State new_st;
                new_st.r = new_r;
                new_st.b = new_b;
                new_st.level = st.level + 1;

                states.push(new_st);
            }
        }

        if (min > 0)
            return min;
    }

    return -1;
}

int main()
{
    cin >> h >> w;

    A = new char *[h];

    State init;
    init.level = 1;

    for (int i = 0; i < h; i++)
    {
        char *row = new char[w];
        cin >> row;

        for (int j = 0; j < w; j++)
        {
            if (row[j] == 'R')
            {
                init.r.x = i;
                init.r.y = j;
            }
            else if (row[j] == 'B')
            {
                init.b.x = i;
                init.b.y = j;
            }
            else if (row[j] == 'O')
            {
                o.x = i;
                o.y = j;
            }
        }

        A[i] = row;
    }

    states.push(init);

    cout << solution();

    return 0;
}