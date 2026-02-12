#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(100001);
    fill_n(v.begin(), 100001, 100001);
    queue<int> q;
    v[n] = 0;
    q.push(n);


    while(!q.empty()){
        int cv = q.front();
        q.pop();

        if(cv + 1 <= 100000 && v[cv + 1] > v[cv] + 1){
            v[cv + 1] = v[cv] + 1;
            q.push(cv + 1);
        }
        if(cv - 1 >= 0 && v[cv - 1] > v[cv] + 1){
            v[cv - 1] = v[cv] + 1;
            q.push(cv - 1);
        }
        if(cv << 1 <= 100000 && v[cv << 1] > v[cv]){
            v[cv << 1] = v[cv];
            q.push(cv << 1);
        }
    }

    cout << v[k];

    return 0;
}