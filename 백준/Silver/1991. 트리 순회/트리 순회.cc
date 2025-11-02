#include <iostream>
#include <stack>
#include <map>

using namespace std;


void rotate(map<char, pair<char, char>>& M, char c, string what_rotate){
    if(c == '.') return;
    if(what_rotate == "front"){
        cout << c;
        rotate(M, M[c].first, "front");
        rotate(M, M[c].second, "front");
    }
    else if(what_rotate == "middle"){
        rotate(M, M[c].first, "middle");
        cout << c;
        rotate(M, M[c].second, "middle");
    }
    else{
        rotate(M, M[c].first, "back");
        rotate(M, M[c].second, "back");
        cout << c;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<char, pair<char, char>> M;

    for(int i = 0;i < n;i++){
        char root, left, right;
        cin >> root >> left >> right;
        M[root] = {left, right};
    }
    
    rotate(M, 'A', "front");
    cout << "\n";
    rotate(M, 'A', "middle");
    cout << "\n";
    rotate(M, 'A', "back");

    return 0;
}