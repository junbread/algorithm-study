#include <iostream>
#include <vector>

using namespace std;

int n, b, c;
vector<int> students;


int main()
{
    cin >> n;

    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        students.push_back(t);
    }

    cin >> b >> c;

    long long num = n;

    for (int i = 0; i < n; i++)
    {
        students[i] -= b;
        if (students[i] > 0)
        {
            int temp = students[i] / c;
            if (students[i] % c > 0)
                temp++;

            num += temp;
        }
    }

    cout << num;

    return 0;
}