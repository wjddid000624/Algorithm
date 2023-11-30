#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000001
int num[MAX], N;
vector<int> LIS;

int bs(int k) {
  int lo = 0, hi = LIS.size() - 1, mid;

  while (lo < hi) {
    mid = (hi + lo) / 2;
    if (LIS[mid] >= k) 
      hi = mid;
    else lo = mid + 1;
  }

  return hi;
}

void input(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
}

void solve(){
  LIS.push_back(num[0]);
  for(int i = 1; i < N; i++){
    if(num[i] > LIS.back()){
      LIS.push_back(num[i]);
    }
    else{
      int idx = bs(num[i]);
      LIS[idx] = num[i];
    }
  }
  cout << LIS.size();
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  solve();

  return 0;
}