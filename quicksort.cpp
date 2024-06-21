#include <iostream>
#include <vector>

class Quicksort {
public:
    void quicksort(std::vector<int>& vec) {
        quicksort(vec, 0, vec.size() - 1);
    }

private:
    void quicksort(std::vector<int>& vec, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = vec[(left + right) / 2];
        int index = partition(vec, left, right, pivot);
        quicksort(vec, left, index - 1);
        quicksort(vec, index, right);
    }

    int partition(std::vector<int>& vec, int left, int right, int pivot) {
        while (left <= right) {
            while (vec[left] < pivot) {
                left++;
            }
            while (vec[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(vec, left, right);
                left++;
                right--;
            }
        }
        return left;
    }

    void swap(std::vector<int>& vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
};

int main() {
    std::vector<int> vec = {3, 6, 8, 10, 1, 2, 1};
    Quicksort qs;
    qs.quicksort(vec);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
