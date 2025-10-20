#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--){
        int A, B; cin >> A >> B;
        bool visited[10000] = {false,};
        int from[10000];
        char how[10000];
        queue<int> Q;

        Q.push(A);
        visited[A] = true;

        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            if(cur == B) break;

            int D = (cur * 2) % 10000;
            int S = (cur == 0) ? 9999 : cur - 1;
            int L = (cur % 1000) * 10 + cur / 1000;
            int R = (cur % 10) * 1000 + cur / 10;

            int nxt[4] = {D, S, L, R};
            char op[4] = {'D', 'S', 'L', 'R'};

            for(int i=0;i<4;i++){
                if(!visited[nxt[i]]){
                    visited[nxt[i]] = true;
                    from[nxt[i]] = cur;
                    how[nxt[i]] = op[i];
                    Q.push(nxt[i]);
                }
            }
        }

        string res;
        for(int cur = B; cur != A; cur = from[cur]) 
            res += how[cur];
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
}
