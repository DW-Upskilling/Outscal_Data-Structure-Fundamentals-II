#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
  Node *_reverse(Node *node) {
    if (node == NULL || node->next == NULL)
      return node;

    Node *previous = _reverse(node->next);
    previous->next = node;

    return node;
  }

public:
  Node *reverse(Node *head, int k) {
    if (head == NULL || head->next == NULL || k < 2)
      return head;

    Node *node = new Node();
    node->next = head;
    Node *current = node, *start, *end, *temp;
    bool flg;

    while (current != NULL && current->next != NULL) {
      start = current->next;
      end = start;
      flg = true;
      for (int i = 1; i < k; i++) {
        if (end->next == NULL) {
          flg = false;
          break;
        }
        end = end->next;
      }
      if (!flg)
        break;
      temp = end->next;
      end->next = NULL;

      _reverse(start);

      current->next = end;
      start->next = temp;

      current = start;
    }

    return node->next;
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
  int n, value, k;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  cin >> k;
  class Outscal s;
  Node *temp = s.reverse(head, k);
  printList(temp);
  return 0;
}