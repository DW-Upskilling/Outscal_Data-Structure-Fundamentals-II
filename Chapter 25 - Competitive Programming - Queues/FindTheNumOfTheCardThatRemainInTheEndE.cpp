#include <bits/stdc++.h>
using namespace std;

int remainingCard(int n) {
  /*
  1. There will be n cards on the deck, starting with '1'
  2. Based on given rules, no even number card will be on the deck at the end of
  first iteration so ignoring all even numbers when adding to the deck
  3. If n even not an issue, if n is odd then n will be left at the end of so it
  should be first element in the deck
*/
  queue<int> deck;
  int prev = 1;

  if (n % 2 != 0)
    deck.push(n);
  for (int i = 1; i <= n / 2; i++) {
    deck.push(prev);
    prev += 2;
  }

  /*
  Iterating over the queue until there is only one element left.
  */
  while (!deck.empty() && deck.size() > 1) {
    int prev = deck.front();
    deck.pop();
    deck.pop();
    deck.push(prev);
  }

  return deck.front();
}

// Driver code
int main() {
  int n;
  cin >> n;
  cout << remainingCard(n);

  return 0;
}
