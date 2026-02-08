/*
1. 만일 각 강의실에 대해서 모든 수업에 대한 경우의 수를 보는건 최악의 경우 n제곱이라서 안됨.
2. 그러면.. 최대 강의실 n개에 대해 logn번만 보면 될듯? 그 방법이 뭘까?
3. 씁.. 강의 배치가 중요한게 아니라 남아있는 가장 작은 끝나는 시간이 중요하다.
4. 강의들을 끝점 기준으로 오름차순으로 정렬한 후에 들어가면 냅두고, 안들어가면 1추가?
5. 그럼 끝 점들을 힙으로 갱신??
*/

#include <bits/stdc++.h>
using namespace std;

void heapify_up(vector<int> &heap, int i){
    int p = i / 2;
    if(p == 0) return;
    if(heap[p] > heap[i]){
        swap(heap[p], heap[i]);
        heapify_up(heap, p);
    }
}

void heapify_down(vector<int> &heap, int i){
    int l = i * 2, r = i * 2 + 1;
    int smallest = i;
    if(l < heap.size() && heap[l] < heap[smallest]) smallest = l;
    if(r < heap.size() && heap[r] < heap[smallest]) smallest = r;
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        heapify_down(heap, smallest);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    vector<int> heap = {0};
    while(n--){
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end()); 
    // 무조건 시작 점 기준 오름차순으로 해야함. 시작 점이 작아야 최적해를 보장 가능. 만일 맞지 않으면 어쩔 수 없는거고.
    // 이를 통해 알 수 있는건, 힙이 끝점 기준 정렬이라고 해서, 기존 인덱스가 그럴 필요까지는 없다는 것임.
    // 이것도 어찌보면 슬라이딩 윈도우라고 할 수 있으나, 기존과는 다르게 pop연산이 필요 없음. 윈도우의 길이 제한이 없기에 그냥 추가 되는 형식.
    // 기존 13334 철도 문제와 비슷하다고 볼 순 있으나
    // 철도 문제는 L 안에 포함되는 녀석들을 시작점 기준 최소힙을 사용하여 슬라이딩 윈도우로 걸러내는 것이고,
    // 이 문제는 길이 제한이 무한인 L이 여러 개 있다고 가정하고, 최소힙을 통해서 L의 끝 점을 기준으로 하는 최소힙을 사용하는 것임.
    heap.push_back(v[0].second);
    for(int i = 1;i < v.size();i++){
        if(v[i].first >= heap[1]){
            heap[1] = v[i].second;
            heapify_down(heap, 1);
        }
        else{
            heap.push_back(v[i].second);
            heapify_up(heap, heap.size() - 1);
        }
    }
    cout << heap.size() - 1;
    return 0;
}

