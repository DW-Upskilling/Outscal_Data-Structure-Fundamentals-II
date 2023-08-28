#include <bits/stdc++.h>
using namespace std;

// Complete this function
vector<int> FindMultiplication(vector<int> &arr) {
  priority_queue<int> pq;
  vector<int> output;

  int a, b, c, result;
  for (auto i : arr) {
    pq.push(i);
    result = -1;
    if (pq.size() > 2) {
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      c = pq.top();
      result = a * b * c;
      pq.push(a);
      pq.push(b);
    }
    output.push_back(result);
  }

  return output;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &e : arr)
    cin >> e;
  auto ans = FindMultiplication(arr);
  for (auto e : ans)
    cout << e << '\n';
}
