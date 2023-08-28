#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  queue<int> q;

  char operation;
  int temp;

  while (N > 0) {
    N--;

    cin >> operation;
    switch (operation) {
    case 'E':
      cin >> temp;
      q.push(temp);
      cout << q.size() << endl;
      break;
    case 'D':
      if (q.empty())
        cout << -1;
      else {
        temp = q.front();
        q.pop();
        cout << temp;
      }
      cout << " " << q.size() << endl;
      break;
    default:
      N++;
    }
  }
  return 0;
}