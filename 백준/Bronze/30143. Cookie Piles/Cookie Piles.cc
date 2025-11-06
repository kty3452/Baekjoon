#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, a, d;
        cin >> n >> a >> d;
        int result = 0;
        for(int i = 0;i < n;i++){
            result += a;
            a += d;
        }
        cout << result << "\n";
    }
    
    return 0;
}