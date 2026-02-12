/*
이건 그냥 슬라이딩 하면서 계속 빼고, 더하고 하면 될 듯? 그리 어렵진 않음.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> v;
    while(n--){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int total = 0, ans = 0;

    for(int l = 0, r = 0;r < v.size();r++){
        total += v[r];
        while(total >= s){
            ans = ans == 0 ? r - l + 1 : min(ans, r - l + 1);
            total -= v[l++];
        }
    }

    cout << ans;

    return 0;
}