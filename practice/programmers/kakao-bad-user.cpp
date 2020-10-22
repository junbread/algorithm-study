#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <regex>
#include <iostream>

using namespace std;

map<string, set<string>> ban_map;
set<set<string>> ban_set;

void select(set<string> s, vector<string> &banned_id, int i)
{
    auto cand = ban_map.find(banned_id[i])->second;

    for (string id : cand)
    {
        if (s.find(id) == s.end())
        {
            s.insert(id);
            if (s.size() == banned_id.size())
            {
                if(ban_set.find(s) == ban_set.end())
                    ban_set.insert(s);
                for(auto item : s)
                    cout << item << endl;
                s.erase(id);
            }
            else
            {
                select(s, banned_id, i + 1);
                s.erase(id);
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    for (int i = 0; i < banned_id.size(); i++)
    {
        replace(banned_id[i].begin(), banned_id[i].end(), '*', '.');
        if (ban_map.find(banned_id[i]) == ban_map.end())
        {
            auto ban_set = set<string>();
            for (string id : user_id)
            {
                if (regex_match(id, regex(banned_id[i])))
                    ban_set.insert(id);
            }
            ban_map.insert(make_pair(banned_id[i], ban_set));
        }
    }

    select(set<string>(), banned_id, 0);

    return ban_set.size();
}

int main(int argc, char const *argv[])
{
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"*rodo", "*rodo", "******"};

    solution(user_id, banned_id);
    return 0;
}
