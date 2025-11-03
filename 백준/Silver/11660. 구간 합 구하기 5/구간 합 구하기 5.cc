#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    static int nums[1025][1025] = {0, };
    static int haps[1025][1025] = {0, };
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> nums[i][j];
            haps[i][j] = haps[i][j - 1] + nums[i][j];
        }
    }

    for(int i = 0;i < m;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        for(int i = x1;i <= x2;i++){
            result = result + (haps[i][y2] - haps[i][y1 - 1]);
        }
        cout << result << "\n";
    }

    return 0;
}