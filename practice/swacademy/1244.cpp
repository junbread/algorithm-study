#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string num;

bool visit[1000000][11];

int solution(int digit, int max_num, int max_change)
{
    if (!max_change)
        return max(max_num, stoi(num));

    for (int i = digit; i < num.size(); i++)
        for (int j = i + 1; j < num.size(); j++)
        {
            swap(num[i], num[j]);
            if (!visit[stoi(num)][max_change - 1])
            {
                visit[stoi(num)][max_change - 1] = true;
                max_num = solution(i, max_num, max_change - 1);
            }
            swap(num[i], num[j]);
        }

    return max_num;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    int max_change;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> num >> max_change;
        memset(visit, false, sizeof(visit));

        cout << "#" << test_case << " " << solution(0, 0, max_change) << endl;
    }

    return 0;
}