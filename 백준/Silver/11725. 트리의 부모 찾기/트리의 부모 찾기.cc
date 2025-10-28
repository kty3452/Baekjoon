#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    static int parent[100001] = {0, 1, };
    vector<vector<int>> edges(n + 1);
    for(int i = 0;i < n - 1;i++){
        int num, num2;
        cin >> num >> num2;
        edges[num].push_back(num2);
        edges[num2].push_back(num);
    }

    queue<int> Q;
    const int root = 1;
    Q.push(root);
    while(!Q.empty()){
        int cv = Q.front();
        Q.pop();

        for(auto nv : edges[cv]){
            if(!parent[nv]){
                Q.push(nv);
                parent[nv] = cv;
            }
        }
    }
     
    for(int i = 2;i <= n;i++)
        cout << parent[i] << "\n";
    return 0;
}