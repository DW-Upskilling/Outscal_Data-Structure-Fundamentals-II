#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  vector<int> commonPrefix(vector<int> nums1, vector<int> nums2) {
    vector<int> output;
    bool flg = false;
    for (int i = 0; i < nums1.size(); i++) {
      flg = false;
      output.push_back(-1);
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j]) {
          flg = true;
        } else if (flg && nums2[j] > nums1[i]) {
          output[i] = nums2[j];
          break;
        }
      }
    }
    return output;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int m, temp, i, n;
  vector<int> brr, arr;
  cin >> m >> n;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  while (n) {
    cin >> temp;
    arr.push_back(temp);
    n--;
  }
  class Outscal s;
  vector<int> ans = s.commonPrefix(brr, arr);
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return (0);
}
