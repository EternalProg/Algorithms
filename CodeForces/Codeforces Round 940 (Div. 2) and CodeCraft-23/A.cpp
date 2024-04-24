#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int N = 0;
    std::cin >> N;

    vector<int> a(101, 0);
    for (int i = 0; i < N; i++) {
      int x; 
      cin >> x;
      a[x]++;
    }
    int sum = 0;
    for (auto& s : a) 
      sum += s / 3;
    cout << sum << "\n";
  }
}