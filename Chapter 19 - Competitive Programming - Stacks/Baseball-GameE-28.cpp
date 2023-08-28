#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  int game(vector<string> ops) {
    stack<int> st;
    int temp;

    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == "C") {
        if (!st.empty())
          st.pop();
      } else if (ops[i] == "D") {
        if (!st.empty())
          st.push(st.top() * 2);
      } else if (ops[i] == "+") {
        if (!st.empty()) {
          temp = st.top();
          st.pop();
          if (!st.empty()) {
            temp += st.top();
            st.push(temp - st.top());
          }
          st.push(temp);
        }
      } else {
        st.push(stoi(ops[i]));
      }
    }
    int output = 0;
    while (!st.empty()) {
      output += st.top();
      st.pop();
    }
    return output;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int m;
  string temp;
  vector<string> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  int ans = s.game(brr);
  cout << ans;
  return (0);
}
