#include <iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e,s,w,e1,e2,f;
    cin >> n >> e >> s;
    cin >> f;
    vector<int> d(n);
    vector<int> start(s);
    vector<vector<int>> edge(e);

    for (int i=0; i<n;i++) d[i]=1000000;

    for (int i=0; i<s;i++){
        cin >> start[i];
    }

    for (int i=0; i<e; i++){
        cin >> e2 >> e1 >> w;
        edge[i] = {e1, e2, w};
    }

    int mini=1000000;
    d[f]=0;
    mini = 1000000;

    bool inn=false;
    for (int j=0; j<e;j++){
        for (auto &x:edge){
            e1 = x[0]; e2 = x[1]; w = x[2];
            if (d[e1]+w<d[e2]) {
                d[e2] = d[e1]+w;
                inn = true;
            }
        }
        if (!inn) break;
    }
    for (auto &x:start){
        mini = min(mini,d[x]);
    }

    //for (auto &x:d) cout << x << " ";

    cout << mini;
}
