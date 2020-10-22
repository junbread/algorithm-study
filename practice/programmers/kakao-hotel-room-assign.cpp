#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> assign_map;

long long assign(long long room_number, vector<long long> *history)
{
    auto search = assign_map.find(room_number);
    if (search == assign_map.end())
    {
        for (long long i : *history)
        {
            search = assign_map.find(i);
            search->second = room_number + 1;
        }
        delete history;

        assign_map.insert(make_pair(room_number, room_number + 1));
        return room_number;
    }
    else
    {
        history->push_back(room_number);
        return assign(search->second, history);
    }
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;

    for (long long i : room_number)
        answer.push_back(assign(i, new vector<long long>()));

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<long long> answers = solution(10, {1, 3, 4, 1, 3, 1});

    for (auto answer : answers)
        cout << answer << endl;

    return 0;
}
