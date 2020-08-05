#include <iostream>

using namespace std;

long long S[200000];
long long A[200000];

int main(int argc, char **argv)
{
    int T, N;
    long long max;

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> A[i];

        S[0] = A[0];
        max = S[0];

        for (int i = 1; i < N; i++)
        {
            S[i] = (A[i] > S[i - 1] + A[i]) ? A[i] : S[i - 1] + A[i];
            max = S[i] > max ? S[i] : max;
        }

        cout << "#" << test_case << " " << max << endl;
    }

    return 0;
}