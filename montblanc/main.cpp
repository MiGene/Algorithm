#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(vector<int> &camp, int &day, int d, int n,int k,int &last_diff){
    int i=0;
    int last=0;

    while (i<n){
        //cout << k+last << " ";
        auto it = lower_bound(camp.begin(), camp.end(),k+last);
        if (it==camp.end()) {
            //cout << "b";
            day++;
            return true;
        }

        int low = *it;
        if (low!=k+last) i = it-camp.begin()-1;
        else i = it-camp.begin();
        //cout << " i: " << i << " low: " << low << " klast :" << k+last<< endl;

        day++;
        if (camp.size()-1 == i) return true;
        if (day >= d){
            if (i == camp.size()-1) {
                //day--;
                return true;
            }
            else {
                last_diff = camp[i+1] - camp[i];
                return false;

            }
        }

        last = camp[i];

    }
}

int main()
{
    int n,d;
    cin >> n >> d;
    vector<int> camp(n);
    for (int i=0; i<n; i++) cin >> camp[i];

    int k = camp[n-1]/d;
    auto it = lower_bound(camp.begin(), camp.end(),k);
    int low = *it;
    int i2 = it-camp.begin();
    if (low != k) {
        k = camp[i2-1]; //beware out of range
        i2--;
    }
    //cout << k;
    while (true){
        int day =0; int last_diff=0;
        bool acc = check(camp,day,d,n,k,last_diff);
        if (acc==true){
            cout << k << " " << day;
            break;
        }
        else {
            int first_diff = camp[i2+1] - k;
            int choose_diff = min(first_diff,last_diff);
            k+= choose_diff;
        }
    }
}
