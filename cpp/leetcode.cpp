// date 20231011
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

int leetcode121(vector<int>& prices) {
    int min_price = INT32_MAX, max_profit = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < min_price) {
            min_price = prices[i];
            continue;
        }
        if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
        }
    }
    return max_profit;
}

// 摩尔投票法
int leetcode169(vector<int> &nums) {
    int count = 0, tmp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (count == 0) {
            tmp = nums[i];
        }
        if (tmp == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    return tmp;
}

void reverse_array(vector<int> &nums, int start, int end) {
    for (int i = 0; i <= (end - start) / 2; ++i) {
        int tmp = nums[start + i];
        nums[start + i] = nums[end - i];
        nums[end - i] = tmp;
    }
}

void leetcode189(vector<int> &nums, int k) {
    k %= nums.size();
    if (nums.size() == 1 or k == 0) {
        return;
    }
    reverse_array(nums, 0, nums.size() - 1);
    reverse_array(nums, 0, k - 1);
    reverse_array(nums, k, nums.size() - 1);
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

    cout << ">>>>>>>189" << endl;
    vector<int> v189 = {7, 6, 5, 4, 3, 2, 1};
    reverse_array(v189, 3, 6);
    for (const auto &item: v189) {
        cout << item << endl;
    }

    return 0;
}
