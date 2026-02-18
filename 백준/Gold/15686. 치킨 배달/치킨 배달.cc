#include <bits/stdc++.h>
using namespace std;

int min_num = INT_MAX;

void backtracking(int start, int m, int depth, vector<pair<int,int>>& v, vector<pair<int,int>>& house, vector<pair<int,int>>& chicken){
    if(depth == m){
        int temp = 0;
        for(auto h : house){
            int min_num2 = INT_MAX;
            for(auto c : v){
                int len = abs(c.first - h.first) + abs(c.second - h.second);
                min_num2 = min(min_num2, len);
            }
            temp += min_num2;
        }
        min_num = min(min_num, temp);
    }
    else{
        for(int i = start;i < chicken.size();i++){
            v.push_back(chicken[i]);
            backtracking(i + 1, m, depth + 1, v, house, chicken);
            v.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> house, chicken, v;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int a;
            cin >> a;
            if(a == 1) house.push_back({i, j});
            else if(a == 2) chicken.push_back({i, j});
        }
    }

    backtracking(0, m, 0, v, house, chicken);
    cout << min_num;
    

    return 0;
}