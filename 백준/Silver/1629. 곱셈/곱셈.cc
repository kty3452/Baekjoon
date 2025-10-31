#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;
    long long result = 1;
    while(b != 0){
        if(b & 1)
            result = (result * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    cout << result % c;

    return 0;

}