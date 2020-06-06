#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int N;
	int arr[11];

	vector<int> ops;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int n_op;
	for (int i = 0; i < 4; i++)
	{
		cin >> n_op;

		for (int j = 0; j < n_op; j++)
			ops.push_back(i);
	}

	int max = INT_MIN, min = INT_MAX;
	do
	{
		int res = arr[0];
		for (int i = 0; i < ops.size(); i++)
			switch (ops[i])
			{
			case 0:
				res += arr[i + 1];
				break;
			case 1:
				res -= arr[i + 1];
				break;
			case 2:
				res *= arr[i + 1];
				break;
			case 3:
				res /= arr[i + 1];
				break;
			}

		max = max > res ? max : res;
		min = min < res ? min : res;

	} while (next_permutation(ops.begin(), ops.end()));

	cout << max << endl << min << endl;

	return 0;
}