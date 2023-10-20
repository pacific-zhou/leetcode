// date 20231011
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>
#include <unordered_map>

using namespace std;

string leetcode_12_1(int num) {
  std::vector<int> l = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  std::map<int, string> m = {{1,    "I"},
                             {4,    "IV"},
                             {5,    "V"},
                             {9,    "IX"},
                             {10,   "X"},
                             {40,   "XL"},
                             {50,   "L"},
                             {90,   "XC"},
                             {100,  "C"},
                             {400,  "CD"},
                             {500,  "D"},
                             {900,  "CM"},
                             {1000, "M"}};
  string result;
  int mod = 0, div = 0;
  while (true) {
    for (int i: l) {
      mod = num / i;
      div = num % i;
      if (mod >= 1) {
        for (int j = 0; j < mod; ++j) {
          result.append(m[i]);
        }
      }
      num = div;
    }
    if (div == 0) {
      break;
    }
  }
  return result;
}

string leetcode_12_2(int num) {
  const pair<int, string> valueSymbols[] = {
          {1000, "M"},
          {900,  "CM"},
          {500,  "D"},
          {400,  "CD"},
          {100,  "C"},
          {90,   "XC"},
          {50,   "L"},
          {40,   "XL"},
          {10,   "X"},
          {9,    "IX"},
          {5,    "V"},
          {4,    "IV"},
          {1,    "I"}};
  string result;
  for (const auto &[k, v]: m) {
    while (num >= k) {
      num -= k;
      result += v;
    }
    if (num == 0) {
      break;
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

int leetcode_28(string haystack, string needle) {
  auto index = haystack.find(needle);
  if (index == string::npos) {
    return -1;
  }
  return index;
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

bool leetcode_383_1(string ransomNote, string magazine) {
  unordered_map<char, int> m;
  for (char c: magazine) {
    if (m.find(c) != m.end()) {
      m[c]++;
    } else {
      m[c] = 1;
    }
  }

  for (char c: ransomNote) {
    if (m.find(c) != m.end() and m[c] > 0) {
      m[c]--;
    } else {
      return false;
    }
  }
  return true;
}

bool leetcode_383_2(string ransomNote, string magazine) {
  if (ransomNote.size() > magazine.size()) {
    return false;
  }
  vector<int> v(26, 0);
  for (char c: magazine) {
    v[c - 'a']++;
  }
  for (char c: ransomNote) {
    if (--v[c - 'a'] < 0) {
      return false;
    }
  }
  return true;
}


bool isAlpha(char c) {
  if (c >= 'a' and c <= 'z') {
    return true;
  }
  if (c >= 'A' and c <= 'Z') {
    return true;
  }
  return false;
}

bool toLower(char c) {
  if (c >= 'A' and c <= 'Z') {
    return toLower(c);
  }
  return c;
}

bool isPalindrome(string s) {
  int j = s.size() - 1;
  for (int i = 0; i < s.size() / 2; ++i) {
    if (isAlpha(s[i])) {
      for (; j >= 0; --j) {
        if (isAlpha(s[j])) {
          if (toLower(s[i]) == toLower(s[j])) {
            break;
          } else {
            return false;
          }
        }
        continue;
      }
    }
    continue;
  }
  return true;
}

// "  h  ello world tiffzhou  "
string leetcode_151(string s) {
  int m = 0;
  bool flag = true;
  vector<string> substrs;
  for (int j = 0; j < s.size(); ++j) {
    if (s[j] == ' ' and flag) {
      continue;
    }
    if (s[j] == ' ' and !flag) {
      flag = true;
      string substr = s.substr(m, j - m);
      substrs.push_back(substr);
      continue;
    }
    if (s[j] != ' ' and flag) {
      flag = false;
      m = j;
      if (j == s.size() - 1) {
        string substr = s.substr(m, j - m + 1);
        substrs.push_back(substr);
      }
      continue;
    }
    if (j == s.size() - 1 and !flag) {
      flag = true;
      string substr = s.substr(m, j - m + 1);
      substrs.push_back(substr);
      continue;
    }
  }
  if (substrs.size() == 0) {
    return "";
  }
  string result;
  for (int i = substrs.size() - 1; i >= 0; --i) {
    result += substrs[i];
    if (i != 0) {
      result += " ";
    }
  }
  return result;
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
