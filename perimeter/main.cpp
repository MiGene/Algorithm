#include <iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
    int v,e,k;
    cin >>v >> e >> k;
    map<int,vector<int>> m;
    vector<int> passed(v+1);
    vector<int> d(v+1);
    vector<int> vec;
    for (int i=0; i<=v; i++){
        m[i] = vec;
        passed[i]=0;
        d[i] = 1001;
    }
    int e1,e2;
    for (int i=0; i<e;i++){
        cin >> e1 >> e2;
        m[e1].push_back(e2);
        m[e2].push_back(e1);
    }

    queue<int> q; q.push(0); d[0] = 0;
    while(!q.empty()){
        int num = q.front();
        if (passed[num]==0){
            passed[num]=1;
            for (auto &x:m[num]){
                if (d[x]==1001){
                    d[x] = d[num]+1;
                    q.push(x);
                }
            }
        }
        q.pop();
    }
    int total=0;
    for (auto &x:d){
        if (x==k) total += 1;
        //cout << x << " ";
    }
    cout << total;
}
