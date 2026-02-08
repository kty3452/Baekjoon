#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, b;
    cin >> n >> k >> b;
    vector<int> v(n + 1);
    while(b--){
        int idx;
        cin >> idx;
        v[idx] = -1;
    } // 0은 신호등 존재, -1은 신호등 부재.
    queue<int> sliding_win;
    int now = 0;
    for(int i = 1;i <= k;i++){
        sliding_win.push(v[i]);
        if(v[i] == -1) now++;
    }
    int best = now;
    for(int i = k + 1;i <= n;i++){
        if(sliding_win.front() == -1) now--;
        sliding_win.pop();
        if(v[i] == -1) now++;
        sliding_win.push(v[i]);
        if(now < best) best = now;
    }
    cout << best;
}