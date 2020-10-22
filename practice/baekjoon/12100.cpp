#include <iostream>
#include <queue>

using namespace std;

int n, N;
char dir[4] = {'u', 'd', 'l', 'r'};

int solution(int *state, int level)
{
    if (level > 5)
        return -1;

    int max_block = 0;

    for (int i = 0; i < 4; i++)
    {
        int *new_state = new int[N]();

        for (int j = 0; j < n; j++)
        {
            queue<int> q;
            int temp = 0;
            for (int k = 0; k < n; k++)
            {
                int pos, nextpos;
                switch (dir[i])
                {
                case 'u':
                    pos = k * n + j;
                    break;
                case 'd':
                    pos = (n - (k + 1)) * n + j;
                    break;
                case 'l':
                    pos = j * n + k;
                    break;
                case 'r':
                    pos = j * n + (n - (k + 1));
                    break;
                }

                int curr = state[pos];

                if (temp > 0)
                {
                    if (temp == curr)
                    {
                        q.push(curr + temp);
                        temp = 0;
                    }
                    else
                    {
                        q.push(temp);
                        temp = curr;
                    }
                }
                else
                    temp = curr;

                if (k == n - 1 && temp > 0)
                {
                    q.push(temp);
                }
            }

            int qsize = q.size();
            for (int k = 0; k < qsize; k++)
            {
                int pos;
                switch (dir[i])
                {
                case 'u':
                    pos = k * n + j;
                    break;
                case 'd':
                    pos = (n - (k + 1)) * n + j;
                    break;
                case 'l':
                    pos = j * n + k;
                    break;
                case 'r':
                    pos = j * n + (n - (k + 1));
                    break;
                }

                new_state[pos] = q.front();
                max_block = max_block > q.front() ? max_block : q.front();
                q.pop();
            }
        }

        cout << dir[i] << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << new_state[i * n + j];
            cout << endl;
        }
        cout << endl;

        int next_max_block = solution(new_state, level + 1);
        max_block = max_block > next_max_block ? max_block : next_max_block;
    }

    return max_block;
}

int main()
{
    cin >> n;
    N = n * n;

    int *init_state = new int[N];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> init_state[i * n + j];

    cout << solution(init_state, 0);

    return 0;
}