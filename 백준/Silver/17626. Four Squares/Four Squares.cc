// Four Squares

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    static int dp[50001];
    vector<int> pownum = {1, };
    dp[1] = 1;
    dp[2] = 2;
    int idx = 1;
    for(int i = 3;i <= n;i++){
        if(i == ((int)sqrt(i) * (int)sqrt(i))) {
            dp[i] = 1;
            pownum.push_back(i);
        }
        else{
            dp[i] = i;
            for(int j = 0;j < pownum.size();j++){
                dp[i] = min(dp[i], dp[i - pownum[j]] + 1);
            }
        }
    }
    

    cout << dp[n];
}