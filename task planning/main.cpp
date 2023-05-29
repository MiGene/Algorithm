#include <iostream>
#include<map>
#include<vector>

using namespace std;

void recur (map<int,vector<int>> &m, vector<int> &passed, vector<int> &parent, vector<int> &process, int Pnode) {
    //cout << Pnode << " ";
    passed[Pnode] = 1;
    if (m[Pnode].size() == 0){
        process.push_back(Pnode);
        passed[Pnode] = 1;
    }
    else {
        for (int i=0; i<m[Pnode].size(); i++){
            if (passed[m[Pnode][i]]==0) recur(m,passed,parent,process,m[Pnode][i]);
        }
        process.push_back(Pnode);
    }

}

int main()
{
    int n;
    cin >> n;
    vector<int> parent(n);
    vector<int> passed(n);
    vector<int> process;
    map<int,vector<int>> m;

    vector<int> vec;
    for (int i=0; i<n;i++){
        m[i] = vec;
        parent[i] = -1;
        passed[i] = 0;
    }

    //push data in
    int num;
    for (int i=0; i<n; i++){
        cin >> num;
        int node;
        for (int j=0; j<num; j++){
            cin >> node;
            m[i].push_back(node);
            parent[node] = i;
        }
    }

    for (int i=0; i<n; i++) {
        if (parent[i]==-1) {
            recur(m,passed,parent,process,i);
            //break;
        }
    }

    for (auto &x:process) cout << x << " ";

}
