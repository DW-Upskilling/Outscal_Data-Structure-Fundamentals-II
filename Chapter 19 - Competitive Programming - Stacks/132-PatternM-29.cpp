#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Outscal {
public: 
  bool find132pattern(vector<int> nums) {
    if (nums.size() < 3)
      return false;
    stack<int> stack;
    int third = INT_MIN;

    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < third) {
        return true;
      }

      while (!stack.empty() && nums[i] > stack.top()) {
        third = stack.top();
        stack.pop();
      }

      stack.push(nums[i]);
    }

    return false;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int m;
  int temp;
  vector<int> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  bool ans = s.find132pattern(brr);
  if (ans)
    cout << "True";
  else
    cout << "False";
  return (0);
}
