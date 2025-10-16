#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string graph[100];

    for(int i = 0;i < n;i++){
        cin >> graph[i];
    }

    int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int visited[100][100] = {0, };
    queue<pair<int, int>> Q;

    int normal = 0, sackyack = 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    auto [cy, cx] = Q.front();
                    Q.pop();
                    for(auto i : move){
                        int ny = cy + i[0], nx = cx + i[1];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(!visited[ny][nx] && graph[cy][cx] == graph[ny][nx]){
                            visited[ny][nx] = 1;
                            Q.push({ny, nx});
                        }
                    }
                }
                normal++;
            }
        }
    }
    for(int i = 0;i < 100;i++){
        fill_n(visited[i], 100, 0);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    auto [cy, cx] = Q.front();
                    Q.pop();
                    for(auto i : move){
                        int ny = cy + i[0], nx = cx + i[1];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(!visited[ny][nx]){
                            if(graph[cy][cx] == graph[ny][nx] || ((graph[cy][cx] == 'R' || graph[cy][cx] == 'G') && (graph[ny][nx] == 'R' || graph[ny][nx] == 'G'))){
                                visited[ny][nx] = 1;
                                Q.push({ny, nx});
                            }
                        }
                    }
                }
                sackyack++;
            }
        }
    }

    cout << normal << " " << sackyack;

    return 0;
}