#include <iostream>
using namespace std;

// 비트 교차 (r, c → morton code)
int morton_order(int r, int c) {
    int res = 0;
    for (int i = 0; i < 15; i++) { // n ≤ 15 (2^15 = 32768)
        res |= ((r >> i) & 1) << (2 * i + 1); // r의 i번째 비트를 2*i+1위치에
        res |= ((c >> i) & 1) << (2 * i);     // c의 i번째 비트를 2*i위치에
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;
    cout << morton_order(r, c);
}
