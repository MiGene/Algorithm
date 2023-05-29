#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int n,f,s;
    priority_queue<pair<int,int>>  pq;
    cin >> n;
    vector<int> start(n);
    vector<int> finish(n);
    for (int i=0; i<n; i++){
        cin >> start[i];
    }
    for (int i=0; i<n; i++){
        cin >> finish[i];
    }

    for (int i=0; i<n; i++){
        pq.push({-finish[i],start[i]});
    }

    int last=0;
    int classes = 0;

    while (!pq.empty()) {
        int f = -pq.top().first; int s = pq.top().second; pq.pop();
        //cout << f << " " << s << "l : " << last <<endl;
        if (s>=last){
            last = f;
            classes++;
        }
    }

    cout << classes;
}
