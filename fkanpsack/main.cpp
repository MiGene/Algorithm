#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int N; float W;
    cin >> W >> N;
    vector<float> price(N);
    vector<float> weight(N);

    for (int i=0; i<N;i++) cin >> price[i];
    for (int i=0; i<N;i++) cin >> weight[i];

    priority_queue<pair<float,int>> pq;
    for (int i=0; i<N; i++){
        float point = price[i]/weight[i];
        pq.push({point, i});
    }


    float total_p = 0;
    while (!pq.empty()){
        float point = pq.top().first; int ind = pq.top().second; pq.pop();
        //cout << point << " " << ind << endl;
        if (W-weight[ind]<0){
            float diff = W;
            total_p += diff*point;
            W = 0;
        }
        else {
            W -= weight[ind];
            total_p += price[ind];
        }
        //cout << W << endl;
        if (W<=0) break;
    }

    printf("%.4lf", total_p);
}
