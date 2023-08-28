#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
  Node *partition(Node *head, int val) {
    Node *left = NULL, *right = NULL;
    Node *l_head = NULL, *r_head = NULL;
    while (head != NULL) {
      if (head->data < val) {
        if (left == NULL) {
          left = head;
          l_head = head;
        } else {
          left->next = head;
          left = left->next;
        }
      } else {
        if (right == NULL) {
          right = head;
          r_head = head;
        } else {
          right->next = head;
          right = right->next;
        }
      }
      head = head->next;
    }

    if (right != NULL)
      right->next = NULL;
    if (l_head == NULL)
      return r_head;

    left->next = r_head;

    return l_head;
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
  int n, value, val;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  cin >> val;
  class Outscal s;
  Node *temp = s.partition(head, val);
  printList(temp);
  return 0;
}