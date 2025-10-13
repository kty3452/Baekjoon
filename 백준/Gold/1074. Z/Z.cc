#include <iostream>
using namespace std;

int z(int n, int r, int c) {
    if (n == 0) return 0;  // 1x1이면 방문 순서 = 0
    int half = 1 << (n - 1);   // 블록 한 변의 절반
    int area = half * half;    // 블록 하나의 면적 (n-1 단계 블록 크기)

    // 4분면에 따라 offset 다름
    if (r < half && c < half)            // 1사분면 (왼위)
        return z(n - 1, r, c);
    if (r < half && c >= half)           // 2사분면 (오위)
        return area + z(n - 1, r, c - half);
    if (r >= half && c < half)           // 3사분면 (왼아래)
        return 2 * area + z(n - 1, r - half, c);
    return 3 * area + z(n - 1, r - half, c - half);  // 4사분면 (오아래)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;
    cout << z(n, r, c);
}
