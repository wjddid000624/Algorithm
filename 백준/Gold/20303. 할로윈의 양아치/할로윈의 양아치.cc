#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 30010
int candy[MAX], N, M, K, ans, parent[MAX], size_group[MAX], DP[MAX][3010];
vector<int> group;

int find(int x){
  if(parent[x] == x){
    return x;
  }
  return parent[x] = find(parent[x]);
}

void Union(int x, int y){
  int x_root = find(x);
  int y_root = find(y);

  if(x_root < y_root){
    parent[y_root] = x_root;
  }
  else{
    parent[x_root] = y_root;
  }
}

void solve(){
  for(int i = 1; i <= N; i++){
    int p = find(i);
    if(p == i){
      group.push_back(i);
      size_group[p]++;
    }
    else{
      candy[p] += candy[i];
      size_group[p]++;
    }
  }

  for(int i = 0; i < group.size(); i++){
    int cur = group[i];
    int sizeGroup = size_group[cur];
    int candyGroup = candy[cur];

    for(int j = 0; j <= K - 1; j++){
      if(j - sizeGroup >= 0){
        DP[i+1][j] = max(DP[i][j], DP[i][j - sizeGroup] + candyGroup);
      }
      else{
        DP[i+1][j] = DP[i][j];
      }
      ans = max(ans, DP[i+1][j]);
    }
  }

  cout << ans;

}

void input(){
  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++){
    cin >> candy[i];
    parent[i] = i;
  }

  for(int i = 0; i < M; i++){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    Union(tmp1, tmp2);
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