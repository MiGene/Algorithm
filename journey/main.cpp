#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void findUpper(vector<vector<int>> &path, vector<int> &maxPath, vector<int> passed, int left, int ub, int old, int &ans,int node){
    //cout << " node : " << node << " left: " << left << " old: " << old << " ans: "<<ans << endl;
    if (left<=1) {
            old += path[1][node]; //cout << " oldNew: " << old << endl;
            if (old>ans) ans=old;
    }
    else if (ub>ans){

        for (int i=2;i<passed.size();i++){
            if (passed[i]==0){
                passed[i]=1;
                int ub1 = ub - maxPath[i]; ub1 += path[i][node];
                //int old1 = old+path[i][node];
                if (ub1>ans) findUpper(path,maxPath,passed,left-1,ub1,old+path[i][node],ans,i);
                passed[i]=0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> path(n+1);
    vector<int> vec(n+1);
    vector<int> passed(n+1);
    vector<int> maxPath(n+1);
    //priority_queue<vector<int>> pq;
    int ans = 0;
    for (int i=1; i<=n;i++) path[i] = vec;

    for (int r=1; r<=n; r++) {
        for (int c=1;c<=n;c++) {
            cin >> path[r][c];
            if (path[r][c]>maxPath[r]) maxPath[r] = path[r][c];
        }
    }

   // for (int i=1; i<=n; i++){
    //    maxPath[i] = *max_element(path[i].begin(), path[i].end());
    //}

    passed[n]=1;
    int ub=accumulate(maxPath.begin(),maxPath.end(),0); int old=0;
    findUpper(path, maxPath, passed,n-1,ub,old,ans,n);

    cout << ans;
}
