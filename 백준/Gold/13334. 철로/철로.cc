/*
1. 일단 각 h 혹은 o (둘 중 더 작은 값)에서 시작하는 선분을 그으면 됨.
2. 해당 시작 지점에서 확인한건 더 이상 확인할 필요 없음.
3. 빠른 제거와 삽입(힙 정렬?)
그럼.. 먼저 정렬을 해놓고(더 작은 지점 기준), 힙 솔트를 쓰면?
// nlogn + nlogn?
음.. 힙은 시작점 기준 정렬, 2차원 배열은 끝점 기준 정렬? 
선분의 시작점이 지나가버리면 그냥 빼버리면 되니까..
끝점 기준이라도 이미 끝점 오름차순이기에 선분 L의 시작점도 결국 계속 늘어날 수 밖에 없음. 총 n번 
시작점 기준으로 하면 L 범위에 포함되는 게 있을 수도 있어서 최적해를 보장할 수 없으나,
끝점 기준일 시, 해당 끝점 내에 존재하지 않는 것들은 다 범위에 포함되지 않는다는 것이 증명됨.
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void heapify_up(vector<pair<int, int>> &heap, int i){
    int p = i / 2;
    if(p == 0) return;
    if(heap[p].first > heap[i].first){
        swap(heap[p], heap[i]);
        heapify_up(heap, p);
    }
}
void heapify_down(vector<pair<int, int>> &heap, int i){
    int l = i * 2, r = i * 2 + 1;
    int smallest = i;
    if(l < heap.size() && heap[l].first < heap[smallest].first) smallest = l;
    if(r < heap.size() && heap[r].first < heap[smallest].first) smallest = r;
    if(i != smallest){
        swap(heap[smallest], heap[i]);
        heapify_down(heap, smallest);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    while(n--) {
        int h, o;
        cin >> h;
        cin >> o;
        if(h > o) swap(h, o);
        v.push_back({h, o});
    }
    sort(v.begin(), v.end(), compare);

    int d, max = 0;
    cin >> d;

    vector<pair<int, int>> heap = {{0, 0}};

    for(int i = 0;i < v.size();i++){
        int x = v[i].second - d; // L의 시작점
        while(heap.size() > 1 && heap[1].first < x){ //시작지점이 지나버린 놈들은 빼버리기
            heap[1] = heap[heap.size() - 1];
            heap.pop_back();
            heapify_down(heap, 1);   
        }
        if(v[i].second - v[i].first <= d){
            heap.push_back({v[i].first, v[i].second});
            heapify_up(heap, heap.size() - 1);
        }
        if(max < heap.size() - 1) max = heap.size() - 1;
    }

    cout << max;

    return 0;
}