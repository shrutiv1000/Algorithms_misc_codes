// leetcode - n queens
// https://leetcode.com/problems/n-queens/

vector<vector<string>> ans;

bool inBoard(int x, int y, int n) {
	return (x >= 0 and x < n and y >= 0 and y < n);
}

bool isSafe(vector<string> board, int n, int x, int y) {
	for (int i = 0 ; i < n ; i++)
		if (board[i][y] == 'Q' or board[x][i] == 'Q')
			return false;

	for (int i = -n ; i < n ; i++)
		if (inBoard(x + i, y + i, n) and board[x + i][y + i] == 'Q')
			return false;

	for (int i = -n ; i < n ; i++)
		if (inBoard(x - i, y + i, n) and board[x - i][y + i] == 'Q')
			return false;

	return true;
}

void solve(vector<string> board, int n, int queens, int row)
{
	if (queens == 0) {
		ans.push_back(board);
		return;
	}

	for (int i = 0 ; i < n ; i++) {
		int x = row;
		int y = i;

		if (inBoard(x, y, n) and isSafe(board, n, x , y)) {
			board[x][y] = 'Q';
			solve(board, n, queens - 1, row + 1);
			board[x][y] = '.';
		}
	}
}

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		ans.clear();

		int queens = n;

		string temp;
		
		for (int i = 0 ; i < n; i++) 
			temp += '.';

		vector<string> board(n, temp);
		solve(board, n, queens, 0);

		return ans;
	}
};