#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer;

    for (int i = 0; i < heights.size(); i++)
    {
        answer.push_back(0);
        for (int j = i - 1; j >= 0; j--)
            if (heights[j] > heights[i])
            {
                answer[i] = j + 1;
                break;
            }
    }
    
    return answer;
}

int main(int argc, char **argv)
{
    vector<int> heights = {6, 9, 5, 7, 4};
    vector<int> answer = solution(heights);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];

    return 0;
}