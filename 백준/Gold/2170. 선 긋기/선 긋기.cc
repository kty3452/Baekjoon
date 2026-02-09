/*
선의 시작 부분 기준으로 정렬하면 뒤에 오는 선분은 앞에 오는 선분과 겹치거나 뒤에 있음이 보장됨.
즉 두 선분 A, B가 있고, x 기준 오름차순 정렬이면 xA <= xB가 보장. 
따라서 앞에 있는 선분의 끝 부분만 고려하여 다음 선분의 시작이 끝부분과 겹치는지 아닌지만 알면됨.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    while(n--){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int total_len = v[0].second - v[0].first;
    int last = v[0].second;
    for(int i = 1;i < v.size();i++){
        if(v[i].first >= last){ //겹치지 않을 경우 그대로 추가
            total_len += (v[i].second - v[i].first);
            last = v[i].second;
        }
        else if(v[i].second >= last){ // 겹치는 부분이 있을 경우 겹치는 길이만큼을 제외하고 추가
            total_len += (v[i].second - last);
            last = v[i].second;
        }
        // 참고로 후에 나오는 선분이 전 선분에 포함되어 있는 경우에는 길이가 변하지 않음.
    }
    cout << total_len;

    return 0;
}