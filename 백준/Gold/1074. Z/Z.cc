// Z
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;

    int row[32768] = {0, };
    int col[32768] = {0, };
    col[1] = 1;
    row[1] = 2;
    int next_edge = 2;
    int edge = 1;
    int max_edge = 1;
    for(int i = 0;i < n;i++){
        max_edge *= 2;
    }
    for(int i = 2;i < max_edge;i++){
        if(i == next_edge){
            col[i] = next_edge * next_edge;
            edge = next_edge;
            next_edge *= 2;
            continue;
        }
        else col[i] = col[edge] + col[i % edge]; 
    }
    next_edge = 2;
    edge = 1;
    for(int i = 2;i < max_edge;i++){
        if(i == next_edge){
            row[i] = next_edge * next_edge * 2;
            edge = next_edge;
            next_edge *= 2;
        }
        else row[i] = row[edge] + row[i % edge]; 
    }

    int result = row[r] + col[c];

    cout << result;

    return 0;
}