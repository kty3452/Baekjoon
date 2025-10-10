// 마인크래프트

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, b;
    cin >> n >> m >> b;

    int ground[500][500] = {0, };

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> ground[i][j];
        }
    }

    int min_num = 500 * 500 * 256 + 1;
    int height = 0;

    for(int i = 0;i <= 256;i++){
        int block_needed = 0, inventory = b;
        for(int j = 0;j < n;j++){
            for(int k = 0;k < m;k++){
                if((ground[j][k] - i) > 0) inventory += (ground[j][k] - i);
                else if((ground[j][k] - i) < 0) block_needed += ((-1) * (ground[j][k] - i));
            }
        }
        if(inventory - block_needed >= 0 && min_num >= (inventory - b) * 2 + block_needed){
            min_num = (inventory - b) * 2 + block_needed;
            height = i;
        }
    }

    cout << min_num << " " << height;

    return 0;
}