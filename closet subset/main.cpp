#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void recur(int diff, int ind, int left, int summ, int &min_dif, int &n,vector<int> &v,int &k){
    if (left==0 && diff<min_dif) min_dif = diff;
    else if (ind<n && n-ind>=left){
        //if (summ > k+min_dif) return
        recur(diff,ind+1,left,summ,min_dif,n,v,k);
        summ += v[ind];
        diff = abs(k-summ);
        if (diff<min_dif) recur(diff,ind+1,left-1,summ,min_dif,n,v,k);
    }
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    //queue<vector<int>> q;
    sort(v.rbegin(),v.rend());
    //q.push({abs(k-v[0]),1,m-1,v[0]});
    //q.push({k,1,m,0});

    int min_dif = 1000000;
    recur(abs(k-v[0]),1,m-1,v[0],min_dif,n,v,k);
    recur(k,1,m,0,min_dif,n,v,k);

    cout << min_dif;
}

