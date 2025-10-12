// 경로 찾기

#include <iostream>
#include <queue>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> V[101];
    queue<int> Q;
    int answer[101][101] = {0, };
    for(int i = 1;i <= n;i++){
        int islink;
        for(int j = 1;j <= n;j++){
            cin >> islink;
            if(islink){
                V[i].push_back(j);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        bool visited[101] = {0, };
        Q.push(i);
        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            for(int j = 0;j < V[node].size();j++){
                if(!visited[V[node][j]]){
                    Q.push(V[node][j]);
                    visited[V[node][j]] = 1;
                }
            }
        }
        copy(visited, visited + 101, answer[i]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}