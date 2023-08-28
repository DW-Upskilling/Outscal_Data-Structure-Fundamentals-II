#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
  Node *oddeven(Node *head) {
    if (head == NULL || head->next == NULL)
      return head;
    Node *odd = head;
    Node *even = head->next;
    Node *temp = even;
    int i = 1;
    for (Node *itr = even->next; itr != NULL; itr = itr->next, i++) {
      if (i % 2 != 0) {
        odd->next = itr;
        odd = odd->next;
      } else {
        even->next = itr;
        even = even->next;
      }
    }
    even->next = NULL;
    odd->next = temp;
    return head;
  }
};

void printList(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
}

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
  Node *temp = s.oddeven(head);
  printList(temp);
  return 0;
}