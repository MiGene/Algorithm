#include <iostream>
#include<vector>
#include<map>
#include<algorithm>


using namespace std;

int main()
{
    int n,e,s;
    int e1,e2,w;
    cin >> n >> e >> s;
    vector<int> p(n);
    vector<int> d(n);
    vector<vector<int>> graph;

    for(int i=0; i<n; i++){
        p[i]=-1;
        d[i]=1000000;
    }

    for (int i=0;i<e;i++){
        cin >> e1 >> e2 >> w;
        graph.push_back({e1,e2,w});
    }

    d[s]=0;
    for (int i=0; i<e;i++){
        for (auto &x:graph){
            int u=x[0]; int w=x[2]; int v=x[1];
            if (d[u]+w<d[v]){
                d[v] = d[u]+w; //p[x[1]] = x[0];
            }
        }
    }
    bool out=false;
    for (auto &x:graph){
            int u=x[0]; int w=x[2]; int v=x[1];
            if (d[u]+w < d[v]){
                cout << "-1";
                out=true;
                break;
            }
    }
    if (out==false) {
        for (auto &x:d) cout << x << " ";
    }
}
