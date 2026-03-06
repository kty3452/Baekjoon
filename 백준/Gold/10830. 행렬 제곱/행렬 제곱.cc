#include <bits/stdc++.h>
using namespace std;

// 행렬 곱 시에는 새 배열 만들기
// 단위행렬은 전부가 1이 아니라 대각선만 1

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, b;
    cin >> n >> b;

    long long temp = b, cnt = 1;
    while(temp > 0){
        temp >>= 1;
        cnt++;
    }

    vector<vector<vector<int>>> v(cnt + 1, vector<vector<int>>(n, vector<int>(n)));

    for(int r = 0;r < n;r++){
        for(int c = 0;c < n;c++){
            cin >> v[0][r][c];
        }
    }
    
    for(int i = 1;i <= cnt;i++){
        for(int r = 0;r < n;r++){
            for(int c = 0;c < n;c++){
                for(int k = 0;k < n;k++){
                    v[i][r][c] += (((v[i - 1][r][k] % 1000) * (v[i - 1][k][c] % 1000)) % 1000); 
                }
                v[i][r][c] %= 1000;
            }
        }
    }

    long long power = 1;
    vector<vector<int>> result(n, vector<int>(n, 0));

    for(int i = 0;i < n;i++){
        result[i][i] = 1;
    }

    for(int i = 0;i <= cnt;i++){
        long long max_num = (power << i);
        if(b & max_num){
            
            vector<vector<int>> temp(n, vector<int>(n, 0));
            for(int r = 0;r < n;r++){
                for(int c = 0;c < n;c++){
                    for(int k = 0;k < n;k++){
                        temp[r][c] += (((result[r][k] % 1000) * (v[i][k][c] % 1000)) % 1000); 
                    }
                    temp[r][c] %= 1000;
                }
            }
            
            for(int r = 0;r < n;r++){
                for(int c = 0;c < n;c++){
                    result[r][c] = temp[r][c];
                }
            }
            b ^= max_num;
        }
    }

    
    for(int r = 0;r < n;r++){
        for(int c = 0;c < n;c++){
            cout << result[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}