#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void min_heapify(string s, vector<long long> &V, int i){
    if(s == "up"){
        if(i == 1) return;
        int p = i/2;
        if(V[p] > V[i]){
            swap(V[p], V[i]);
            min_heapify("up", V, p);
        }
    }
    else{
        int l = i*2;
        int r = i*2+1;
        int smallest = i;

        if(l < V.size() && V[smallest] > V[l]) smallest = l;
        if(r < V.size() && V[smallest] > V[r]) smallest = r;
        if(smallest != i){
            swap(V[i], V[smallest]);
            min_heapify("down", V, smallest);
        }
    }
}
void max_heapify(string s, vector<long long> &V, int i){
    if(s == "up"){
        if(i == 1) return;
        int p = i/2;
        if(V[p] < V[i]){
            swap(V[p], V[i]);
            max_heapify("up", V, p);
        }
    }
    else{
        int l = i*2;
        int r = i*2+1;
        int largest = i;

        if(l < V.size() && V[largest] < V[l]) largest = l;
        if(r < V.size() && V[largest] < V[r]) largest = r;
        if(largest != i){
            swap(V[i], V[largest]);
            max_heapify("down", V, largest);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;
        vector<long long> min_heap = {0, };
        vector<long long> max_heap = {0, };
        map<long long, int> m;
        while(k--){
            char ID;
            int val;
            cin >> ID >> val;

            if(ID == 'I'){
                min_heap.push_back(val);
                max_heap.push_back(val);
                m[val]++;
                min_heapify("up", min_heap, min_heap.size() - 1);
                max_heapify("up", max_heap, max_heap.size() - 1);
            }
            else{
                if(val == 1){
                    while(max_heap.size() > 1 && m[max_heap[1]] == 0){
                        max_heap[1] = max_heap[max_heap.size() - 1];
                        max_heap.pop_back();
                        max_heapify("down", max_heap, 1);
                    }
                    if(max_heap.size() > 1){
                        m[max_heap[1]]--;
                        max_heap[1] = max_heap[max_heap.size() - 1];
                        max_heap.pop_back();
                        max_heapify("down", max_heap, 1);
                    }
                }
                else if(val == -1){
                    while(min_heap.size() > 1 && m[min_heap[1]] == 0){
                        min_heap[1] = min_heap[min_heap.size() - 1];
                        min_heap.pop_back();
                        min_heapify("down", min_heap, 1);
                    }
                    if(min_heap.size() > 1){
                        m[min_heap[1]]--;
                        min_heap[1] = min_heap[min_heap.size() - 1];
                        min_heap.pop_back();
                        min_heapify("down", min_heap, 1);
                    }
                }
            }
        }
        
        while(max_heap.size() > 1 && m[max_heap[1]] == 0){
            max_heap[1] = max_heap[max_heap.size() - 1];
            max_heap.pop_back();
            max_heapify("down", max_heap, 1);
        }
        while(min_heap.size() > 1 && m[min_heap[1]] == 0){
            min_heap[1] = min_heap[min_heap.size() - 1];
            min_heap.pop_back();
            min_heapify("down", min_heap, 1);
        }
        if(min_heap.size() <= 1 || max_heap.size() <= 1) cout << "EMPTY\n";
        else cout << max_heap[1] << " " << min_heap[1] << "\n";
    }
    return 0;
}