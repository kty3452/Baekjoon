#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_num = 0;
    cin >> n;
    vector<vector<pair<int, int>>> adj;
    vector<int> visited;
    stack<int> s;
    adj.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 0;i < n - 1;i++){
        int p, c, w;
        cin >> p >> c >> w;
        adj[p].push_back(pair{c, w});
        adj[c].push_back(pair{p, w});
    }

    for(int i = 1;i <= n;i++){
        s.push(i);
        visited[i] = 1;
        while(!s.empty()){
            int now = s.top();
            s.pop();
            for(auto [next, w] : adj[now]){
                if(!visited[next]){
                    s.push(next);
                    visited[next] = visited[now] + w;
                    max_num = max(visited[next] - 1, max_num);
                }
            }
        }
        visited.assign(n + 1, 0);
    }

    cout << max_num;

    return 0;
}