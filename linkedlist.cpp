#include <iostream>
#include <cstring> // For memcpy

using namespace std;

template <class T>
class Node {
public:
  T data_;
  Node* next_;

  Node(T data, Node* next) {
    data_ = data;
    next_ = next;
  }

  Node(T data) {
    data_ = data;
    next_ = NULL;
  }
};

template <class T>
class LinkedList {
public:
  Node<T>* head_ = NULL;

  Node<T>* search(T element_data) {
    Node<T>* x = head_;
    while (x != NULL && x->data_ != element_data) {
      x = x->next_;
    }
    return x;
  }

  void insert(T element_data) {
    head_ = new Node<T>(element_data, head_);
  }

  void deleteNode(Node<T>* element) {
    if (element == NULL) return;

    Node<T>* next;
    if (element->next_ != NULL) {
      next = element->next_;
      memcpy(&(element->data_), &(next->data_), sizeof(T));
      element->next_ = next->next_;
      delete next;
    } else {
      if (head_ == element) {
        head_ = NULL;
        delete element;
      } else {
        Node<T>* prev = head_;
        while (prev->next_ != element) {
          prev = prev->next_;
        }
        prev->next_ = NULL;
        delete element;
      }
    }
  }

  void reverse() {
    Node<T>* last = NULL;
    Node<T>* next = head_;
    while (next != NULL) {
      head_ = next;
      next = head_->next_;
      head_->next_ = last;
      last = head_;
    }
  }

  void print() {
    Node<T>* current = head_;
    while (current != NULL) {
      cout << current->data_ << " ";
      current = current->next_;
    }
    cout << endl;
  }

  ~LinkedList() {
    Node<T>* x = head_;
    while (x != NULL) {
      Node<T>* next = x->next_;
      delete x;
      x = next;
    }
  }
};

int main() {
  LinkedList<int> list;

  list.insert(10);
  list.insert(20);
  list.insert(30);


  cout << "Linked list contents: ";
  list.print();


  list.reverse();
  cout << "Reversed linked list contents: ";
  list.print();

  Node<int>* node = list.search(20);
  if (node != NULL) {
    cout << "Element 20 found in the list." << endl;
  } else {
    cout << "Element 20 not found in the list." << endl;
  }

  list.deleteNode(node);
  cout << "Linked list contents after deletion: ";
  list.print();

  return 0;
}
