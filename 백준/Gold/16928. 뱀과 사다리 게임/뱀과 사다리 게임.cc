#include <iostream>
#include <queue>

using namespace std;

void bfs(int visited[], queue<int> &Q, int sadari[], int snake[]){
    while(!Q.empty()){
        int cv = Q.front();
        Q.pop();
        
        if(sadari[cv]){
            int nv = sadari[cv];
            if(!visited[nv] || visited[nv] > visited[cv]){
                visited[nv] = visited[cv];
                Q.push(nv);
            }
        }
        else if(snake[cv]){
            int nv = snake[cv];
            if(!visited[nv] || visited[nv] > visited[cv]){
                visited[nv] = visited[cv];
                Q.push(nv);
            }
        } 
        else{
            for(int i = 1;i <= 6;i++){
                int nv = cv + i;
                if(nv > 100) break;
                if(!visited[nv] || visited[nv] > visited[cv] + 1){
                    visited[nv] = visited[cv] + 1;
                    Q.push(nv);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int sadari[101] = {0, };
    int snake[101] = {0, };
    for(int i = 1;i<=n;i++){
        int from, to;
        cin >> from >> to;
        sadari[from] = to;
    }    
    for(int i = 1;i<=m;i++){
        int from, to;
        cin >> from >> to;
        snake[from] = to;
    }

    int visited[101] = {0, };
    queue<int> Q;
    Q.push(1);
    visited[1] = 1;
    bfs(visited, Q, sadari, snake);
    cout << visited[100] - 1;
    
    return 0;
}