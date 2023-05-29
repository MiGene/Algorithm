#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void findUpper(vector<vector<int>> &path, vector<int> passed,vector<int> &maxPath, int &maxK, vector<int> &keep, int &wanted, int &wantedI, int old,int ind){
    if (old == wanted) {
        keep[wantedI] =1;
    }
    else if (old<=maxK){
        passed[ind]=1;
        for (int i=0;  i<passed.size();i++){
            if (passed[i]==0){
                passed[i] = 1;
                int old1= old+path[ind][i];
                findUpper(path,passed,maxPath,maxK,keep,wanted,wantedI,old1,i);
                passed[i] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,m,k;
    cin >> n >> m;
    vector<int> K(8);
    for (int i=0; i<8;i++) cin >> K[i];
    int maxK = *max_element(K.begin(),K.end());
    vector<int> passed(n);
    vector<vector<int>> path(n);
    vector<int> maxPath(n);
    vector<int> vec(n);
    vector<int> keep(8);


    for (int i=0; i<n; i++) path[i] = vec;

    int a,b,w;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> w;
        path[a][b] = w; path[b][a]=w;
    }
    for (int i=0; i<path.size();i++) {
        maxPath[i] = *max_element(path[i].begin(), path[i].end());
    }
    for(int i=0; i<8;i++) {
        //cout << " " << i << " ";
        passed[i] = 1;
        int r=i;
        for (int j=0; j<path.size();j++){
            findUpper(path,passed,maxPath,maxK,keep,K[i],i,0,j);
            if (keep[i]==1) break;
        }
        if (keep[i]==1) cout << "YES" << endl;
        else cout << "NO" << endl;
        passed[i]=0;
    }

    /*for (int i=0; i<8; i++){
        if (keep[i]==1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }*/
    /*for (int i=0; i<n;i++){
        cout << " i: ";
        for (int j=0;j<n;j++) cout << path[i][j] << " ";
        cout << endl;
    }*/
    //for (int i=0; i<keep.size();i++) cout << keep[i] << " ";
}
