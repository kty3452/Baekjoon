#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board;
vector<int> dist;
vector<pair<int, int>> mv = {pair{1, 0}, pair{-1, 0}, pair{0, 1}, pair{0, -1}};
int max_num = 1;

void dfs(vector<int>& dist, int r, int c){
    for(auto [dr, dc] : mv){
        int nr = r + dr;
        int nc = c + dc;
        if(board[nr][nc] != 'a' && !dist[board[nr][nc] - 'A']){
            dist[board[nr][nc] - 'A'] = dist[board[r][c] - 'A'] + 1;
            dfs(dist, nr, nc);
            max_num = max(dist[board[nr][nc] - 'A'], max_num);
            dist[board[nr][nc] - 'A'] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    board.resize(r + 2, vector<char>(c + 2, 'a'));
    dist.resize(26);

    for(int i = 1;i <= r;i++){
        string s;
        cin >> s;
        for(int j = 1;j <= s.size();j++){
            board[i][j] = s[j - 1];
        }
    }

    dist[board[1][1] - 'A'] = 1;
    
    dfs(dist, 1, 1);

    cout << max_num;

    return 0;
}

