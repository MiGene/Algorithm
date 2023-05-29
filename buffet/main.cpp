#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void concealing(vector<int> &food, vector<int> &light,int &w, int ind){
    for (int i=ind; i<=ind+2*w;i++){
        //cout << " in ";
        if (i<food.size()){
            if (food[i]<=food[ind]+2*w) {
                light[i]=1;
                //for (auto &x:conceal) cout << x << " ";
                //cout << endl;
            }

        }
    }
}

int main()
{
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> food(f);
    vector<int> light(f);
    for (int i=0; i<f; i++) {
        cin >> food[i];
        light[i]=0;
    }

    sort(food.begin(),food.end());
    int s=0;

    //เปิดหัว
    light[0]=1; s++;
    //cout << food[0]+2*w <<endl;
    for (int i=0; i<=w*2;i++){
        if (i<food.size()){
            if (food[i]<=food[0]+2*w) {
                light[i]=1;
            }
        }
    }



    //ปิดท้าย
    /*if (conceal[conceal.size()-1]==0){
        for (int i=conceal.size()-1; i<l;i++){
            if (broken[i]<broken[0]+l) {
                conceal[i]=1;
            }
        }
        s++;
    }*/

    for (int i=0;i<food.size();i++){
        //cout <<"in ";
        //cout << food[i]<< " ";
        if (light[i]==0){
            //cout << "in : "<<food[i]<< " ";
            concealing(food,light,w,i);
            s++;
        }
    }


    cout << s;

}
