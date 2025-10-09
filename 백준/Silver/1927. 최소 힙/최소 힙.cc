// 최소 힙

#include <iostream>
#include <vector>

using namespace std;

void heapify_up(vector<string> &A, int i){
    int p = i / 2;
    if(p == 0) return;

    int largest = i;

    if(A[i].size() < A[p].size()){
        largest = p;
    }
    else if(A[i].size() == A[p].size()){
        if(A[i] < A[p]) largest = p;
    }

    if(largest != i){
        swap(A[i], A[largest]);
        heapify_up(A, largest);
    }
}
void heapify_down(vector<string> &A, int i){
    int l = i * 2;
    int r = i * 2 + 1;

    int largest = i;

    if(l < A.size()){
        if(A[largest].size() > A[l].size()){
            largest = l;
        }
        else if(A[largest].size() == A[l].size()){
            if(A[largest] > A[l]) largest = l;
        }
    }
    if(r < A.size()){
        if(A[largest].size() > A[r].size()){
            largest = r;
        }
        else if(A[largest].size() == A[r].size()){
            if(A[largest] > A[r]) largest = r;
        }
    }

    if(largest != i){
        swap(A[i], A[largest]);
        heapify_down(A, largest);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> heapArr = {"0"};

    while(n--){
        string input;
        cin >> input;
        if(input == "0"){
            if(heapArr.size() == 1){
                cout << "0\n";
            }
            else{
                cout << heapArr[1] << "\n";
                heapArr[1] = heapArr[heapArr.size() - 1];
                heapArr.pop_back();
                heapify_down(heapArr, 1);
            }
        }
        else{
            heapArr.push_back(input);
            heapify_up(heapArr, heapArr.size() - 1);
        }
    }

    return 0;
}