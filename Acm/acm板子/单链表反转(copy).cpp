#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int _data) {
    data = _data;
    next = NULL;
  }
};

class LinkList {
public:
  LinkList() { head = NULL; }
  void Insert(Node *node, int position);
  void Output();
  void Reverse_order();

private:
  Node *head;
};

void LinkList::Insert(Node *node, int position) {
  if (head == NULL) {
    head = node;
    return;
  }
  if (position == 0) {
    node->next = head;
    head = node;
    return;
  }
  Node *current_node = head;
  int i = 0;
  while (current_node->next != NULL && i < position - 1) {
    current_node = current_node->next;
    i++;
  }
  if (i == position - 1) {
    node->next = current_node->next;
    current_node->next = node;
  }
}

void LinkList::Output() {
  if (head == NULL) {
    return;
  }
  Node *current_node = head;
  while (current_node != NULL) {
    cout << current_node->data << " ";
    current_node = current_node->next;
  }
  cout << endl;
}

void LinkList::Reverse_order() {
  if (head == NULL) {
    return;
  }
  Node *current_node = head->next, *next_node;
  head->next = NULL;
  while (current_node != NULL) {
    next_node = current_node->next;
    current_node->next = head;
    head = current_node;
    current_node = next_node;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LinkList linkList;
  for (int i = 1; i <= 10; i++) {
    Node *node = new Node(i);
    linkList.Insert(node, i - 1);
  }
  linkList.Output();
  linkList.Reverse_order();
  linkList.Output();
  return 0;
}