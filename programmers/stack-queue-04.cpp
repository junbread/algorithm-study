#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 1, ptr = 0;
    while (true)
    {
        bool is_max = true;
        for (int i = ptr + 1; i < priorities.size(); i++)
        {
            if (priorities[ptr] < priorities[i])
            {
                priorities.push_back(priorities[ptr]);
                is_max = false;
                break;
            }
        }

        if (is_max)
        {
            if (ptr == location)
                return answer;
            answer++;
            ptr++;
        }
        else
        {
            if (ptr == location)
                location = priorities.size() - 1;
            ptr++;
        }
    }
}

int main(int argc, char **argv)
{
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;

    int sol = solution(priorities, location);
    cout << sol << endl;

    return 0;
}