#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    static int levels[300001] = {0, };

    for(int i = 1;i <= n;i++){
        cin >> levels[i];
    }
    sort(levels + 1, levels + n + 1);
    double d = (double)n * 0.15;
    if(d - (double)(int)d >= 0.5) d += (1.0 - (d - (double)(int)d));
    else d -= (d - (double)(int)d);

    double avg = 0;

    for(int i = 1 + d;i <= n - d;i++){
        avg += (double)levels[i];
    }
    if(avg) avg /= ((double)n - (2 * d));

    
    if(avg - (double)(int)avg >= 0.5) avg += (1.0 - (avg - (double)(int)avg));
    else avg -= (avg - (double)(int)avg);

    cout << avg;

    return 0;
}