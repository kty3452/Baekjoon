#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int dp[100000][2];
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < n;j++){
                cin >> dp[j][i];
            }
        }
        dp[1][0] = dp[1][0] + dp[0][1];
        dp[1][1] = dp[1][1] + dp[0][0];
        for(int i = 2;i < n;i++){
            dp[i][0] = dp[i][0] + max(dp[i - 1][1], dp[i - 2][1]);
            dp[i][1] = dp[i][1] + max(dp[i - 1][0], dp[i - 2][0]);
        }
        cout << *max_element(dp[n - 1], dp[n - 1] + 2) << "\n";
    }
    return 0;
}