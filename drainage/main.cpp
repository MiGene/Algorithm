#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void concealing(vector<int> &broken, vector<int> &conceal,int &l, int ind){
    for (int i=ind; i<ind+l;i++){
        //cout << " in ";
        if (i<broken.size()){
            if (broken[i]<broken[ind]+l) {
                conceal[i]=1;
                //for (auto &x:conceal) cout << x << " ";
                //cout << endl;
            }

        }
    }
}

int main()
{
    int n,l;
    cin >> n >> l;
    vector<int> broken(n);
    vector<int> conceal(n);
    for (int i=0; i<n; i++) {
        cin >> broken[i];
        conceal[i]=0;
    }

    sort(broken.begin(),broken.end());
    int s=0;

    //ปิดหัว
    conceal[0]=1; s++;
    for (int i=0; i<l;i++){
        if (broken[i]<broken[0]+l) {
            conceal[i]=1;
        }
    }

    //ปิดท้าย
    if (conceal[conceal.size()-1]==0){
        for (int i=conceal.size()-1; i<l;i++){
            if (broken[i]<broken[0]+l) {
                conceal[i]=1;
            }
        }
        s++;
    }

    for (int i=0;i<broken.size();i++){
        if (conceal[i]==0){
            concealing(broken,conceal,l,i);
            s++;
        }
    }


    cout << s-1;

}
