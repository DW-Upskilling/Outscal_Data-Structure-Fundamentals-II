#include <bits/stdc++.h>
using namespace std;

bool isValidNumber(int n) {
  vector<int> counts(10, 0);
  int temp = n;
  while (temp > 0) {
    counts[temp % 10] += 1;
    temp /= 10;
  }

  bool flg = true;
  for (int i = 0; i < counts.size(); i++) {
    if (counts[i] > 1 || (i > 5 && counts[i] > 0))
      flg = false;
  }
  return flg;
}

int findcount(string l, string r) {
  int left = std::stoi(l);
  int right = std::stoi(r);
  int count = 0, temp;

  int curr = left;
  while (curr <= right) {
    if (isValidNumber(curr)) {
      count++;
    }
    curr++;
  }

  return count;
}

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {

  string l, r;
  cin >> l >> r;
  cout << findcount(l, r);

  return 0;
}
