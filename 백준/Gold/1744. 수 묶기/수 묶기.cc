#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> min, plus;
    int total = 0;
    while(n--){
        int num;
        cin >> num;
        if(num < 1) min.push_back(num);
        else if(num > 1) plus.push_back(num);
        else total++;
    }
    sort(min.begin(), min.end());
    if((min.size() & 1) == 1) min.push_back(1);
    for(int i = 0;i < min.size();i+=2){
        total += (min[i] * min[i + 1]);
    }
    sort(plus.begin(), plus.end(), greater<>());
    if((plus.size() & 1) == 1) plus.push_back(1);
    for(int i = 0;i < plus.size();i+=2){
        total += (plus[i] * plus[i + 1]);
    }

    cout << total;

    return 0;
}