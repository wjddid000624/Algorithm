#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define MAX 32001
int N, M, bigger[MAX];
bool printed[MAX];
vector<int> smaller[MAX];

void input(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int tmp1, tmp2; 
    cin >> tmp1 >> tmp2;
    smaller[tmp1].push_back(tmp2);
    bigger[tmp2] += 1;
  }
  memset(printed, false, sizeof(printed));
}

void solve(){
  int p = 0;
  while(p < N){
    for(int i = 1; i <= N; i++){
      if(bigger[i] == 0 && printed[i] == false){
        cout << i << " ";
        p++;
        printed[i] = true;
        for(int j = 0; j < smaller[i].size(); j++){
          bigger[ smaller[i][j] ] -= 1;
        }
      }

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
