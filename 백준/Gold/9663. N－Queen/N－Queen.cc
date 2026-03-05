#include <bits/stdc++.h>
using namespace std;

int num = 0;

void find(vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2, int queen){
    if(queen == col.size()){
        num++;
    }
    else{
        int n = col.size();
        for(int j = 0;j < col.size();j++){
            if(!col[j] && !dia1[queen - j + n] && !dia2[queen + j]){
                col[j] = true;
                dia1[queen - j + n] = true;
                dia2[queen + j] = true;
                find(col, dia1, dia2, queen + 1);
                col[j] = false;
                dia1[queen - j + n] = false;
                dia2[queen + j] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> col(n), dia1(n * 2), dia2(n * 2);

    find(col, dia1, dia2, 0);

    cout << num;

    return 0;
}