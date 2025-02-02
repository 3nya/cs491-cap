#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
int n, m, k;
vector<vector<int>> board;
int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},{0, -1},{0, 1},{1, -1}, {1, 0}, {1, 1}};

bool isValid(int row, int col) {
    if (board[row][col] == 1) return false;

    for (auto& dir : directions) {
        int newRow = row + dir[0];
        int newCol = col + dir[1];
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == 1) {
            return false;
        }
    }
    return true;
}
ll countWays(int placed, int startRow, int startCol) {
    if (placed == k) return 1;

    ll count = 0;
    for (int i = startRow; i < n; i++) {
        for (int j = (i == startRow ? startCol : 0); j < m; j++) {
            if (isValid(i, j)) {
                board[i][j] = 1;
                count += countWays(placed + 1, i, j + 1);
                board[i][j] = 0;
            }
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;


    board.assign(n, vector<int>(m, 0));

    cout << countWays(0, 0, 0) << "\n";

}