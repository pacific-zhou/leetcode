// date 20231011
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>
#include <unordered_map>
#include <set>
#include <climits>
#include <stack>

using namespace std;

vector<int> leetcode_1(vector<int> &nums, int target) {
  vector<int> result;
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); ++i) {
    int t = target - nums[i];
    if (m.find(t) != m.end()) {
      result.push_back(m[t]);
      result.push_back(i);
    } else {
      m[nums[i]] = i;
    }
  }
  return result;
}

bool leetcode_9(int x) {
  if (x < 0) {
    return false;
  }
  long reverse = 0, t = x;
  while (t > 0) {
    reverse = reverse * 10 + t % 10;
    t = t / 10;
  }
  return x == reverse;
}

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


bool leetcode_20(string s) {
  stack<char> st;
  map<char, char> m = {{')', '('},
                       {'}', '{'},
                       {']', '['}};
  for (char c: s) {
    if (m.find(c) != m.end()) {
      if (st.empty() or m[c] != st.top()) {
        return false;
      }
      st.pop();
    } else {
      st.push(c);
    }
  }
  return st.empty();
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *leetcode_21(ListNode *list1, ListNode *list2) {
  ListNode *head = new ListNode(), *tmp = head;
  while (list1 != NULL and list2 != NULL) {
    if (list1->val <= list2->val) {
      tmp->next = list1;
      list1 = list1->next;
    } else {
      tmp->next = list2;
      list2 = list2->next;
    }
    tmp = tmp->next;
  }
  tmp->next = list1 == NULL ? list2 : list1;
  return head->next;
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

string leetcode_67(string a, string b) {
  string result;
  int i = a.size() - 1, j = b.size() - 1;
  int carry = 0;
  while (i >= 0 or j >= 0) {
    if (i >= 0) {
      carry += a[i] - '0';
    }
    if (j >= 0) {
      carry += b[j] - '0';
    }
    result += to_string(carry % 2);
    carry /= 2;
    i--;
    j--;
  }
  if (carry > 0) {
    result.push_back('1');
  }
  std::reverse(result.begin(), result.end());
  return result;
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool leetcode_100(TreeNode *p, TreeNode *q) {
  if (p == nullptr and q == nullptr) {
    return true;
  }
  if (p == nullptr and q != nullptr) {
    return false;
  }
  if (p != nullptr and q == nullptr) {
    return false;
  }
  if (p->val == q->val) {
    return leetcode_100(p->left, q->left) and leetcode_100(p->right, q->right);
  } else {
    return false;
  }
}

bool check(TreeNode *left, TreeNode *right) {
  if (left != nullptr and right != nullptr) {
    if (left->val != right->val) {
      return false;
    }
    return check(left->left, right->right) and check(left->right, right->left);
  }
  if (left == nullptr and right != nullptr) {
    return false;
  }
  if (left != nullptr and right == nullptr) {
    return false;
  }
  return true;
}

bool leetcode_101(TreeNode *root) {
  return check(root, root);
}

int leetcode_104(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  return max(leetcode_104(root->left), leetcode_104(root->right)) + 1;
}

bool leetcode_112(TreeNode *root, int targetSum) {
  if (root == nullptr) {
    return false;
  }
  if (root->left == nullptr and root->right == nullptr) {
    return targetSum == root->val;
  }
  return leetcode_112(root->left, targetSum - root->val) || leetcode_112(root->right, targetSum - root->val);
}

/*struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};*/

bool leetcode_141(ListNode *head) {
  if (head == NULL or head->next == NULL) {
    return false;
  }
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (fast != NULL and fast->next != NULL) {
    if (slow == fast) {
      return true;
    }
    fast = fast->next->next;
    slow = slow->next;
  }
  return false;
}

int getSum(int n) {
  int sum = 0;
  while (n > 0) {
    int div = n % 10;
    sum += div * div;
    n = n / 10;
  }
  return sum;
}

bool leetcode_202(int n) {
  set<int> s;
  while (true) {
    int sum = getSum(n);
    if (sum == 1) {
      return true;
    } else {
      if (s.find(sum) == s.end()) {
        s.insert(sum);
        n = sum;
      } else {
        return false;
      }
    }
  }
  return false;
}

bool leetcode_205(string s, string t) {

  unordered_map<char, char> m;
  unordered_map<char, char> n;
  for (int i = 0; i < t.size(); ++i) {
    if (m.find(t[i]) != m.end() && n.find(s[i]) != n.end()) {
      if (m[t[i]] != s[i] or n[s[i] != m[i]]) {
        return false;
      }
    } else if (m.find(t[i]) == m.end() && n.find(s[i]) == n.end()) {
      m[t[i]] = s[i];
      n[s[i]] = t[i];
    } else {
      return false;
    }
  }
  return true;
}

bool leetcode_219(vector<int> &nums, int k) {
  map<int, int> m;
  for (int i = 0; i < nums.size(); ++i) {
    if (m.find(nums[i]) != m.end()) {
      if (i - m[nums[i]] <= k) {
        return true;
      }
    }
    m[nums[i]] = i;
  }
  return false;
}

int leetcode_222(TreeNode *root) {
  if (root == NULL) return 0;
  return 1 + leetcode_222(root->left) + leetcode_222(root->right);
}

TreeNode *leetcode_226(TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }
  TreeNode *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

vector<string> leetcode_228(vector<int> &nums) {
  vector<string> result;
  int i = 0;
  while (i < nums.size()) {
    int low = i;
    i++;
    while (i < nums.size() and nums[i] == nums[i - 1] + 1) {
      i++;
    }
    int high = i - 1;
    string element = to_string(nums[low]);
    if (high > low) {
      element.append("->");
      element.append(to_string(nums[high]));
    }
    result.push_back(element);
  }
  return result;
}

//  1 2 3 4
//s 1 2 6 24
//e 24 24 12 4
//  24,12,8,6
vector<int> leetcode_238(vector<int> &nums) {
  vector<int> s(nums.size());
  vector<int> e(nums.size());
  vector<int> result(nums.size());
  s[0] = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    s[i] = s[i - 1] * nums[i];
  }
  e[nums.size() - 1] = nums[nums.size() - 1];
  for (int i = nums.size() - 2; i >= 0; --i) {
    e[i] = e[i + 1] * nums[i];
  }
  result[0] = e[1];
  result[nums.size() - 1] = s[nums.size() - 2];
  for (int i = 1; i < nums.size() - 1; ++i) {
    result[i] = s[i - 1] * e[i + 1];
  }
  return result;
}

bool leetcode_242(string s, string t) {
  vector<int> v(26, 0);
  for (char c: s) {
    v[c - 'a']++;
  }
  for (char c: t) {
    v[c - 'a']--;
  }
  for (int c: v) {
    if (c != 0) {
      return false;
    }
  }
  return true;
}

bool leetcode_290(string pattern, string s) {
  unordered_map<char, string> m;
  unordered_map<string, char> n;
  int j = 0, k = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ' or i == s.size() - 1) {
      string substr = s.substr(k, i - k);
      if (i == s.size() - 1) {
        substr = s.substr(k, i - k + 1);
      }
      char c = pattern[j];
      if (n.find(substr) != n.end() && m.find(c) != m.end()) {
        if (n[substr] != c or m[c] != substr) {
          return false;
        }
      } else if (n.find(substr) == n.end() && m.find(c) == m.end()) {
        n[substr] = c;
        m[c] = substr;
      } else {
        return false;
      }
      j++;
      k = i + 1;
    }
  }
  if (j < pattern.size()) {
    return false;
  }
  return true;
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

char toLower(char c) {
  if (c >= 'A' and c <= 'Z') {
    return c + 32;
  }
  return c;
}

bool leetcode_125_1(string s) {
  int j = s.size() - 1;
  for (int i = 0; i < s.size() / 2; ++i) {
    if (isAlpha(s[i]) or isdigit(s[i])) {
      for (; j >= 0; --j) {
        if (isAlpha(s[j]) or isdigit(s[i])) {
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

bool leetcode_125_2(string s) {
  string new_str;
  for (char c: s) {
    if (isAlpha(c) or isdigit(c)) {
      new_str.push_back(toLower(c));
    }
  }
  string reverse_str(new_str.rbegin(), new_str.rend());
  return reverse_str == new_str;
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

bool leetcode_392(string s, string t) {
  if (s.empty()) {
    return true;
  }
  int i = 0, j = 0;
  bool find = false;
  while (i < s.size() and j < t.size()) {
    if (s[i] == t[j]) {
      i++;
      find = true;
    } else {
      find = false;
    }
    j++;
  }
  if (i < s.size()) {
    return false;
  }
  return find;
}

vector<int> traverse(TreeNode *root) {
  if (root == NULL) {
    return vector<int>();
  }
  vector<int> result;
  vector<int> left_result = traverse(root->left);
  vector<int> right_result = traverse(root->right);
  for (int i: left_result) {
    result.emplace_back(i);
  }
  result.emplace_back(root->val);
  for (int i: right_result) {
    result.emplace_back(i);
  }
  return result;
}

int leetcode_530(TreeNode *root) {
  vector<int> v = traverse(root);
  std::sort(v.begin(), v.end());
  int min_gap = INT_MAX;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] - v[i - 1] < min_gap) {
      min_gap = v[i] - v[i - 1];
    }
  }
  return min_gap;
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
