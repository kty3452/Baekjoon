// 케빈베이컨의 6단계 법칙

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int graph[101][101];
    for(int i = 1;i <= n;i++){
        fill_n(graph[i], n + 1, 101);
        graph[i][i] = 0;
    }
    for(int i = 0;i < m;i++){
        int y, x;
        cin >> y >> x;

        graph[y][x] = 1;
        graph[x][y] = 1;
    }

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    int min_num = 101 * 100;
    int min_idx = n;
    for(int i = n;i >= 1;i--){
        int sum = 0;
        for(int j = 1;j <= n;j++){
            sum += graph[i][j];
        }
        if(min_num >= sum){
            min_num = sum;
            min_idx = i;
        }
    }
    cout << min_idx;

    return 0;
}