#include <iostream>
#include <string>

template <class T>
class Queue
{
protected:
    T* queue_;
    int size_; // size of allocated memory; actual queue size = size_ - 1
    int tail_;
    int head_;

public:
    Queue(int size)
    {
        size_ = size + 1;
        queue_ = new T[size_];
        head_ = 0;
        tail_ = 0;
    }

    ~Queue()
    {
        delete[] queue_;
    }

    // do NOT check overflow
    void Enqueue(T element)
    {
        queue_[tail_] = element;
        if (tail_ == size_ - 1)
            tail_ = 0;
        else
            ++tail_;
    }

    T Dequeue()
    {
        T& element = queue_[head_];
        if (head_ == size_ - 1)
            head_ = 0;
        else
            ++head_;
        return element;
    }

    bool QueueEmpty()
    {
        if (tail_ == head_)
            return true;
        else
            return false;
    }

    bool QueueFull()
    {
        if (tail_ + 1 == head_ ||
            (tail_ == size_ - 1 && head_ == 0))
            return true;
        else
            return false;
    }

    void EnqueueCheck(T element)
    {
        if (QueueFull())
            throw "overflow";
        else
            Enqueue(element);
    }

    T DequeueCheck()
    {
        if (QueueEmpty())
            throw "underflow";
        return Dequeue();
    }
};

int main()
{
    // Example with integers
    Queue<int> intQueue(5);
    intQueue.EnqueueCheck(1);
    intQueue.EnqueueCheck(2);
    intQueue.EnqueueCheck(3);
    intQueue.EnqueueCheck(4);
    intQueue.EnqueueCheck(5);
    
    std::cout << "Dequeued from intQueue: " << intQueue.DequeueCheck() << std::endl;
    std::cout << "Dequeued from intQueue: " << intQueue.DequeueCheck() << std::endl;

    // Example with strings
    Queue<std::string> stringQueue(3);
    stringQueue.EnqueueCheck("apple");
    stringQueue.EnqueueCheck("banana");
    stringQueue.EnqueueCheck("cherry");

    std::cout << "Dequeued from stringQueue: " << stringQueue.DequeueCheck() << std::endl;
    std::cout << "Dequeued from stringQueue: " << stringQueue.DequeueCheck() << std::endl;

    return 0;
}
