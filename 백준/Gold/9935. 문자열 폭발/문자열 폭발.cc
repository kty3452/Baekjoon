#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str, bombstr;
    cin >> str >> bombstr;
    stack<char> stk;

    for(int i = 0;i < str.size();i++){
        stk.push(str[i]);
        if(str[i] == bombstr[bombstr.size() - 1] && stk.size() >= bombstr.size()){
            stack<char> temp;
            stack<char> temp2;
            for(int j = 0;j < bombstr.size();j++){
                temp.push(stk.top());
                temp2.push(stk.top());
                stk.pop();
            }

            bool check = true;
            for(int j = 0;j < bombstr.size();j++){
                if(temp.top() != bombstr[j]){
                    check = false;
                    break;
                }
                temp.pop();
            }
            if(!check){
                for(int j = 0;j < bombstr.size();j++){
                    stk.push(temp2.top());
                    temp2.pop();
                }
            }
        }
    }
    stack<char> result;
    while(!stk.empty()){
        result.push(stk.top());
        stk.pop();
    }

    if(result.empty()) cout << "FRULA";
    else 
        while(!result.empty()){
            cout << result.top();
            result.pop();
        }


    return 0;
}
