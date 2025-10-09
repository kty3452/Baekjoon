#include <iostream>

using namespace std;

static int blue = 0, white = 0;

void divide(int *A, int start, int n){
    bool same = true;
    int first_idx = start;
    for(int i = 0;i < n;i++){
        for(int j = start;j < start + n;j++){ 
            if(A[j] != A[first_idx]){
                same = false;
                break;
            }
        }
        if(!same) break;
        start += 128;
    }
    if(!same){
        divide(A, first_idx, n/2);
        divide(A, first_idx + n/2, n/2);
        divide(A, first_idx + 128 * (n/2), n/2);
        divide(A, first_idx + 128 * (n/2) + n/2, n/2);
    } 
    else{
        if(A[first_idx] == 1) blue++;
        else white++;
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    static int paper[128 * 128] = {0, };
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> paper[i * 128 + j];
        }
    }

    divide(paper, 0, n);

    cout << white << "\n" << blue;

}