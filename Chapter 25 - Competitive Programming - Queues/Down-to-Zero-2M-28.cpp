#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
 * Complete the downToZero function below.
 */
int downToZero(int n) {
  int output = 0, multiple, temp;
  while (n > 0) {
    multiple = n;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        temp = max(i, n / i);
        multiple = min(multiple, temp);
      }
    }
    if (multiple == n) {
      n--;

    } else {
      n = multiple;
    }
    output++;
  }

  return output;
}

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = downToZero(n);

    cout << result << "\n";
  }

  return 0;
}
