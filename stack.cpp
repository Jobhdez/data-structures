#include <iostream>
#include <string>

template <class T>
class Stack {
  T* stack_;
  int size_;
  int top_;

public:
  Stack(int size) {
    size_ = size;
    stack_ = new T[size];
    top_ = -1;
  }
  ~Stack() {
    delete[] stack_;
  }
  bool StackEmpty() {
    return top_ == -1;
  }

  bool StackFull() {
    return top_ == size_ - 1;
  }

  void Push(T element) {
    stack_[++top_] = element;
  }

  T Pop() {
    return stack_[top_--];
  }

  void PushCheck(T element) {
    if (StackFull())
      throw std::overflow_error("overflow");
    else
      Push(element);
  }

  T PopCheck() {
    if (StackEmpty())
      throw std::underflow_error("underflow");
    else
      return Pop();
  }
};

int main() {
  // Example 1: Stack of integers
  Stack<int> intStack(5);
  intStack.PushCheck(1);
  intStack.PushCheck(2);
  intStack.PushCheck(3);
  std::cout << "Popped from intStack: " << intStack.PopCheck() << std::endl;
  std::cout << "Popped from intStack: " << intStack.PopCheck() << std::endl;

  // Example 2: Stack of strings
  Stack<std::string> stringStack(5);
  stringStack.PushCheck("hello");
  stringStack.PushCheck("world");
  std::cout << "Popped from stringStack: " << stringStack.PopCheck() << std::endl;
  std::cout << "Popped from stringStack: " << stringStack.PopCheck() << std::endl;

  return 0;
}
