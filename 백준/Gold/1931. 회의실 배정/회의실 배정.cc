#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> V;
    for(int i = 0;i < n;i++){
        int first, second;
        cin >> first >> second;
        V.push_back(make_pair(first, second));
    }
    sort(V.begin(), V.end(), cmp);
    
    int end_time = -1;
    int cnt = 0;
    for(auto i = V.begin();i != V.end();i++){
        if(end_time <= (*i).first) {
            end_time = (*i).second;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}