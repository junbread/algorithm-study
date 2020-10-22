#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> users;
vector<pair<int, string>> history;

vector<string> split(string str)
{
    vector<string> res;

    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, ' '))
    {
        res.push_back(buffer);
    }

    return res;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    for (auto rec : record)
    {
        vector<string> rec_parsed = split(rec);

        int type = 0; // 0 : enter, 1 : change, 2 : leave
        if (rec_parsed[0].compare("Enter") == 0)
        {
            type = 0;
            auto search = users.find(rec_parsed[1]);
            if (search != users.end())
                search->second = rec_parsed[2];
            else
                users.insert(make_pair(rec_parsed[1], rec_parsed[2]));
            history.push_back(make_pair(type, rec_parsed[1]));
        }
        else if (rec_parsed[0].compare("Change") == 0)
        {
            type = 1;
            auto search = users.find(rec_parsed[1]);
            if (search != users.end())
                search->second = rec_parsed[2];
        }
        else
        {
            type = 2;
            history.push_back(make_pair(type, rec_parsed[1]));
        }
    }

    for (auto his : history)
    {
        stringstream ss;
        switch (his.first)
        {
        case 0: // enter
            ss << users.find(his.second)->second << "님이 들어왔습니다.";
            answer.push_back(ss.str());
            break;
        case 2:
            ss << users.find(his.second)->second << "님이 나갔습니다.";
            answer.push_back(ss.str());
            break;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> inputs = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};

    solution(inputs);
    return 0;
}
