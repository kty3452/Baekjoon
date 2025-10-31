#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int prev[501] = {0, };
    cin >> prev[1];
    int cur[501] = {0, };
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= i;j++){
            cin >> cur[j];
            cur[j] += max(prev[j - 1], prev[j]);
        }
        for(int j = 1;j <= i;j++)
            prev[j] = cur[j];
    }
    cout << *max_element(prev + 1, prev + n + 1);
    
    return 0;
}