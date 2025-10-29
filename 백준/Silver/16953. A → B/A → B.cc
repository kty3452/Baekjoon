#include <iostream>
#include <queue>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    queue<pair<int, int>> Q;
    Q.push({b, 1});
    bool check = false;
    int cnt = 1;
    int next = 1, current = 0;

    while(!Q.empty()){
        auto [cv, pos] = Q.front();
        Q.pop();
        int nv = cv % 2 == 0 ? cv / 2 : 0;
        if(nv != 0){
            if(nv == a){
                check = true;
                cout << pos + 1;
                break;
            }
            if(nv < a){
                continue;
            }
            Q.push({nv, pos + 1});
        }
        nv = cv % 10 == 1 ? (cv - 1) / 10 : 0;
        if(nv != 0){
            if(nv == a){
                check = true;
                cout << pos + 1;
                break;
            }
            if(nv < a){
                continue;
            }
            Q.push({nv, pos + 1});
        }
    }
    if(!check) cout << -1;
    return 0;
}