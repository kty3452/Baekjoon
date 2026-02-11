/*
1. 각 자리에 대해서 모든 경우의 수를 새는 것은 O(n^2)라서 안됨.
2. 그런데 만약 구간 합을 사용한다면?
3. 그럴 필요도 없이 일종의 슬라이드 형식으로 종류가 차면 앞에 것만 빼고, 뒤에거를 추가하는 형식으로.
*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> use_alpabet(26);
    vector<int> how_many_use_alpabet(26);
    int high = 0, total = 0, start = 0;

    for(int i = 0;i < s.size() - 1;i++){
        int idx = s[i] - 'a';
        use_alpabet[idx] = true;
        how_many_use_alpabet[idx]++;
        total++;

        if(accumulate(use_alpabet.begin(), use_alpabet.end(), 0) >= n && !use_alpabet[s[i + 1] - 'a']){
            if(total > high) high = total;
            for(int j = start;j <= i;j++){ // 이미 i 값까지는 다 개수를 센 상태이기에 없애도 상관없음.
                how_many_use_alpabet[s[j] - 'a']--;
                total--;
                if(how_many_use_alpabet[s[j] - 'a'] <= 0){
                    use_alpabet[s[j] - 'a'] = false;
                    start = j + 1;
                    break;
                }
            }
        }
        
    }
    if(high < total + 1) high = total + 1;
    cout << high;
}