#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    vector<vector<int>> board(4);
    vector<int> vec(4);
    vector<vector<int>> pos;

    for (int i=0; i<4; i++){
        board.push_back(vec);
        pos.push_back(vec);
    }
    int i=1;
    for (int r=1; r<=4; r++){
        for (int c=1; c<=4; c++){
            cin >> board[r][c];
            pos[r][c] = i; i++;
        }
    }
    pos[4][4]=0;

    priority_queue<vector<vector<vector<int>>> pq;

    int diff=0;
    for (int r=1; r<=4;r++){
        for (int c=1; c<=4; c++){
            if (board[r][c]!=pos[r][c]){
                diff =
            }
        }
    }

    pq.push({{}})
    while (!pq.empty()){

    }
}
