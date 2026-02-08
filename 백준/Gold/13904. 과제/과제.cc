/*
2109와 똑같은 스타일. 여기서는 가치순 정렬 후, UF로 풀어보겠음.
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int find(vector<int>& unf, int a){
    if(unf[a] == a) return a;
    return unf[a] = find(unf, unf[a]);
}

void Union(vector<int>& unf, int a, int b){
    int fa = find(unf, a);
    int fb = find(unf, b);
    if(fa != fb){
        unf[fa] = fb;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> dw;
    while(n--){
        int d, w;
        cin >> d >> w;
        dw.push_back({d, w});
    }
    sort(dw.begin(), dw.end(), compare);

    vector<int> unf(1001);
    for(int i = 0;i <= 1000;i++){
        unf[i] = i;
    }
    
    int total = 0;

    for(int i = 0;i < dw.size();i++){
        int idx = find(unf, dw[i].first);
        if(idx > 0) {
            total += dw[i].second;
            Union(unf, idx, idx - 1);
        }
    }

    cout << total;
    
    return 0;
}