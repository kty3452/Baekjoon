#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = n - 1;
    long long best = (1LL<<62);
    int bestL = arr[l], bestR = arr[r];

    while (l < r) {
        long long sum = 1LL * arr[l] + arr[r];
        long long gap = llabs(sum);

        if (gap < best) {
            best = gap;
            bestL = arr[l];
            bestR = arr[r];
            if (best == 0) break;
        }

        // 네가 원한 "브랜치 최소화" 형태 유지
        l += (sum < 0);
        r -= (sum > 0);
    }

    cout << bestL << ' ' << bestR;
    return 0;
}
