#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;
    int k;
    cin >> k;

    vector<vector<pair<int, int>>> adj(v + 1);

    while(e--){
        int s, n, w;
        cin >> s >> n >> w;
        adj[s].push_back({n, w});
    }

    vector<int> dist(v + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // 우선순위 큐를 통해 현재 기준 정점에 연결된 값 중에서 가장 작은 값을 출력
    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()){
        auto [cost, now] = pq.top();
        pq.pop();

        if(cost > dist[now]) continue; // 이미 더 작은 값으로 갱신된 경로라면 무시

        for(auto [next, weight] : adj[now]){ // 해당 정점에 연결된 모든 정점 확인
            if(dist[next] > cost + weight){
                dist[next] = cost + weight;
                pq.push({dist[next], next});
            }
        }
    }

    for(int i = 1;i < dist.size();i++){
        if(dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}