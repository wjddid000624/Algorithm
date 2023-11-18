#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1010
#define INF 987654321
char MAP[MAX][MAX];
int visited[MAX][MAX], N, M, ans;

void dfs(int x, int y){
  visited[x][y] = 1;
  int nx, ny;
  if(MAP[x][y] == 'U'){
    nx = x - 1;
    ny = y;
  }
  else if(MAP[x][y] == 'D'){
    nx = x + 1;
    ny = y;
  }
  else if(MAP[x][y] == 'L'){
    nx = x;
    ny = y - 1;
  }
  else{
    nx = x;
    ny = y + 1;
  }

  if(visited[nx][ny] == 1) ans++;
  else if(visited[nx][ny] == 0) dfs(nx, ny);
  visited[x][y] = 2;
  
}

void solve(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(visited[i][j] == 0) dfs(i, j);
    }
  }

  cout << ans;
}

void input(){
  cin >> N >> M;
  int num = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> MAP[i][j];
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  solve();

  return 0;
}