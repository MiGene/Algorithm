#include <iostream>
#include<map>
#include<vector>
using namespace std;

void recur(vector<vector<int>>& adj_list, vector<int>& parent, int node, vector<int>& visited){
    if (visited[node]==0){
        visited[node] = 1;
        for (auto &x:adj_list[node]){
            if (visited[x]==0){
                parent[x] = node;
                recur(adj_list,parent,x,visited);
            }
        }

    }
}

void print(vector<int>& parent, int node){
    cout << node << " ";
    if (parent[node]!=0){
        print(parent, parent[node]);
    }
}


int main()
{
    int n; cin >> n;
    vector<vector<int>> adj_list(n+1);
    vector<int> parent(n+1);
    vector<int> visited(n+1);
    for (int i=1; i<=n; i++) {
        parent[i] = 0;
        visited[i] = 0;
    }

    int a;
    for (int i=2; i<=n; i++){
        cin >> a;
        adj_list[a].push_back(i);
        adj_list[i].push_back(a);
    }

    recur(adj_list,parent,n,visited);
    print(parent, 1);

}
