// 절댓값 힙

#include <iostream>
#include <vector>

using namespace std;

void heapify(string s, vector<string> &V, int i){
    auto absStr = [](const string& s){ return s[0]=='-' ? s.substr(1) : s; };
    if(s == "up"){
        if(i == 1) return;
        int p = i/2;
        int p_size = V[p].size();
        int i_size = V[i].size();
        bool p_is_minus = V[p][0] == '-';
        bool i_is_minus = V[i][0] == '-';

        if(p_size - p_is_minus > i_size - i_is_minus){
            swap(V[p], V[i]);
            heapify("up", V, p);
        }
        else if(p_size - p_is_minus == i_size - i_is_minus){
            string strP = absStr(V[p]);
            string strI = absStr(V[i]);
            if(strP > strI){
                swap(V[p], V[i]);
                heapify("up", V, p);
            }
            else if(strP == strI && p_is_minus == false && i_is_minus == true){
                swap(V[p], V[i]);
                heapify("up", V, p);
            }
        }
        return;
    }
    else{
        int l = i*2;
        int r = i*2+1;
        int smallest = i;
        int smallest_size;
        bool smallest_is_minus;
        if(i < V.size()){
            smallest_size = V[i].size();
            smallest_is_minus = V[i][0] == '-';
        }

        if(l < V.size()){
            int l_size = V[l].size();
            bool l_is_minus = V[l][0] == '-';
            if(l_size - l_is_minus < smallest_size - smallest_is_minus){
                smallest = l;
                smallest_size = l_size;
                smallest_is_minus = l_is_minus;
            }
            else if(l_size - l_is_minus == smallest_size - smallest_is_minus){
                string strL = absStr(V[l]);
                string strSmallest = absStr(V[smallest]);
                if(strL < strSmallest){
                    smallest = l;
                    smallest_size = l_size;
                    smallest_is_minus = l_is_minus;
                }
                else if(strL == strSmallest && l_is_minus == true && smallest_is_minus == false){
                    smallest = l;
                    smallest_size = l_size;
                    smallest_is_minus = l_is_minus;
                }
            }
        }
        if(r < V.size()){
            int r_size = V[r].size();
            bool r_is_minus = V[r][0] == '-'  ? true : false;
            if(r_size - r_is_minus < smallest_size - smallest_is_minus){
                smallest = r;
            }
            else if(r_size - r_is_minus == smallest_size - smallest_is_minus){
                string strR = absStr(V[r]);
                string strSmallest = absStr(V[smallest]);
                if(strR < strSmallest){
                    smallest = r;
                }
                else if(strR == strSmallest && r_is_minus == true && smallest_is_minus == false){
                    smallest = r;
                }
            }
        }
        if(smallest != i){
            swap(V[i], V[smallest]);
            heapify("down", V, smallest);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> heapArr = {"0", };

    for(int i = 0;i < n;i++){
        string num;
        cin >> num;
        
        if(num == "0"){
            if(heapArr.size() == 1){
                cout << "0\n";
            }
            else{
                cout << heapArr[1] << "\n";
                heapArr[1] = heapArr[heapArr.size() - 1];
                heapArr.pop_back();
                heapify("down", heapArr, 1);
            }
        }
        else{
            heapArr.push_back(num);
            heapify("up", heapArr, heapArr.size() - 1);
        }
    }


}