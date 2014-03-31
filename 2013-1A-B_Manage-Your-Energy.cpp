#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int64;
vector<int64> schedule;

int64 compute(int64 E, int64 R, int64 N)
{
	if (R > E)
		R = E;
	int64** dp = new int64*[N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int64[E - R + 1];
		for (int j = 0; j < E - R + 1; j++)
			dp[i][j] = 0;
	}
	for (int j = 0; j < E - R + 1; j++)
	{
		dp[0][j] = schedule[0]*(E-j);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < E - R + 1; j++)
		{
			int64 maxi = -1;
			for (int k = max(0LL, j - R); k <= E - R; k++)
			{
				int64 temp = dp[i-1][k] + (k + R - j)*schedule[i];
				if (temp > maxi)
					maxi = temp;
			}
			dp[i][j] = maxi;
		}
	}
	return dp[N-1][0];
}

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
	{
		int64 E, R, N;
		cin >> E >> R >> N;
		int64 temp;
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			schedule.push_back(temp);
		}
		int64 ans = compute(E, R, N);
		cout << "Case #" << i << ": " << ans << "\n";
		schedule.clear();
	}
	return 0;
}