#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int nums[1000] = {0, };
    int dp[1000] = {0, };
    fill_n(dp, n, 1);
    for(int i = 0;i < n;i++) cin >> nums[i];
    for(int i = n - 1;i >= 0;i--){
        for(int j = i + 1;j < n;j++){
            if(nums[j] > nums[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp, dp + n);

    
    return 0;
}