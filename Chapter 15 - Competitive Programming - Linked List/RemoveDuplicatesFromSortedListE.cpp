#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:  
  void removeDuplicates(Node *head) {
    if (head == NULL || head->next == NULL)
      return;
    Node *prev = head;
    Node *curr = head->next;
    while(curr != NULL){
      if(curr->data != prev->data){
        prev->next = curr;
        prev = prev->next;
      }
      curr = curr->next;
    }
    prev->next = curr;
  }
};
/*
  1 2 3 3 3 4 4 5 5 5
  1 2 3 -> 4 -> 5
  prev = 3 
  curr = 4
*/

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
  s.removeDuplicates(head);
  printList(head);
  return 0;
}