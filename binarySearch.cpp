#include <vector>
#include <iostream>

class BinarySearch {
    private:
    std::vector<int> nums;
    int target;
    public:

    BinarySearch(std::vector<int> arr, int t) {
        this->nums = arr;
        this->target = t;
    }

    int search() {
        int l = 0;
        int r = this->nums.size() - 1;

        while (l <= r) {
            int mid = l + ((r - l) / 2);
            if (this->nums[mid] > this->target) {
                r = mid - 1;
            }
            else if (this->nums[mid] < this->target) {
                l = mid + 1;
            } else {
                return mid;
            }

        }
        return -1;
    }
};

int main() {
    std::vector<int> nums = {-1, 0, 2,4,6,8};
    BinarySearch bs(nums, 4);
    std::cout << bs.search() << std::endl;

}