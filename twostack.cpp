#include <iostream>
#include <string>

template <class T>
class TwoStack
{
	T* stack_;
	int size_;
	int a_top_;
	int b_top_;

public:
	TwoStack(int size)
	{
		size_ = size;
		stack_ = new T[size];
		a_top_ = -1;
		b_top_ = size;
	}

	~TwoStack()
	{
		delete[] stack_;
	}

	bool AStackEmpty()
	{
		if (a_top_ == -1)
			return true;
		else
			return false;
	}

	bool BStackEmpty()
	{
		if (b_top_ == size_)
			return true;
		else
			return false;
	}

	//do NOT check overflow
	void APush(T element)
	{
		stack_[++a_top_] = element;
	}

	//do NOT check underflow
	T APop()
	{
		--a_top_;
		return stack_[a_top_ + 1];
	}

	//do NOT check overflow
	void BPush(T element)
	{
		stack_[--b_top_] = element;
	}

	//do NOT check underflow
	T BPop()
	{
		++b_top_;
		return stack_[b_top_ - 1];
	}
};

int main() {
	// Example with int
	TwoStack<int> intStack(10);
	intStack.APush(1);
	intStack.APush(2);
	intStack.APush(3);
	intStack.BPush(10);
	intStack.BPush(9);
	intStack.BPush(8);

	std::cout << "Int A stack pop: " << intStack.APop() << std::endl;
	std::cout << "Int A stack pop: " << intStack.APop() << std::endl;
	std::cout << "Int B stack pop: " << intStack.BPop() << std::endl;
	std::cout << "Int B stack pop: " << intStack.BPop() << std::endl;

	// Example with std::string
	TwoStack<std::string> stringStack(10);
	stringStack.APush("Hello");
	stringStack.APush("World");
	stringStack.BPush("Stack");
	stringStack.BPush("Example");

	std::cout << "String A stack pop: " << stringStack.APop() << std::endl;
	std::cout << "String A stack pop: " << stringStack.APop() << std::endl;
	std::cout << "String B stack pop: " << stringStack.BPop() << std::endl;
	std::cout << "String B stack pop: " << stringStack.BPop() << std::endl;

	return 0;
}
