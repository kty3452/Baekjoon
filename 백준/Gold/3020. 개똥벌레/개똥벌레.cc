/*
최악의 경우 200000 * 500000 = 100000000000 1000억...
그럼.. 뭔가 방법이 있어야 하는데.. logn? 어떻게?
아니면 n을 한 번씩만 지나도 확정이 나도록? 음..
꼭 다 갱신할 필요 없이, 해당 인덱스에서만 +1 하면 되는거 아닌가?
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;

    vector<int> sucksoon(h + 2);
    vector<int> jongyusuck(h + 2);

    while(n--){
        int temp;
        cin >> temp;
        if(n & 1 == 1)sucksoon[temp]++;
        else jongyusuck[h - temp + 1]++;
    }

    vector<int> result(h + 1);

    for(int i = 1;i <= h;i++){
        result[i] += jongyusuck[i];
        jongyusuck[i + 1] += jongyusuck[i];
    }
    for(int i = h;i >= 1;i--){
        result[i] += sucksoon[i];
        sucksoon[i - 1] += sucksoon[i];
    }
    
    int low = *min_element(result.begin() + 1, result.end());
    int cnt = 0;
    for(int i = 1;i <= h;i++){
        if(result[i] == low) cnt++;
    }

    cout << low << " " << cnt;    

    return 0;
}