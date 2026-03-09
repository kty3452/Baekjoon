#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1, vector<int>(n + 1, 10000001));

    while(m--){
        int f, s, w;
        cin >> f >> s >> w;
        v[f][s] = min(v[f][s], w);
    }

    for(int i = 0;i <= n;i++){
        v[i][i] = 0;
    }

    for(int k = 1;k <= n;k++){
        for(int s = 1;s <= n;s++){
            for(int e = 1;e <= n;e++){
                v[s][e] = min(v[s][e], v[s][k] + v[k][e]);
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(v[i][j] > 10000000) cout << "0 ";
            else cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}