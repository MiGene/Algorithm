#include <iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool sw(vector<int> &v, vector<int> &vSorted, vector<int> &correct, map<int,pair<int,int>> &m, int i){
    int ind = m[v[i]].second; int amount = ind = m[v[i]].second;
    for (int j=ind; j<ind+amount; j++){
        if (correct[j]==0 && v[j]==vSorted[i]){
            swap(v[j], vSorted[i]);
            correct[j] = 1; correct[i]=1;
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> vSorted(n);
    vector<int> correct(n);
    map<int,pair<int,int>> m;

    for (int i=0; i<n; i++) cin >> vSorted[i];

    v = vSorted;

    sort(vSorted.begin(), vSorted.end());

    for (int i=0; i<v.size();i++){
        if (v[i]==vSorted[i]) correct[i] = 1;
        else correct[i] = 0;

        //cout << vSorted[i] << " " << i << endl;
        if (m.find(vSorted[i])==m.end()) m[vSorted[i]] = {1,i};
        else {
            m[vSorted[i]].first+=1; //cout << " f ";
        }

    }

    /*for (auto &x:m) {
        cout << "amount: " << x.second.first << " ind: " << x.second.second;
        cout << endl;
    }*/

   int s = 0;
    for(int i=0; i<v.size();i++){
        if (correct[i]==0){
            if (v[i]==vSorted[i]) correct[i]=1;
            else {
                if (sw(v,vSorted,correct,m,i)==true) s++;
                else {

                    for (int j=i+1; j<v.size(); j++){
                        if (v[j]==vSorted[i] && correct[j]==0) {
                            swap(v[i],v[j]);
                            s++;
                            correct[i]=1;
                            break;
                        }
                    }
                }
            }
        }
        //for(auto &x:v) cout << x << " ";
        //cout << endl;
    }

    //for(auto &x:v) cout << x << " ";

    cout << s;


}
