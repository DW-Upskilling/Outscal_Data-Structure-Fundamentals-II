#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
  bool isPalindrome(Node *head, Node *tail) {
    // Traversing to the end of the node holding the head
    if (tail->next == NULL) {
      // end of list discovered, checking if end node data and first node data
      // are same
      if (tail->data == head->next->data) {
        // if data match move the head placeholder to point next node
        head->next = head->next->next;
        return true;
      }
      return false;
    }
    // if and only if palindrom, recursion here
    // trying to do bottom up approach at same time keeping track of previous
    // node
    if (isPalindrome(head, tail->next)) {
      tail->next = tail->next;
      // if odd length then node address will be same
      // or else data must match between the nodes
      if (head->next == tail || head->next->data == tail->data) {
        head->next = head->next->next;
        return true;
      }
    }
    return false;
  }

public:
  bool detectpalindrome(Node *head) {
    if (head == NULL || head->next == NULL)
      return true;
    // creating a placeholder node which points the current node
    Node *node = new Node();
    node->next = head;
    return isPalindrome(node, head->next);
  }
};

void push(Node **head_ref, int new_data) {
  Node *new_node = new Node();
  Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

int main() {
  int n, value;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  class Outscal s;
  bool t = s.detectpalindrome(head);
  if (t)
    cout << "true";
  else
    cout << "false";
  return 0;
}