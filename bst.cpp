#include <iostream>
#include <algorithm>

using namespace std;

class Node {
private:
    Node *left, *right;
    int data;
public:
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value) {
        if (value <= this->data) {
            if (left == nullptr) {
                left = new Node(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == nullptr) {
                right = new Node(value);
            } else {
                right->insert(value);
            }
        }
    }

    bool contains(int value) {
        if (value == this->data)
            return true;
        if (value < this->data) {
            if (this->left == nullptr)
                return false;
            return this->left->contains(value);
        }
        if (this->right == nullptr)
            return false;
        return this->right->contains(value);
    }

    void print_in_order() {
        if (this->left != nullptr) {
            this->left->print_in_order();
        }
        cout << this->data << "\t" << endl;
        if (this->right != nullptr) {
            this->right->print_in_order();
        }
    }
};

int main() {
    Node* root = new Node(4);
    root->insert(2);
    root->insert(1);
    root->insert(3);
    root->insert(6);
    root->insert(5);
    root->insert(7);
    cout << "in-order:" << endl;
    root->print_in_order();
    cout << endl;

    return 0;
}
