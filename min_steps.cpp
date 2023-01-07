#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int step[N];
int min_steps(int i) {
  if (i == 1) return 0;
  if (step[i] != -1) return step[i];
  int ans = min_steps(i - 1) + 1;
  if (i % 2 == 0) {
    ans = min(ans, min_steps(i / 2) + 1);
  }
  if (i % 3 == 0) {
    ans = min(ans, min_steps(i / 3) + 1);
  }
  step[i] = ans;
  return step[i];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(step, -1, sizeof step);
  int n = 10;
  cout << min_steps(n) << '\n';
  return 0;
}
// You are given an integer n(1 \le n \le 10^5)n(1≤n≤1e5).You can perform the following 
// operations on it(as many as times as you want).

// 1.Subtract 1 from it. (assign n := n - 1)
// 2.If its divisible by 2, divide by 2. (if n mod 2 == 0, then assign n := n / 2)
// 3.If its divisible by 3, divide by 3. (if n mod 3 == 0, then assign n := n / 3).
// Find the minimum number of operations to make n = 1.

// Example: For n = 7, output: 3 (7 -1 = 6 /3 = 2 /2 = 1)

// What is your solution for this? Does greedy work?NO,Dp works