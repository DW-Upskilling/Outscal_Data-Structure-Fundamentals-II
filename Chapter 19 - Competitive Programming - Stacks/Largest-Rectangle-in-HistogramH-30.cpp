#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  int largestRectangleArea(vector<int> histogram) {
    if (histogram.size() < 1)
      return 0;
    int output = histogram[0];
    int l, b, area;
    stack<int> st;

    for (int i = 0; i < histogram.size(); i++) {
      while (!st.empty() && histogram[i] < histogram[st.top()]) {
        l = histogram[st.top()];
        st.pop();
        b = st.empty() ? i : i - st.top() - 1;
        area = l * b;
        output = area > output ? area : output;
      }
      st.push(i);
    }

    while (!st.empty()) {
      l = histogram[st.top()];
      st.pop();
      b = st.empty() ? histogram.size() : histogram.size() - st.top() - 1;
      area = l * b;
      output = area > output ? area : output;
    }

    return output;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int m, temp;
  vector<int> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  int ans = s.largestRectangleArea(brr);
  cout << ans;
  return (0);
}
