#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    int n,m,d;
    cin >> n >> m >> d;

    vector<vector<int>> process(d+1);

    for (int i=0; i<d; i++){
        vector<int> vec(3); int a;
        cin >> a >> vec[0] >> vec[1];
        process[a] = vec;
    }

    //sort(process.begin(),process.end());

    queue<int> produce;
    queue<int> req;

    for (int i=1; i<process.size();i++){
        if (process[i][0] == 0){
            if (!req.empty()){
                cout << req.front() << "\n";
                req.pop();
            }
            else {
                produce.push(process[i][1]);
                cout << "0" << "\n";
            }
        }
        else if (process[i][0]==1) {
            if (!produce.empty()){
                cout << produce.front() << "\n";
                produce.pop();
            }
            else {
                req.push(process[i][1]);
                cout << "0" << "\n";
            }
        }
    }
}
