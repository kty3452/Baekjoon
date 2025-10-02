#include <iostream>
#include <algorithm>

using namespace std;


static int dp[100001][101] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N, K;
    cin >> N >> K;

    int mulguns[101][2] = {0, };
    for(int i = 1;i <= N;i++){
        cin >> mulguns[i][0] >> mulguns[i][1];
    }


    for(int i = 1;i <= K;i++){
        for(int j = 1;j <= N;j++){
            int W = mulguns[j][0];
            int V = mulguns[j][1];
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(i >= W){
                dp[i][j] = max(dp[i][j], dp[i - W][j - 1] + V);
            }
        }
    }
    cout << dp[K][N];

    return 0;
}