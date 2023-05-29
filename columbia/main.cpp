#include <iostream>
#include<vector>
#include<queue>


using namespace std;

int main()
{
    int row,col;
    cin >> row >> col;
    vector<vector<int>> m(row);
    vector<vector<int>> d(row);
    vector<vector<int>> passed(row);
    vector<int> vec(col);
    priority_queue<vector<int>> pq;

    for (int r=0; r<row; r++){
        m[r]=vec;
        d[r]=vec;
        passed[r]=vec;
    }

    for (int r=0; r<row;r++){
        for (int c=0; c<col; c++){
            cin >> m[r][c];
            d[r][c] = 1000000;
            passed[r][c] =0;
        }
    }

    d[0][0] = 0;
    pq.push({0,0,0});

    while (!pq.empty()){
        int dis = -pq.top()[0]; int r = pq.top()[1]; int c = pq.top()[2];
        pq.pop();
            passed[r][c]=1;
            if (r+1<row && m[r+1][c]+dis<d[r+1][c]){
                d[r+1][c] = dis+m[r+1][c];
                pq.push({-d[r+1][c],r+1,c});
            }
            if (c+1<col && m[r][c+1]+dis < d[r][c+1]){
                d[r][c+1] = dis+m[r][c+1];
                pq.push({-d[r][c+1] ,r,c+1});
            }
            if (r-1>=0 && m[r-1][c]+dis<d[r-1][c]){
                d[r-1][c] = dis+m[r-1][c];
                pq.push({-d[r-1][c],r-1,c});
            }
            if (c-1>=0 && m[r][c-1]+dis<d[r][c-1]){
                d[r][c-1] = dis+m[r][c-1];
                pq.push({-d[r][c-1] ,r,c-1});
            }
        //}

    }

    for (int r=0; r<row; r++){
        for (auto &x: d[r]) cout << x << " ";
        cout << endl;
    }


}
