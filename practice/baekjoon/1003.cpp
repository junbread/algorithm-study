/*
 *  Problem No: 1003
 *  Date: 2020-01-06
 *  Type: Dynamic Programming 
 */
#include <cstdio>

int dp[42];

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (dp[n + 1] == 0)
        return dp[n + 1] = fibonacci(n - 1) + fibonacci(n - 2);
    else
        return dp[n + 1];
}

int main()
{
    int max, num;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;

    scanf("%d", &max);
    for (int i = 0; i < max; i++)
    {
        scanf("%d", &num);
        fibonacci(num);

        printf("%d %d\n", dp[num], dp[num + 1]);
    }

    return 0;
}
