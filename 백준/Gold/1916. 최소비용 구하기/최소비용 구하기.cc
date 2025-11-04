#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    static int adm[1001][1001] = {0, };
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            adm[i][j] = 100000001;
        }
        adm[i][i] = 0;
    }

    while(m--){
        int start, end, cost;
        cin >> start >> end >> cost;
        if(cost < adm[start][end]) adm[start][end] = cost;
    }
    
    int start, end;
    cin >> start >> end;

    bool visited[1001] = {0, };
    visited[start] = true;
    int min_idx = 0;

    for(int i = 0;i < n - 1;i++){
        int min_num = 100000001;
        for(int j = 1;j <= n;j++){
            if(!visited[j] && adm[start][j] < min_num){
                min_num = adm[start][j];
                min_idx = j;
            }
        }
        visited[min_idx] = true;
        for(int j = 1;j <= n;j++){
            adm[start][j] = min(adm[start][j], adm[start][min_idx] + adm[min_idx][j]);
        }
    }
    cout << adm[start][end];

    return 0;
}