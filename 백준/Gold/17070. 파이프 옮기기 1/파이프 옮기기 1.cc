#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void backtracking(vector<vector<int>>& v, pair<int, int> behind, pair<int, int> front, int n){
    if(front == pair{n, n})
        cnt++;
    else{
        auto [dy, dx] = pair{abs(behind.first - front.first), abs(behind.second - front.second)};
        bool able_behind_y = (behind.first + 1 <= n);
        bool able_behind_x = (behind.second + 1 <= n);
        bool able_front_y = (front.first + 1 <= n);
        bool able_front_x = (front.second + 1 <= n);
        if(dy == 1 && dx == 1){ // 대각선 방향일 경우
            if(able_behind_y && able_behind_x && able_front_x && v[front.first][front.second + 1] == 0){
                backtracking(v, pair{behind.first + 1, behind.second + 1}, pair{front.first, front.second + 1}, n);
            }
            if(able_behind_y && able_behind_x && able_front_y && v[front.first + 1][front.second] == 0){
                backtracking(v, pair{behind.first + 1, behind.second + 1}, pair{front.first + 1, front.second}, n);
            }
            if(able_behind_y && able_behind_x && able_front_y && able_front_x && v[front.first + 1][front.second] == 0 && v[front.first][front.second + 1] == 0  && v[front.first + 1][front.second + 1] == 0){
                backtracking(v, pair{behind.first + 1, behind.second + 1}, pair{front.first + 1, front.second + 1}, n);
            }
        }
        else if(dx == 1){ // 가로 방향일 경우
            if(able_behind_x && able_front_x && v[front.first][front.second + 1] == 0){
                backtracking(v, pair{behind.first, behind.second + 1}, {front.first, front.second + 1}, n);
            }
            if(able_behind_x && able_front_x && able_front_y && v[front.first + 1][front.second] == 0 && v[front.first][front.second + 1] == 0  && v[front.first + 1][front.second + 1] == 0){
                backtracking(v, pair{behind.first, behind.second + 1}, {front.first + 1, front.second + 1}, n);
            }
        }
        else{ // 세로 방향일 경우
            if(able_behind_y && able_front_y && v[front.first + 1][front.second] == 0){
                backtracking(v, pair{behind.first + 1, behind.second}, {front.first + 1, front.second}, n);
            }
            if(able_behind_y && able_front_x && able_front_y && v[front.first + 1][front.second] == 0 && v[front.first][front.second + 1] == 0  && v[front.first + 1][front.second + 1] == 0){
                backtracking(v, pair{behind.first + 1, behind.second}, {front.first + 1, front.second + 1}, n);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> v;
    vector<int> sv;
    v.push_back(sv);

    for(int i = 0;i <= n + 1;i++){
        v[0].push_back(0);
    }

    for(int i = 1;i <= n;i++){
        v.push_back(sv);
        v[i].push_back(0);
        for(int j = 1;j <= n;j++){
            int a;
            cin >> a;
            v[i].push_back(a);
        }
        v[i].push_back(0);
    }
    v.push_back(sv);

    for(int i = 0;i <= n + 1;i++){
        v[n + 1].push_back(0);
    }

    backtracking(v, {1, 1}, {1, 2}, n);

    cout << cnt;
    
}