// 오르막 수

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[1001][10] = {0, };
    for(int i = 0;i < 10;i++)
        dp[1][i] = 1;

    for(int i = 2;i <= n;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k <= j;k++){
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    int result = 0;
    for(int i = 0;i < 10;i++){
        result += dp[n][i];
        result %= 10007;
    }
    cout << result;

    return 0;
}