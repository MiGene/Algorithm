#include <iostream>
#include<vector>
#include<queue>
#include<numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<pair<int,int>> q;
    for (int i=1; i<n;i++){
        q.push({i,i});
    }
    int total =1;

    while (!q.empty()){
        int c = q.front().first; int summ = q.front().second; q.pop();

        for (int i=c; i<n; i++){
            int sum1 = summ+i;
            if ( sum1 < n) {
                q.push({i,sum1});
            }
            else if (sum1 == n) total += 1;
        }

    }

    cout << total;
}
