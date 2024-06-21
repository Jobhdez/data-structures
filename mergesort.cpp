#include <iostream>
#include <vector>

class Mergesort {
public:
    void mergesort(std::vector<int>& vec) {
        std::vector<int> temp(vec.size());
        mergesort(vec, temp, 0, vec.size() - 1);
    }

private:
    void mergesort(std::vector<int>& vec, std::vector<int>& temp, int left_start, int right_end) {
        if (left_start >= right_end)
            return;
        int middle = (left_start + right_end) / 2;
        mergesort(vec, temp, left_start, middle);
        mergesort(vec, temp, middle + 1, right_end);
        mergehalves(vec, temp, left_start, right_end);
    }

    void mergehalves(std::vector<int>& vec, std::vector<int>& temp, int left_start, int right_end) {
        int left_end = (right_end + left_start) / 2;
        int right_start = left_end + 1;

        int left = left_start;
        int right = right_start;
        int index = left_start;

        while (left <= left_end && right <= right_end) {
            if (vec[left] <= vec[right]) {
                temp[index] = vec[left];
                left++;
            } else {
                temp[index] = vec[right];
                right++;
            }
            index++;
        }

        std::copy(vec.begin() + left, vec.begin() + left_end + 1, temp.begin() + index);
        std::copy(vec.begin() + right, vec.begin() + right_end + 1, temp.begin() + index);

        std::copy(temp.begin() + left_start, temp.begin() + right_end + 1, vec.begin() + left_start);
    }
};

int main() {
    std::vector<int> vec = {38, 27, 43, 3, 9, 82, 10};
    Mergesort sorter;
    sorter.mergesort(vec);

    std::cout << "Sorted array: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
