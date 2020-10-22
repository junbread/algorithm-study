#include <iostream>

using namespace std;

int N;
int arr[100000] = {0};
int buf[100000] = {0};
long long inversion = 0;

void merge_sort(int arr[], int size)
{
    if (size == 1)
        return;

    int mid = size / 2;

    merge_sort(arr, mid);
    merge_sort(arr + mid, size - mid);

    int first = 0, second = mid, cnt = 0;

    while (first < mid && second < size)
    {
        if (arr[first] < arr[second])
            buf[cnt++] = arr[first++];
        else if (arr[first] > arr[second])
        {
            buf[cnt++] = arr[second++];
            inversion += (mid - first);
        }
        else
            buf[cnt++] = arr[second++];
    }

    while (first < mid)
        buf[cnt++] = arr[first++];

    while (second < size)
        buf[cnt++] = arr[second++];

    for (int i = 0; i < size; i++)
        arr[i] = buf[i];
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        inversion = 0;
        merge_sort(arr, N);

        cout << "#" << test_case << " " << inversion << endl;
    }

    return 0;
}