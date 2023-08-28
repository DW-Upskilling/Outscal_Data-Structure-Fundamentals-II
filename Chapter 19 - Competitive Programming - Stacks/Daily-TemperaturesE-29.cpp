#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  vector<int> temperatures(vector<int> temperatures) {
    vector<int> output(temperatures.size(), 0);
    stack<int> st;
    int temp;

    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        temp = st.top();
        st.pop();
        output[temp] = i - temp;
      }
      st.push(i);
    }

    return output;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIE

int main() {
  int m, i;
  int temp;
  vector<int> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  vector<int> ans = s.temperatures(brr);
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return (0);
}
