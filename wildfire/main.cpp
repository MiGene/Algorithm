#include <iostream>
#include<vector>
#include<map>
#include<numeric>
using namespace std;

void recur(vector<int> &b, vector<int> &passed, map<int,vector<int>> &M, int ind){
    b[ind]=0;
    if (passed[ind]==0){
        passed[ind]=1;
        if (!M[ind].empty()){
            for (auto &x:M[ind]){
                recur(b,passed,M,x);
            }
        }
    }
}

int main()
{
    int n,m,k,n1,n2;
    cin >> n >> m >> k;
    vector<int> b(n);
    vector<int> d(k);
    vector<int> passed(n);
    map<int,vector<int>> M;

    vector<int> vec;
    for (int i=0; i<n;i++){
        M[i] = vec;
        passed[i]=0;
        cin >> b[i];
    }
    for (int i=0; i<k;i++) cin >> d[i];

    for (int i=0; i<m;i++){
        cin >> n1 >> n2;
        M[n1].push_back(n2);
    }

    for (auto&x:d){
        recur(b,passed,M,x);
        //for(auto &x:b) cout << x << " ";
        cout << accumulate(b.begin(),b.end(),0) << " ";
    }

}
