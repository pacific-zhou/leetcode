
#include <iostream>
#include <vector>

using namespace std;

int leetcode26(vector<int> &nums) {
    int slow = 0, fast = 1;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
        fast++;
    }
    return ++slow;
}

int leetcode27(vector<int> &nums, int val) {
    int index = 0, size = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[index++] = nums[i];
            size++;
        }
    }
    return size;
}

int leetcode80(vector<int> &nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int slow = 2, fast = 2;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow - 2]) {
            nums[slow++] = nums[fast];
        }
        fast++;
    }
    return slow;
}

void leetcode88(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int s = m + n - 1;
    while (m > 0 && n > 0) {
        if (nums1[m - 1] >= nums2[n - 1]) {
            nums1[s--] = nums1[m-- - 1];
        } else {
            nums1[s--] = nums2[n-- - 1];
        }
    }

    for (int k = n; k > 0; --k) {
        nums1[s--] = nums2[k - 1];
    }
}


int main() {
    cout << "Hello, World!" << endl;

    // 27
    vector<int> v = {1, 2, 3, 1};
    cout << leetcode27(v, 1) << endl;

    // 88
    vector<int> a = {0};
    vector<int> b = {1};
    leetcode88(a, 0, b, 1);
    cout << a.size() << endl;

    return 0;
}
