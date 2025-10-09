// 최대 힙

#include <iostream>
#include <vector>

using namespace std;

void heapify(string s, vector<string> &A, int i){
    if(s == "up"){
        if(i == 1) return;
        int p = i / 2;
        
        if(A[p].size() < A[i].size() || (A[p].size() == A[i].size() && A[p] < A[i])){
            swap(A[p], A[i]);
            heapify("up", A, p);
        }
    }
    else{
        int l = i * 2;
        int r = i * 2 + 1;
        int largest = i;
        if(l < A.size()){
            if(A[l].size() > A[largest].size() 
            || (A[l].size() == A[largest].size() 
            && A[l] > A[largest])) largest = l;
        }
        if(r < A.size()){
            if(A[r].size() > A[largest].size() 
            || (A[r].size() == A[largest].size() 
            && A[r] > A[largest])) largest = r;
        }
        if(i != largest){
            swap(A[i], A[largest]);
            heapify("down", A, largest);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> heap_arr = {"0"};

    for(int i = 0;i < n;i++){
        string num;
        cin >> num;

        if(num == "0"){
            if(heap_arr.size() == 1) cout << "0\n";
            else{
                cout << heap_arr[1] << "\n";
                heap_arr[1] = heap_arr[heap_arr.size() - 1];
                heap_arr.pop_back();
                heapify("down", heap_arr, 1);
            }
        }
        else{
            heap_arr.push_back(num);
            heapify("up", heap_arr, heap_arr.size() - 1);
        }
    }

    return 0;
}
