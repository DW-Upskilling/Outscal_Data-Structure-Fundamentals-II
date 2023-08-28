#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  vector<int> asteroidCollision(vector<int> asteroids) {
    vector<int> output;
    bool flg;
    for (int i = 0; i < asteroids.size(); i++) {
      flg = true;
      while (output.size() > 0 && output[output.size() - 1] >= 0 &&
             asteroids[i] < 0) {
        if (output[output.size() - 1] == (-1 * asteroids[i])) {
          output.pop_back();
          flg = false;
          break;
        } else if (output[output.size() - 1] < (-1 * asteroids[i])) {
          output.pop_back();
        } else {
          flg = false;
          break;
        }
      }
      if (flg)
        output.push_back(asteroids[i]);
    }

    return output;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int m, i, temp;
  vector<int> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  vector<int> ans = s.asteroidCollision(brr);
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return (0);
}
