#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board;
vector<pair<int,int>> mv = {{1,0},{-1,0},{0,1},{0,-1}};
int R,C;
int ans = 0;

void dfs(int r,int c,int mask,int depth){
    ans = max(ans, depth);

    for(auto [dr,dc] : mv){
        int nr = r + dr;
        int nc = c + dc;

        char ch = board[nr][nc];
        if(ch=='a') continue;

        int idx = ch - 'A';

        if(mask & (1<<idx)) continue;

        dfs(nr,nc,mask | (1<<idx), depth+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>R>>C;

    board.resize(R+2, vector<char>(C+2,'a'));

    for(int i=1;i<=R;i++){
        string s;
        cin>>s;
        for(int j=1;j<=C;j++)
            board[i][j]=s[j-1];
    }

    int start = 1<<(board[1][1]-'A');

    dfs(1,1,start,1);

    cout<<ans;
}