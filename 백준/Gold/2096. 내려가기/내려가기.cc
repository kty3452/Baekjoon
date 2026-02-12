#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    static int nums[100001][3];
    static int dp[2][3] = {0, };
    
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 3;j++){
            cin >> nums[i][j];
        }
    }
    dp[0][0] = nums[0][0];
    dp[0][1] = nums[0][1];
    dp[0][2] = nums[0][2];
    for(int i = 1;i <= n;i++){
        dp[1][0] = nums[i][0] + max(dp[0][0], dp[0][1]);
        dp[1][1] = nums[i][1] + *max_element(dp[0], dp[0] + 3);
        dp[1][2] = nums[i][2] + max(dp[0][1], dp[0][2]);
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
    }
    cout << *max_element(dp[0], dp[0] + 3) << " ";
    
    fill_n(dp[0], 3, 0);
    fill_n(dp[1], 3, 0);
    
    for(int i = 1;i <= n;i++){
        dp[1][0] = nums[i][0] + min(dp[0][0], dp[0][1]);
        dp[1][1] = nums[i][1] + *min_element(dp[0], dp[0] + 3);
        dp[1][2] = nums[i][2] + min(dp[0][1], dp[0][2]);
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
    }
    cout << *min_element(dp[0], dp[0] + 3);
    

    return 0;
}