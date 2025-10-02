#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    int costs[N][3] = {0, };
    for(int i = 0;i < N;i++)
        for (int j = 0;j < 3;j++)
            cin >> costs[i][j]; 
    
    int dp[N][3] = {0, };
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    
    for(int i = 1;i < N;i++){
        dp[i][0] = costs[i][0] + (dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]);
        dp[i][1] = costs[i][1] + (dp[i - 1][2] < dp[i - 1][0] ? dp[i - 1][2] : dp[i - 1][0]);
        dp[i][2] = costs[i][2] + (dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1]);
    }

    cout << (dp[N - 1][0] < dp[N - 1][1]
        ? (dp[N - 1][0] < dp[N - 1][2] ? dp[N - 1][0] : dp[N - 1][2]) 
        : (dp[N - 1][1] < dp[N - 1][2] ? dp[N - 1][1] : dp[N - 1][2]));

    return 0;
}