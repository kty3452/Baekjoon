/*
1. 기약 분수를 구한다.
2. 분모의 역원을 구한다.
3. 분자와 분모의 역원을 곱한 값의 mod 1000000007 을 구한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    long long mod = 1000000007, result = 0;

    while(m--){
        long long n, s;
        cin >> n >> s;
        long long a = s, b = n;
        while(b != 0){
            int r = a % b;
            a = b;
            b = r;
        }
        s /= a;
        n /= a;

        a = 1;
        b = mod - 2;

        while(b != 0){
            if(b & 1) a = (a * n) % mod;
            n = (n * n) % mod;
            b >>= 1;
        }

        result += (s * a) % mod;
        result %= mod;
    }

    cout << result;

    return 0;
}