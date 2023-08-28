#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
  Node *swap(Node *head) {
    if (head == NULL || head->next == NULL)
      return head;

    Node *next = head->next;
    Node *temp = swap(next->next);
    next->next = head;
    head->next = temp;

    return next;
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
  Node *temp = s.swap(head);
  printList(temp);
  return 0;
}