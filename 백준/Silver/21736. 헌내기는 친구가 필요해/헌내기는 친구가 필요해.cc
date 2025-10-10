// 헌내기는 친구가 필요해

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int visited[600][600] = {0, };
    string graph[600] = {"", };

    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i = 0;i < n;i++){
        cin >> graph[i];
        if(graph[i].find("I") != string::npos){
            y = i;
            x = graph[i].find("I"); 
            visited[y][x] = 1;
        }
    }

    int move[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int cnt = 0;
    queue<pair<int, int>> queue;
    queue.push({y, x});

    while(!queue.empty()){
        auto [cy, cx] = queue.front();
        queue.pop();
        for(int i = 0;i < 4;i++){
            int ny = cy + move[i][0];
            int nx = cx + move[i][1];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] == 0 && graph[ny][nx] != 'X'){
                if(graph[ny][nx] == 'P') cnt++;
                queue.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }   
    }
    if(cnt == 0) cout << "TT";
    else cout << cnt;


    return 0;
}