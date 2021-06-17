#include <string>
#include <vector>
#include <queue>

using namespace std;

int f[108][108];

int solution(vector<vector<int>> board) {
    for (int i = 0; i < 108; i++)
        for (int j = 0; j < 108; j++)
            f[i][j] = 1;
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board.size(); j++)
            f[i + 1][j + 1] = board[i][j];

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ {1,2},{0,0} }); //좌표,방향,걸린 시간순
    //방향 : 0=왼쪽 1=밑 2=오른쪽 3=위
    int y, x, d, t,addx,addy;
    while (!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        d = q.front().second.first;
        t = q.front().second.second;
        if (d == 0) {
            addx = x - 1;
            addy = y;
        }
        if (d == 1) {

        }
    }
    int answer = 0;
    return answer;
}