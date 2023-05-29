#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    float m;
    cin >> n >> m;
    vector<int> v(m);
    vector<int> total(m);

    for (int i=0; i<m; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    /*total[0] = v[0];
    int summ=total[0];
    for (int i=1; i<v.size(); i++){
        total[i] = total[i-1]+v[i];
        summ += total[i];
    }

    float ave = summ/m;
    printf("%.3lf", ave);*/

    float summ=0;
    for (int i=0; i<n;i++){
        //cout << " i: "<< i << " : " << v[i] << endl;
        int s = i;
        int last = v[i]; summ += v[i];
        s+=n;
        while (s<m){
            summ += last+v[s];
            last += v[s];
            s += n;
            //cout << v[s] << " ";
        }
    }

    float ave = summ/m;
    printf("%.3lf", ave);

}
