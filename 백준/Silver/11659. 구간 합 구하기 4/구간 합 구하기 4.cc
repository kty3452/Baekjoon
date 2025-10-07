// 구간 합 구하기 4

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    static int sums[100001] = {0, };
    for(int i = 1;i <= n;i++){
        cin >> sums[i];
    }
    for(int i = 2;i <= n;i++){
        sums[i] = sums[i - 1] + sums[i];
    }
    for(int i = 0;i < m;i++){
        int start, end;
        cin >> start >> end;

        cout << sums[end] - sums[start - 1] << "\n";
    }

    return 0;
}