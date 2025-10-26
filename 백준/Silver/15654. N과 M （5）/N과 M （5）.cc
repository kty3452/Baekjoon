#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void backtracking(vector<int>& V, int n, int m, int nums[], bool check_exists_num[]) {
    if (V.size() == m) {
        for (int x : V) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!check_exists_num[nums[i]]){
            V.push_back(nums[i]);
            check_exists_num[nums[i]] = true;
            backtracking(V, n, m, nums, check_exists_num);
            V.pop_back();
            check_exists_num[nums[i]] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> V;
    int nums[9] = {0, };
    for(int i = 0;i < n;i++) cin >> nums[i];
    sort(nums, nums + n);
    bool check_exists_num[10001] = {false, };
    backtracking(V, n, m, nums, check_exists_num);
}
