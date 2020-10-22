#include <iostream>

using namespace std;

int n;
int duration[15];
int pay[15];

int solution(int ptr, int sum)
{
    int max = sum, temp;
    for(int i = ptr; i < n; i++)
    {
        if (i + duration[i] > n) continue;
        temp = solution(i + duration[i], sum + pay[i]);
        if (temp > max)
            max = temp;
    }

    return max;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> duration[i] >> pay[i];

    cout << solution(0, 0) << endl;

    return 0;
}