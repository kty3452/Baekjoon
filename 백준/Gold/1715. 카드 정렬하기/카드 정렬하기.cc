#include <bits/stdc++.h>
using namespace std;

void heapify_up(vector<int> &v, int i){
    int p = i / 2;
    if(p == 0) return;
    if(v[i] < v[p]){
        swap(v[i], v[p]);
        heapify_up(v, p);
    }
}

void heapify_down(vector<int> &v, int i){
    int l = i * 2, r = i * 2 + 1;
    int smallest = i;
    if(l < v.size() && v[l] < v[smallest]) smallest = l;
    if(r < v.size() && v[r] < v[smallest]) smallest = r;
    if(smallest != i){
        swap(v[i], v[smallest]);
        heapify_down(v, smallest);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v = {0, };
    while(n--){
        int temp;
        cin >> temp;
        v.push_back(temp);
        heapify_up(v, v.size() - 1);
    }

    int best = 0;

    while(v.size() > 2){
        int temp = 0;
        for(int i = 0;i < 2;i++){
            temp += v[1];
            v[1] = v[v.size() - 1];
            v.pop_back();
            heapify_down(v, 1);
        }
        best += temp;
        v.push_back(temp);
        heapify_up(v, v.size() - 1);
    }

    cout << best;
}