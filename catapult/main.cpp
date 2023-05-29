#include <iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void DFS(map<int,vector<int>> &m, vector<int> &status, vector<int> &num){

}

int main()
{
    int n,p,c;
    cin >> n;
    map<int,vector<int>> m;
    map<int,vector<int>> transpose;
    vector<int> passed(n);
    vector<int> vec;
    for (int i=0; i<n;i++){
        m[i] = vec;
        transpose[i] = vec;
        passed[i]=0;
        cin >> p;
        for (int j=0;j<p;j++) {
            cin >> c;
            m[i].push_back(c);
        }
    }

    for (int i=0; i<m; i++){
        for (auto &x:m[i]) {
            transpose[x].push_back(i);
        }
    }

    for (int i=0; i<m; i++){
        if (status[i]!=2){
            DFS();
        }
    }

}
