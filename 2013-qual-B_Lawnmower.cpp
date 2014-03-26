#include <iostream>

using namespace std;

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 1; i <= ncases; i++)
	{
		int r, c;
		cin >> r >> c;

		int** lawn = new int*[r];
		for (int j = 0; j < r; j++)
		{
			lawn[j] = new int[c];
			for (int k = 0; k < c; k++)
				cin >> lawn[j][k];
		}

		bool possible = true;
		//make sure there exists a row or column cutting through each square with all values <= to square value
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				int val = lawn[j][k];
				bool rowposs = true;
				for (int cc = 0; cc < c; cc++)
				{
					if (lawn[j][cc] > val)
						rowposs = false;
				}
				bool colposs = true;
				for (int rr = 0; rr < r; rr++)
				{
					if (lawn[rr][k] > val)
						colposs = false;
				}

				if (!rowposs && !colposs)
				{
					possible = false;
					break;
				}
			}
			if (!possible)
				break;
		}

		cout << "Case #" << i << ": ";
		if (possible)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}