#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int,vector<pair<int,int>>> m;
    vector<int> distance(n+1);
    vector<int> used;
    vector<int> unused;
    priority_queue<pair<int,int>> pq;


    vector<pair<int,int>> vec;
    for (int i=1;i<=n;i++){
        m[i]=vec;
        distance[i] = 10000000000;
        unused.push_back(i);
    }
    distance[1]=0;

    int d;
    for (int r=1;r<=n;r++){
        for (int c=1;c<=n;c++){
            cin >> d;
            if (d != -1 && d!=0) m[r].push_back({d,c});
        }
    }

    for (auto&x:m[1]){
        int town = x.second; int dis = x.first;
        distance[town]=dis;
        pq.push({-dis,town});
    }
    used.push_back(1);

    while(!pq.empty()){
        int town = pq.top().second; int dis = -pq.top().first;
        if (find(used.begin(), used.end(),town)!=used.end()) pq.pop();
        else {
            for (int i=0; i<m[town].size();i++){
                int d = m[town][i].first; int t = m[town][i].second;
                if (d+dis<distance[t]) {
                    distance[t]=d+dis;
                    pq.push({-(d+dis),t});
                }
            }
            used.push_back(town);
            unused.erase(find(unused.begin(), unused.end(),town));
            pq.pop();
        }
    }

    //sort(distance.begin(),distance.end());
    //for (auto &x:distance) cout << x << " ";
    //cout << endl;
    auto it =  max_element(distance.begin(),distance.end());
    if (*it >= 10000000000) cout << "-1";
    else cout << *it;
}
