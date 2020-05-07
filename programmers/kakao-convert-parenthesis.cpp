#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

const char lp = '(';
const char rp = ')';

bool check_rightness(string p)
{
    int i = 0, level = 0;
    for (; i < p.length(); i++)
    {
        if (p[i] == lp)
            level++;
        else
            level--;

        if (level < 0)
            return false;
    }

    if (level > 0)
        return false;

    return true;
}

string reverse(string p)
{
    stringstream ss;
    for (int i = 0; i < p.length(); i++)
        ss << ((p[i] == lp) ? rp : lp);

    return ss.str();
}

string solution(string p)
{
    stringstream ss;

    int level = 0;
    if (!p.length())
        return "";

    int i;
    for (i = 0; i < p.length(); i++)
    {
        if (p[i] == lp)
            level++;
        else
            level--;

        if (level == 0)
            break;
    }

    string u = p.substr(0, i + 1);
    string v = p.substr(i + 1);

    if (check_rightness(u))
    {
        return u + solution(v);
    }
    else
    {
        ss << lp << solution(v) << rp;
        ss << reverse(u.substr(1, u.length() - 2));

        return ss.str();
    }
}

int main()
{
    cout << solution("(()())()") << endl;
    cout << solution(")(") << endl;
    cout << solution("()))((()") << endl;

    return 0;
}