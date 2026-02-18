#include <bits/stdc++.h>
using namespace std;

int n;
int board[17][17];
long long cnt = 0;

void dfs(int y, int x, int dir) {
    // (y, x)는 파이프의 끝점

    if (y == n && x == n) {
        cnt++;
        return;
    }

    // 0 = 가로, 1 = 세로, 2 = 대각선

    // ▶ 가로 or 대각선 → 오른쪽 이동 가능
    if (dir == 0 || dir == 2) {
        if (x + 1 <= n && board[y][x + 1] == 0) {
            dfs(y, x + 1, 0);
        }
    }

    // ▼ 세로 or 대각선 → 아래 이동 가능
    if (dir == 1 || dir == 2) {
        if (y + 1 <= n && board[y + 1][x] == 0) {
            dfs(y + 1, x, 1);
        }
    }

    // ↘ 모든 방향에서 대각선 이동 가능
    if (y + 1 <= n && x + 1 <= n &&
        board[y][x + 1] == 0 &&
        board[y + 1][x] == 0 &&
        board[y + 1][x + 1] == 0) {

        dfs(y + 1, x + 1, 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    dfs(1, 2, 0);  // 초기 상태 (가로)

    cout << cnt;
}
