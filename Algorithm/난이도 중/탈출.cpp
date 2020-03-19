#include <iostream>
#include <queue>
using namespace std;

char map[50][50];
int visit[50][50];
int dir[4][2] = { {1,0},{-1,0}, {0,1},{0,-1} };
queue<pair<int, int>> river;
pair<int, int> start, goal;
int sx, sy;

int Ischecked(int a,int b) {
	return ( 0 <= a && a < sx) && (0 <= b && b < sy);
}

int BFS() {
	queue<pair<int, int>> move;
	move.push(start);
	visit[start.first][start.second];
	while (!move.empty()) {
		int riverSize = river.size();
		for (int i = 0; i < riverSize; i++) {
			int rx = river.front().first;
			int ry = river.front().second;
			river.pop();
			for (int k = 0; k < 4; k++) {
				int Next_rx = rx + dir[k][0];
				int Next_ry = ry + dir[k][1];
				if (Ischecked(Next_rx,Next_ry) &&map[Next_rx][Next_ry] == '.') {
					map[Next_rx][Next_ry] = '*';
					river.push(make_pair(Next_rx, Next_ry));
				}

			}
		}

		int moveSize = move.size();
		for (int i = 0; i < moveSize; i++) {
			int rx = move.front().first;
			int ry = move.front().second;
			move.pop();
			if (goal.first == rx && goal.second == ry) {
				return visit[rx][ry];
			}
			for (int k = 0; k < 4; k++) {
				int Next_rx = rx + dir[k][0];
				int Next_ry = ry + dir[k][1];
				if (Ischecked(Next_rx, Next_ry) && map[Next_rx][Next_ry] != '*' && map[Next_rx][Next_ry] != 'X'&& visit[Next_rx][Next_ry]==0) {
					//cout << Next_rx << " ," << Next_ry << endl;
					visit[Next_rx][Next_ry] = visit[rx][ry] +1;
					move.push(make_pair(Next_rx, Next_ry));
				}

			}
		}
	}
	return -1;
}

int main() {
	cin >> sx >> sy;
	for (int i = 0; i < sx; i++) {
		for (int j = 0; j < sy; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < sx; i++) {
		for (int j = 0; j < sy; j++) {
			if (map[i][j] == 'D') {
				goal = make_pair(i, j);
			}
			else if (map[i][j] == 'S') {
				start = make_pair(i, j);
			}
			else if (map[i][j] == '*') {
				river.push(make_pair(i, j));
			}
		}
	}
	int result = BFS();
	if (result == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << result;
	}
}
