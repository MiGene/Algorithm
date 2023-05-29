#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void findUpperB(vector<pair<float,int>> &ppw, vector<float> &price, vector<float> &weight,float &upperB,float left, int ind){
    for (int i=ind; i<ppw.size();i++){
        int j = ppw[i].second; float pw = ppw[i].first;
        if (weight[j]>left) {
            upperB += pw*left;
            break;
        }
        else {
            upperB += price[j];
            left -= weight[j];
        }
    }
}

int main()
{
    int N;
    float W;
    cin >> W >> N;
    float w,v;
    vector<float> weight(N);
    vector<float> price(N);
    priority_queue<pair<vector<float>,int>> pq;
    float maxx=0.0;

    for (int i=0; i<N; i++) cin >> price[i];
    for (int i=0; i<N; i++) cin >> weight[i];

    vector<pair<float,int>> ppw(N);
    for (int i=0;i<N;i++) ppw[i] = {price[i]/weight[i], i};
    sort(ppw.rbegin(), ppw.rend());

    //for (auto &x: ppw) cout << x.first << " " << x.second << endl;

    float up=0;
    findUpperB(ppw,price,weight,up,W,1);
    pq.push({{up,W,0},1});
    up = 0;
    findUpperB(ppw,price,weight,up,W-weight[ppw[0].second],1);
    pq.push({{up+price[ppw[0].second],W-weight[ppw[0].second], price[ppw[0].second]},1});

    float ans=0;
    while (!pq.empty()){
       // cout << " in ";
        float ub = pq.top().first[0]; float left = pq.top().first[1]; float old =pq.top().first[2]; int ind = pq.top().second; pq.pop();
        //cout << " ind : " << ind << " ub : " << ub << " left : " << left << " old  " << old <<endl;
        if (ub>ans){
         //   cout << old << " ";
            if (ind==ppw.size()){
                if (old>ans) {
                    ans=old;
                }
            }
            if (ind<ppw.size()){

                //ไม่เอา
                float up = 0;
                findUpperB(ppw,price,weight,up,left,ind+1);
                pq.push({{up+old,left,old},ind+1});


                if (left-weight[ppw[ind].second]>=0){

                    up = 0;
                    findUpperB(ppw,price,weight,up,left-weight[ppw[ind].second],ind+1);
                    old += price[ppw[ind].second];
                    pq.push({{up+old,left-weight[ppw[ind].second],old},ind+1});
                }

            }

        }
        else break;
    }

    printf("%.4lf",ans);
}
