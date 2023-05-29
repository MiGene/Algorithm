#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>

using namespace std;

bool check(vector<int> color, vector<int> vec, int ind){
    //cout << endl;
    //cout << ind << " : ";
    for (auto &x: vec) {
      //  cout << x << " ";
        if (color[ind]==color[x]) return false;
    }
    return true;
}

int main()
{
    int n,e;
    cin >> n >> e;
    vector<vector<int>> v(n);
    vector<int> color(n);
    queue<pair<vector<int>,int>> q;
    stack<pair<vector<int>,int>> s;
    int minn=10000;
    for (int i=0; i<n;i++) color[i] = -1; //<- -1
    /*for(int i=0; i<n; i++){
        color[0]=i;
        q.push({color,1});
    }*/
    color[0]=0; s.push({color,1});

    int v1,v2;
    for (int i=0; i<e; i++){
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    while(!s.empty()){
        vector<int> color = s.top().first; int ind = s.top().second; s.pop();
        //cout << ind << " ";
        int maxx = *max_element(color.begin(),color.end());
        if (ind==n) {
            //for (auto &x: color) cout << x << " ";
            //cout << endl;
            maxx+=2; //เพราะมีค่า 0 กับ -1
            if (maxx<minn) minn = maxx;
        }
        else if (v[ind].empty()) continue;
        else if (maxx <minn){
            for (int i=0;i<n; i++){ //<- 0
                color[ind]=i;
                if (check(color,v[ind],ind)==true){
                    int maxxi = *max_element(color.begin(),color.end());
                    if (maxxi<=minn)s.push({color,ind+1});
                }
            }
        }
    }

    cout << minn-1;

}

