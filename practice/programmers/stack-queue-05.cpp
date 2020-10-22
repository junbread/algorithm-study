#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string arrangement)
{
    arrangement += '(';

    int answer = 0, queue = -1, maxqueue = -1;
    bool laser = true;

    for (int i = 0; i < arrangement.length(); i++)
    {
        switch (arrangement[i])
        {
        case '(':
            if (!laser)
            {
                answer += maxqueue - queue - 1;
                maxqueue = queue;
            }
            queue++;
            laser = true;
            break;
        case ')':
            if (laser)
            {
                answer += queue;
                maxqueue = queue;
            }
            queue--;
            laser = false;
            break;
        }
    }
    return answer;
}

int main(int argc, char **argv)
{
    string arrangement = "()(((()())(())()))(())";

    int sol = solution(arrangement);
    cout << sol << endl;

    return 0;
}