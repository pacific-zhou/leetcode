// date 20231011
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int leetcode_27(vector<int> &nums, int val) {
  int i = 0;
  for (const int j: nums) {
    if (j != val) {
      nums[i++] = j;
    }
  }
  return i;
}

int leetcode_58(string s) {
  bool b = false;
  int c = 0;
  for (int j = s.size() - 1; j >= 0; --j) {
    if (s[j] != ' ') {
      c++;
      b = true;
    }
    if (s[j] == ' ' and b) {
      break;
    }
  }
  return c;
}

void leetcode_88_1(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  int i = m + n;
  while (m > 0 and n > 0) {
    if (nums1[m - 1] > nums2[n - 1]) {
      nums1[--i] = nums1[--m];
    } else {
      nums1[--i] = nums2[--n];
    }
  }
  while (n > 0) {
    nums1[--i] = nums2[--n];
  }
}

void leetcode_88_2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  for (int i = 0; i < n; ++i) {
    nums1[m + i] = nums2[i];
  }
  std::sort(nums1.begin(), nums1.end());
}

// main entry point
int main() {
  cout << "Hello, World!" << endl;

  // 58
  std::string str = "luffy is still joyboy";
  int c = leetcode_58(str);
  cout << "count:" << c << endl;


  cout << "finished" << endl;
  return 0;
}
