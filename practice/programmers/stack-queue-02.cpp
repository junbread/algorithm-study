#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    vector<int> truck_start;

    int first = 0, last = 0, timer = 0, cur_weight = 0;

    cur_weight += truck_weights[0];
    truck_start.push_back(1);

    while (first < truck_weights.size())
    {
        timer++;

        if (timer - truck_start[first] >= bridge_length)
            cur_weight -= truck_weights[first++];

        if (last + 1 < truck_weights.size() && cur_weight + truck_weights[last + 1] <= weight)
        {
            cur_weight += truck_weights[++last];
            truck_start.push_back(timer);
        }
    }

    return timer;
}

int main(int argc, char **argv)
{
    int bridge_length = 2, weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    cout << solution(bridge_length, weight, truck_weights);

    return 0;
}