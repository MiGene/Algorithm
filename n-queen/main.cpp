#include <iostream>
#include<vector>
#include<queue>

using namespace std;

bool check(vector<int> vec, int ind){
    for (int i=1; i<ind; i++){
        int dx = abs(vec[i] - vec[ind]);
        int dy = abs(i - ind);
        //cout <<"//" <<dy << " "<<dx << "//";
        if (dy == dx) return false;

    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    queue<pair<vector<int>,int>> q;
    for (int i=1; i<=n;i++) v[i] = i;
    int queen = 0;

    q.push({v,1});

    while(!q.empty()){
        vector<int> vec = q.front().first; int ind = q.front().second;
        q.pop();

        for (int i=ind; i<=n; i++){
            if (ind == n) {
                if (check(vec,ind)==true) queen+=1;
            }
            else {

                swap(vec[i],vec[ind]);
                if (check(vec,ind) == true) {
                    q.push({vec,ind+1});
                }
                swap(vec[i],vec[ind]);
            }
        }
    }

    cout << queen;
}
