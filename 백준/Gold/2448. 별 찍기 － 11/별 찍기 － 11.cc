#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> triangle;

void draw(int r, int c, int n){
    if(n == 3){
        triangle[r][c] = '*';

        triangle[r + 1][c + 1] = '*';
        triangle[r + 1][c - 1] = '*';

        triangle[r + 2][c + 2] = '*';
        triangle[r + 2][c + 1] = '*';
        triangle[r + 2][c] = '*';
        triangle[r + 2][c - 1] = '*';
        triangle[r + 2][c - 2] = '*';
    }
    else{
        draw(r, c, n/2);
        draw(r + n/2, c - n/2, n/2);
        draw(r + n/2, c + n/2, n/2);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    triangle.resize(n, vector<char>(n * 2, ' '));

    draw(0, n - 1, n);

    for(auto a : triangle){
        for(auto b : a){
            cout << b;
        }
        cout << "\n";
    }

    return 0;
}