#define N 4

typedef struct
{
	int strike;
	int ball;
} Result;

extern Result query(int guess[]);


inline bool match(Result a, Result b)
{
	return a.strike == b.strike && a.ball == b.ball;
}

inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int arr[5040][N] = {0};
int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int skip[5040] = {0};
bool first = true;

void permutation(int depth)
{
	static int permutation_cnt = 0;
	if (depth == N)
	{
		for (int j = 0; j < N; j++)
			arr[permutation_cnt][j] = digits[j];

		permutation_cnt++;
		return;
	}

	for (int k = depth; k < 10; k++)
	{
		swap(digits[depth], digits[k]);
		permutation(depth + 1);
		swap(digits[depth], digits[k]);
	}
}

void init()
{
	if (first)
	{
		first = false;
		permutation(0);
	}

	for (int i = 0; i < 5040; i++)
		skip[i] = 0;
}

Result simulate(int ans[N], int guess[N])
{
	Result res;
	res.strike = 0;
	res.ball = 0;

	int cnt[10] = {0};
	for (int i = 0; i < N; i++)
	{
		if (ans[i] == guess[i])
			res.strike++;
		else
		{
			cnt[ans[i]]++;
			cnt[guess[i]]++;
		}
	}

	for (int i = 0; i < 10; i++)
		if (cnt[i] == 2)
			res.ball++;
	
	return res;
}

void doUserImplementation(int guess[])
{
	init();

	Result res;

	for (int i = 0; i < 5040; i++)
	{
		if (skip[i])
			continue;

		for (int j = 0; j < N; j++)
			guess[j] = arr[i][j];

		res = query(guess);

		if (res.strike == 0 && res.ball == 0) // no hit
			for (int j = 0; j < 5040; j++)
			{
				bool fin = false;
				for (int k = 0; !fin && k < N; k++)
					for (int l = 0; !fin && l < N; l++)
						if (arr[j][k] == guess[l])
						{
							skip[j] = 1;
							fin = true;
						}
			}
		else
		{
			if (res.strike == N)
				return;
			else
				for (int j = 0; j < 5040; j++)
					if(!skip[j] && !match(res, simulate(arr[j], guess)))
						skip[j] = 1;
		}
	}
}