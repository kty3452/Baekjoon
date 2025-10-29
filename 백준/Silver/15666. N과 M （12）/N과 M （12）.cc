#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V;
vector<int> temp;

void backtracking(int n, int m){
    if(temp.size() == m){
        for(auto a : temp) cout << a << " ";
        cout << "\n";
        return;
    }
    int prev = -1;
    for(int i = 0;i < n;i++){
        if(temp.size() > 0 && V[i] < temp[temp.size() - 1]) continue;
        if(prev == V[i]) continue;

        temp.push_back(V[i]);
        prev = V[i];
        backtracking(n, m);
        temp.pop_back();
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    V.resize(n);
    for(int i = 0;i < n;i++) cin >> V[i];
    sort(V.begin(), V.end());

    backtracking(n, m);

    return 0;
}