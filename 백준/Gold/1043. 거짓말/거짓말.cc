#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<bool> know_true(n + 1);
    vector<vector<bool>> adm(n + 1, vector<bool>(n + 1));
    vector<vector<int>> history;

    int hmkt;
    cin >> hmkt;
    while(hmkt--){
        int temp;
        cin >> temp;
        q.push(temp);
        know_true[temp] = true;
    }

    int cnt = m;
    vector<int> sv;

    for(int i = 0;i < m;i++){
        int temp;
        cin >> temp;
        history.push_back(sv);
        while(temp--){
            int num;
            cin >> num;
            history[i].push_back(num);
        }
        for(int j = 0;j < history[i].size();j++){
            for(int k = 0;k < history[i].size();k++){
                adm[history[i][j]][history[i][k]] = true;
            }
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 1;i <= n;i++){
            if(adm[now][i] && !know_true[i]){
                know_true[i] = true;
                q.push(i);
            }
        }
    }
    for(auto h : history){
        for(auto a : h){
            if(know_true[a]){
                cnt--;
                break;
            }
        }
    }

    cout << cnt;
}