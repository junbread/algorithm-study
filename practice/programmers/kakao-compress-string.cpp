#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s)
{
    int answer = 10000;

    int strlen = s.length();
    int maxlen = strlen / 2;

    if (strlen == 1)
        return 1;
    for (int i = 1; i <= maxlen; i++)
    {
        int count = 1;
        stringstream ss;
        string tar = s.substr(0, i);
        for (int j = i; j < strlen; j += i)
        {
            string cmp = s.substr(j, i);
            if (tar.compare(cmp) == 0)
            {
                count++;
            }
            else
            {
                if (count == 1)
                    ss << tar;
                else
                {
                    ss << count << tar;
                    count = 1;
                }
                tar = cmp;
            }

            if (j + i >= strlen)
            {
                if (count > 1)
                    ss << count << cmp;
                else
                    ss << cmp;
                break;
            }
        }

        if (ss.str().length() < answer)
            answer = ss.str().length();
    }

    return answer;
}

int main()
{
    string str = "aabbaccc";

    cout << solution(str);

    return 0;
}