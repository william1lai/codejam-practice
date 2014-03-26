#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool matches(char c1, char c2, char c3, char c4)
{
	if (c1 == '.' || c2 == '.' || c3 == '.' || c4 == '.')
		return false;
	if (c1 == 'T')
		return (c2 == c3 && c3 == c4);
	if (c2 == 'T')
		return (c1 == c3 && c3 == c4);
	if (c3 == 'T')
		return (c1 == c2 && c2 == c4);
	if (c4 == 'T')
		return (c1 == c2 && c2 == c3);
	return (c1 == c2 && c2 == c3 && c3 == c4);
}

char winner(vector<string> board)
{
	for (int r = 0; r < 4; r++)
	{
		if (matches(board[r][0], board[r][1], board[r][2], board[r][3]))
		{
			if (board[r][0] != 'T')
				return board[r][0];
			else
				return board[r][1];
		}
		if (matches(board[0][r], board[1][r], board[2][r], board[3][r]))
		{
			if (board[0][r] != 'T')
				return board[0][r];
			else
				return board[1][r];
		}
	}
	if (matches(board[0][0], board[1][1], board[2][2], board[3][3]))
	{
		if (board[0][0] != 'T')
			return board[0][0];
		else
			return board[1][1];
	}
	if (matches(board[0][3], board[1][2], board[2][1], board[3][0]))
	{
		if (board[0][3] != 'T')
			return board[0][3];
		else
			return board[1][2];
	}
	return '.';
}

int main()
{
	int ncases;
	cin >> ncases;
	cin.ignore(1000, '\n');

	for (int i = 1; i <= ncases; i++)
	{
		vector<string> board;
		string s;
		for (int j = 0; j < 4; j++)
		{
			getline(cin, s);
			board.push_back(s);
		}
		char c = winner(board);

		if (c == '.')
		{
			c = '-';
			for (int r = 0; r < 4; r++)
			{
				for (int cc = 0; cc < 4; cc++)
				{
					if (board[r][cc] == '.')
					{
						c = '.';
						break;
					}
				}
				if (c == '.')
					break;
			}
		}

		cout << "Case #" << i << ": ";
		if (c == '.')
			cout << "Game has not completed\n";
		else if (c == '-')
			cout << "Draw\n";
		else
			cout << c << " won\n";
		getline(cin, s);
	}
	return 0;
}