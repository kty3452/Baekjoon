// 파도반 수열

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long int dp[101] = {0, 1, 1, 1, 2, 2, };
        for(int i = 6;i <= n;i++){
            dp[i] = dp[i - 1] + dp[i - 5];
        }
        cout << dp[n] << "\n";
    }
    return 0;
}