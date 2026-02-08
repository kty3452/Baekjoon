/*
1. 이건 굉장히 간단한듯? 일단 정석대로 다 돌려면 대충 n세제곱? 정확하진 않은데, 이러면 시간초과
2. 그럼 각 날짜마다 최적의 강의를 골라서 넣으면 될 듯?
3. 그런데 시작 날짜부터 계산하면 놓치는게 분명히 있음.
4. 예를 들어 80 2, 50 2, 10 1, 60 1 일 때, 1일 이내 부터 계산을 하면 60을 놓치게 됨.
5. 따라서 남은 시간 순 대로 내림차순(오름차순 하고 끝 부터 확인)한 배열을 가치 기준 최대 힙에 넣어서 뽑으면 될 듯? 미래(10000일 후)에서 현재까지 오는 느낌.
6. 약간 지난번에 푼 가방 문제하고 비슷한데.. 경우의 수가 적은 것부터 먼저 하는 것이 이런 문제의 핵심인듯?
7. 다만 지난번 가방 문제는 무게 기준 정렬하고 가치 기준 최대 힙 말고도, 가치 순 정렬 + 유니온 파인드로도 풀렸는데, 이건 안되는 거 같음. 이건 답변 부탁
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void heapify_up(vector<int>& heap, int i){
    int p = i / 2;
    if(p == 0) return;
    if(heap[p] < heap[i]){
        swap(heap[p], heap[i]);
        heapify_up(heap, p);
    }
}

void heapify_down(vector<int>& heap, int i){
    int l = i * 2, r = i * 2 + 1, largest = i;
    if(l < heap.size() && heap[l] > heap[largest]) largest = l;
    if(r < heap.size() && heap[r] > heap[largest]) largest = r;
    if(largest != i){
        swap(heap[largest], heap[i]);
        heapify_down(heap, largest);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v = {{0, 0}};
    int idx = n;
    while(n--){
        int p, d;
        cin >> p >> d;
        v.push_back({p, d});
    }
    sort(v.begin(), v.end(), compare);
    vector<int> heap = {0}; // 가치를 담아둘 힙

    int total = 0;
    for(int x = 10000;x >= 1;x--){ // 각 날짜마다 얼마 버는 돈을 total에 추가
        while(idx > 0 && v[idx].second == x){ // x일 이내부터 할 수 있는 녀식들은 다 heap에 추가
            heap.push_back(v[idx].first);
            heapify_up(heap, heap.size() - 1);
            idx--;
        }
        if(heap.size() > 1){
            total += heap[1];
            heap[1] = heap[heap.size() - 1];
            heap.pop_back();
            heapify_down(heap, 1);
        }
    }

    cout << total;

    return 0;
}