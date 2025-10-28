#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<int>> S;

void backtracking(int n, int m, vector<int>& V, vector<bool>& visited, vector<int>& temp){
    if(temp.size() == m){
        S.insert(temp);
    }
    else{
        for(int i = 0;i < n;i++){
            if(visited[i]) continue;
            temp.push_back(V[i]);
            visited[i] = true;
            backtracking(n, m, V, visited, temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> V(n);
    vector<bool> visited(n);
    vector<int> temp;
    for(int i = 0;i < n;i++) 
        cin >> V[i];
    sort(V.begin(), V.end());


    backtracking(n, m, V, visited, temp);

    for(auto s : S){
        for(auto v : s){
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}