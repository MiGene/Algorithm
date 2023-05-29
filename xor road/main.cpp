#include <iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> inG;
    vector<int> outG(n-1);
    unsigned long long total=0;
    int last;
    for (int i=0;i<n-1;i++){
        cin >> outG[i];
    }
    cin >> last; inG.push_back(last);

    while (!outG.empty()){
        int maxxi=0;
        int maxind=0;
        int outt=0;
        for (int ot=0;ot<outG.size();ot++){
            for (int i=0;i<inG.size();i++){
                int a = outG[ot]^inG[i];
                if (a>maxxi){
                    maxxi = outG[ot]^inG[i];
                    outt = outG[ot];
                    maxind = ot;
                }
            }
        }
        total += maxxi;
        inG.push_back(outt);
        outG.erase(outG.begin()+maxind);
    }
    cout << total;
}
