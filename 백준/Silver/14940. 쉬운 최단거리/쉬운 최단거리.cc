// 쉬운 최단 거리

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    static int graph[1001][1001] = {0, };
    int start[2] = {0, 0};

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> graph[i][j];
            if(graph[i][j] == 2){
                start[0] = i;
                start[1] = j;
            }
        }
    }
    int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    static int visited[1001][1001];
    queue<pair<int, int>> Q;
    
    Q.push({start[0], start[1]});
    visited[start[0]][start[1]] = 0;
    
    while(!Q.empty()){
        auto [cy, cx] = Q.front();
        Q.pop();
        for(auto[movey, movex] : move){
            int ny = cy + movey;
            int nx = cx + movex;
            if(ny < 0 || ny > n || nx < 0 || nx > m) continue;
            if(graph[ny][nx] == 1 && !visited[ny][nx]){
                visited[ny][nx] = visited[cy][cx] + 1;
                Q.push({ny, nx});
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(graph[i][j] == 1 && visited[i][j] == 0) cout << "-1 ";
            else cout << visited[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}