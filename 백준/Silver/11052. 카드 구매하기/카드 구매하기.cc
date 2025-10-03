// 카드 구매하기

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    int card_costs[1001] = {0, };
    for(int i = 1;i <= n;i++){
        cin >> card_costs[i];
    }
    int dp[1001] = {0, };
    

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = n;k >= i;k--){
                dp[k] = max(dp[k], dp[k - i] + card_costs[i]);
            }
        }
    }


    cout << dp[n];

    return 0;
}