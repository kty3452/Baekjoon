#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int stair[n + 1] = {0, };
    for(int i = 1;i <= n;i++){
        cin >> stair[i];
    }
    int dp[n + 1][2] = {0, 0, stair[1],};
    for(int i = 2;i <= n;i++){
        dp[i][1] = stair[i] + dp[i - 1][0];
        dp[i][0] = dp[i - 2][1] > dp[i - 2][0] ? stair[i] + dp[i - 2][1] : stair[i] + dp[i - 2][0]; 
    }
    int result = 0;
    cout << (dp[n][0] > dp[n][1] ? dp[n][0] : dp[n][1]);

    return 0;
}