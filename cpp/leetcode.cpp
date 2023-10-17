// date 20231011
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

 DCXXI
 */
int leetcode_13_1(string s) {
  int result = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'I' and (i + 1) <= s.size() - 1 and s[i + 1] == 'V') {
      result += 4;
      ++i;
      continue;
    }
    if (s[i] == 'I' and (i + 1) <= s.size() - 1 and s[i + 1] == 'X') {
      result += 9;
      ++i;
      continue;
    }
    if (s[i] == 'I') {
      result += 1;
      continue;
    }
    if (s[i] == 'V') {
      result += 5;
    }
    if (s[i] == 'X' and (i + 1) <= s.size() - 1 and s[i + 1] == 'L') {
      result += 40;
      ++i;
      continue;
    }
    if (s[i] == 'X' and (i + 1) <= s.size() - 1 and s[i + 1] == 'C') {
      result += 90;
      ++i;
      continue;
    }
    if (s[i] == 'X') {
      result += 10;
      continue;
    }
    if (s[i] == 'L') {
      result += 50;
      continue;
    }
    if (s[i] == 'C' and (i + 1) <= s.size() - 1 and s[i + 1] == 'D') {
      result += 400;
      ++i;
      continue;
    }
    if (s[i] == 'C' and (i + 1) <= s.size() - 1 and s[i + 1] == 'M') {
      result += 900;
      ++i;
      continue;
    }
    if (s[i] == 'C') {
      result += 100;
    }
    if (s[i] == 'D') {
      result += 500;
      continue;
    }
    if (s[i] == 'M') {
      result += 1000;
      continue;
    }
  }
  return result;
}

/**
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

 DCXXI
 */
int leetcode_13_2(string s) {
  std::map<char, int> m = {{'I', 1},
                           {'V', 5},
                           {'X', 10},
                           {'L', 50},
                           {'C', 100},
                           {'D', 500},
                           {'M', 1000}};

  int result = 0;
  for (int i = 0; i < s.size(); ++i) {
    int v = m[s[i]];
    if ((i + 1) < s.size() - 1 and v < m[s[i + 1]]) {
      result += m[s[i + 1]] - v;
      ++i;
      continue;
    }
    result += m[s[i]];
  }
  return result;
}

// 从第二个字符串开始，都与第一个字符串逐个字符比较，不一致就退出
string leetcode_14(vector<string> &strs) {
  if (strs.empty()) {
    return "";
  }
  if (strs.size() == 1) {
    return strs[0];
  }
  int i = 0;
  bool result = true;
  for (int j = 0; j < strs[0].size(); ++j) {
    for (int k = 1; k < strs.size(); ++k) {
      result = strs[k][j] == strs[0][j];
      if (!result) {
        break;
      }
    }
    if (!result) {
      break;
    } else {
      i++;
    }
  }
  if (i > 0) {
    return strs[0].substr(0, i + 1);
  }
  return "";
}

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
