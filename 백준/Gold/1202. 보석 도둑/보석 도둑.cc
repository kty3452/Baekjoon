#include <bits/stdc++.h>
using namespace std;

void heapify_up(vector<int> &existed, int i){
    int p = i / 2;
    if(p == 0) return;

    if(existed[i] < existed[p]){
        swap(existed[i], existed[p]);
        heapify_up(existed, p);
    }

}
void heapify_down(vector<int> &existed, int i){
    int l = i * 2, r = i * 2 + 1;
    int smallest = i;
    if(l < existed.size() && existed[l] < existed[smallest])
        smallest = l;
    if(r < existed.size() && existed[r] < existed[smallest])
        smallest = r;
    if(smallest != i){
        swap(existed[smallest], existed[i]);
        heapify_down(existed, smallest);
    }
}


bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first > b.first; // 내림차순
    }
    return a.second > b.second;
}

int find(int v, vector<int>& unf){
    if(v == unf[v]) return v;
    else return unf[v] = find(unf[v], unf);
}

void Union(int a, int b, vector<int>& unf){
    int fa = find(a, unf);
    int fb = find(b, unf);
    if(fa != fb) unf[fa] = fb;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    long long best = 0;
    vector<pair<int, int>> mv;
    vector<int> c;
    while(n--){
        int mi, vi;
        cin >> mi >> vi;
        mv.push_back({mi, vi});
    }
    while(k--){
        int ci;
        cin >> ci;
        c.push_back(ci);
    }
    vector<int> unf;
    for(int i = 0;i <= c.size();i++){
        unf.push_back(i);
    }

    sort(mv.begin(), mv.end(), compare);
    sort(c.begin(), c.end());

    for(int i = 0;i < mv.size();i++){
        int low = 0, high = c.size() - 1, standard = c.size();
        while(low <= high){ // 이분탐색
            int mid = (low + high) / 2;
            if(c[mid] < mv[i].first){
                low = mid + 1;
            }
            else{
                standard = mid;
                high = mid - 1;
            }
        }
        int idx = find(standard, unf);
        if(idx != c.size()){
            best += mv[i].second;
            Union(idx, idx + 1, unf);
        }

    }

    cout << best;
}