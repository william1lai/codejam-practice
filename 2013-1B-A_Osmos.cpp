#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
	{
		int A, N, temp;
		cin >> A >> N;
		vector<int> motes;
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			motes.push_back(temp);
		}
		sort(motes.begin(), motes.end()); //N LOG N

		int ops;
		int start = 0;
		while (start < N && A > motes[start])
		{
			A = A + motes[start];
			start++;
		}
		if (start == N)
			ops = 0;
		else
		{
			ops = N - start;
			int temp_ops = 0;
			bool done = false;
			while (!done)
			{
				A = A + A - 1;
				temp_ops++;
				done = temp_ops >= ops;
				while (start < N && A > motes[start])
				{
					A = A + motes[start];
					start++;
				}
				if (temp_ops + N - start < ops)
					ops = temp_ops + N - start;
				if (start == N)
					break;
			}
		}

		cout << "Case #" << i << ": " << ops << "\n";
	}
	return 0;
}