#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Compare {
    bool operator()(long long a, long long b) const {
        if (llabs(a) == llabs(b)) return a > b; // 절댓값 같으면 실제값 작은 쪽(음수) 우선
        return llabs(a) > llabs(b);             // 절댓값 작은 쪽 우선
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<long long, vector<long long>, Compare> pq;
    int n; cin >> n;
    while (n--) {
        long long x; cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else pq.push(x);
    }
}
