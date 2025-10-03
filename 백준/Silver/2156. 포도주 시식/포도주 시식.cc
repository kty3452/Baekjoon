// 포도주 시식

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int wines[10001] = {0, };
    for(int i = 1;i <= n;i++){
        cin >> wines[i];
    }
    int dp[10001][3] = {0, };
    dp[1][0] = wines[1];
    dp[1][1] = wines[1]; 

    for(int i = 2;i <= n;i++){
        dp[i][0] = max({dp[i - 3][0], dp[i - 3][1], dp[i - 2][0], dp[i - 2][1]}) + wines[i];
        dp[i][1] = dp[i - 1][0] + wines[i];
    }
    int max_num = 0;
    for(int i = 1;i <= n;i++){
        max_num = max({dp[i][0], dp[i][1], max_num});
    }
    cout << max_num;

    return 0;
}