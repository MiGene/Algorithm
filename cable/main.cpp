#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> path(n);
    vector<int> vec(n);
    for (int i=0; i<n;i++) path[i] = vec;
    int c;
    for (int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cin >> c;
            path[i][j]=c; path[j][i]=c;
        }
    }
    vector<int> inG;
    vector<int> outG;
    inG.push_back(0);
    for(int i=1;i<n;i++) outG.push_back(i);

    int total=0;
    while (!outG.empty()){
        int minn=1000000;
        int ind=0;
        int node=0;
        for (int i=0; i<outG.size();i++){
            for (int j=0; j<inG.size();j++){
                int d = path[inG[j]][outG[i]]; //cout << " in: " << j <<" out: "<< i << " d: " << d << "\n";
                if (d<minn) {
                    minn = d;
                    node = outG[i];
                    ind = i;
                }
            }
        }
        total+=minn; //cout<<total << endl;
        outG.erase(outG.begin()+ind);
        inG.push_back(node);

    }

    cout << total;




}
