#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int size = progresses.size();

    for (int ptr = 0; ptr < size;)
    {
        int days = (99 - progresses[ptr]) / speeds[ptr] + 1;

        for (int i = ptr; i < size; i++)
            progresses[i] += speeds[i] * days;

        int deploy = 0;
        for (; progresses[ptr] >= 100; ptr++, deploy++);

        answer.push_back(deploy);
    }

    return answer;
}

int main(int argc, char **argv)
{
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    vector<int> sol = solution(progresses, speeds);
    for (int i = 0; i < sol.size(); i++)
        cout << sol[i];

    return 0;
}