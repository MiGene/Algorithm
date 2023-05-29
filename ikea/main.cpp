#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int n,e,a,b;
    cin >> n >> e;
    map<int,vector<int>> pre;

    for (int i=0;i<e;i++){
        cin >> a >> b;
        if (pre.find(b)!=pre.end()) pre[b].push_back(a);
        else pre[b] = {a};
    }

    for (int i=0;i<5;i++){
        vector<int> process(n);
        for (int k=0; k<n; k++){
            cin >> process[k];
        }

        bool fail=false;
        for (int j=0; j<process.size();j++){
            if (pre.find(process[j])!=pre.end()){
                for (int y=0; y<pre[process[j]].size();y++){
                //cout << *process.begin() <<  " " << *(process.begin()+j) <<" "<< pre[process[j]][y] << " "<< *find(process.begin(), process.begin()+j,pre[process[j]][y]) <<endl;
                    if (find(process.begin(), process.begin()+j,pre[process[j]][y])==process.begin()+j){
                        cout << "FAIL" << endl;
                        fail=true;
                        break;
                    }
                }
                if (fail) break;
            }
        }
        if (!fail) cout << "SUCCESS" << endl;
    }
}
