#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> failure_rate;

int compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    double rate_a = a.second.second ? ((double) a.second.first / a.second.second) : 0;
    double rate_b = b.second.second ? ((double) b.second.first / b.second.second) : 0;

    if (rate_a == rate_b)
        return a.first < b.first;
    else
        return rate_a > rate_b;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    for (int i = 1; i <= N; i++)
        failure_rate.push_back(make_pair(i, make_pair(0, 0)));

    for (int stage : stages)
    {
        for (int i = 1; i < stage; i++)
            failure_rate[i - 1].second.second++;
        if (stage != N + 1)
        {
            failure_rate[stage - 1].second.first++;
            failure_rate[stage - 1].second.second++;
        }
    }

    sort(failure_rate.begin(), failure_rate.end(), compare);

    for (auto rate : failure_rate)
        answer.push_back(rate.first);

    return answer;
}

int main(int argc, char const *argv[])
{
    int N = 5;
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};

    solution(N, stages);

    return 0;
}
