// date 20231011
#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

ListNode *leetcode_2(ListNode *l1, ListNode *l2) {
  ListNode *head = nullptr, *tail = nullptr;
  int carry = 0;
  while (l1 || l2) {
    int l1_val = l1 == nullptr ? 0 : l1->val;
    int l2_val = l2 == nullptr ? 0 : l2->val;
    int sum = l1_val + l2_val + carry;
    if (head == nullptr) {
      head = tail = new ListNode(sum % 10);
    } else {
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
    }
    carry = sum / 10;
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
  }
  if (carry > 0) {
    tail->next = new ListNode(carry);
  }
  return head;
}

int leetcode_3(string s) {
  int fast = 0, slow = 0, max_count = 0;
  map<char, int> m;
  while (fast < s.length()) {
    if (m.find(s[fast]) != m.end()) {
      slow = max(slow, m[s[fast]] + 1);
    }
    max_count = max(max_count, fast - slow + 1);
    m[s[fast]] = fast;
    fast++;
  }
  return max_count;
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

int leetcode_11(vector<int> &height) {
  int i = 0, j = height.size() - 1;
  int area = 0;
  while (i < j) {
    area = max(area, min(height[i], height[j]) * (j - i));
    if (height[i] >= height[j]) {
      j--;
    } else {
      i++;
    }
  }
  return area;
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
  const pair<int, string> m[] = {
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
  for (const auto &e: m) {
    while (num >= e.first) {
      num -= e.first;
      result += e.second;
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

vector<vector<int>> leetcode_15(vector<int> &nums) {
  vector<vector<int>> result;
  if (nums.size() < 3) {
    return result;
  } // -4 -1 -1 0 1 2
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > 0) {
      break;
    }
    if (i > 0 and nums[i] == nums[i - 1]) {
      continue;
    }
    int l = i + 1;
    int r = nums.size() - 1;
    while (l < r) {
      int t = nums[i] + nums[l] + nums[r];
      if (t == 0) {
        vector<int> m = {nums[i], nums[l], nums[r]};
        result.push_back(m);
        while (l < r and nums[l] == nums[l + 1]) {
          l++;
        }
        while (l < r and nums[r] == nums[r - 1]) {
          r--;
        }
        l++;
        r--;
      } else if (t > 0) {
        r--;
      } else if (t < 0) {
        l++;
      }
    }
  }
  return result;
}

ListNode *leetcode_19(ListNode *head, int n) {
  int length = 0;
  ListNode *tmp = head;
  while (tmp) {
    length++;
    tmp = tmp->next;
  }
  int target = length - n;
  auto *dummy = new ListNode(0, head);
  tmp = dummy;
  while (target > 0) {
    tmp = tmp->next;
    target--;
  }
  tmp->next = tmp->next->next;
  ListNode *result = dummy->next;
  delete dummy;
  return result;
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

bool leetcode_36(vector<vector<char>> &board) {
  int row[9][9] = {}, col[9][9] = {};
  int boxes[3][3][9] = {};
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      char c = board[i][j];
      if (c == '.') {
        continue;
      }
      int index = c - '0' - 1;
      row[i][index]++;
      col[index][j]++;
      boxes[i / 3][j / 3][index]++;
      if (row[i][index] > 1 || col[index][j] > 1 || boxes[i / 3][j / 3][index] > 1) {
        return false;
      }
    }
  }
  return true;
}

vector<vector<string>> leetcode_49(vector<string> &strs) {
  map<string, vector<string>> m;
  for (const string &s: strs) {
    string t = s;
    sort(t.begin(), t.end());
    m[t].push_back(s);
  }
  vector<vector<string>> result;
  for (const auto &i: m) {
    result.push_back(i.second);
  }
  return result;
}

vector<vector<int>> leetcode_56(vector<vector<int>> &intervals) {
  if (intervals.empty()) {
    return {};
  }
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> result;
  for (int i = 0; i < intervals.size(); ++i) {
    int l = intervals[i][0];
    int r = intervals[i][1];
    if (result.empty() || result.back()[1] < l) {
      result.push_back({l, r});
    } else {
      result.back()[1] = max(result.back()[1], r);
    }
  }
  return result;
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

string leetcode_71(string path) {
  auto split = [](const string &s, char delim) -> vector<string> {
      vector<string> result;
      string cur;
      for (char ch: s) {
        if (ch == delim) {
          result.push_back(cur);
          cur.clear();
        } else {
          cur += ch;
        }
      }
      result.push_back(cur);
      return result;
  };

  vector<string> names = split(path, '/');
  vector<string> stack;
  for (string &name: names) {
    if (name == "..") {
      if (!stack.empty()) {
        stack.pop_back();
      }
    } else if (!name.empty() && name != ".") {
      stack.push_back(name);
    }
  }
  string result;
  if (stack.empty()) {
    result = "/";
  } else {
    for (string &name: stack) {
      result += "/" + name;
    }
  }
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

void reverseLinkedList(ListNode *head) {
  ListNode *pre = nullptr;
  ListNode *cur = head;

  while (cur != nullptr) {
    ListNode *next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
}

ListNode *leetcode_92(ListNode *head, int left, int right) {
  ListNode *dummyNode = new ListNode(-1);
  dummyNode->next = head;

  ListNode *pre = dummyNode;

  for (int i = 0; i < left - 1; ++i) {
    pre = pre->next;
  }

  ListNode *rightNode = pre;
  for (int i = 0; i < right - left + 1; ++i) {
    rightNode = rightNode->next;
  }
  ListNode *leftNode = pre->next;
  ListNode *curr = rightNode->next;

  pre->next = nullptr;
  rightNode->next = nullptr;

  reverseLinkedList(leftNode);

  pre->next = rightNode;
  leftNode->next = curr;

  return dummyNode->next;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

bool check_bst(TreeNode *node, long long lower, long long upper) {
  if (node == nullptr) {
    return true;
  }
  if (node->val <= lower || node->val >= upper) {
    return false;
  }
  return check_bst(node->left, lower, node->val) && check_bst(node->right, node->val, upper);
}

bool leetcode_98(TreeNode *root) {
  return check_bst(root, LONG_MIN, LONG_MAX);
}

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

bool leetcode_101(TreeNode *root) { return check(root, root); }

int leetcode_104(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  return max(leetcode_104(root->left), leetcode_104(root->right)) + 1;
}

TreeNode *build_tree(const vector<int> &preorder, const vector<int> &inorder, int preorder_left, int preorder_right,
                     int inorder_left, int inorder_right, unordered_map<int, int> index) {
  if (preorder_left > preorder_right) {
    return nullptr;
  }
  int preorder_root = preorder_left;
  int inorder_root = index[preorder[preorder_root]];

  TreeNode *root = new TreeNode(preorder[preorder_root]);
  int size_left_subtree = inorder_root - inorder_left;

  root->left = build_tree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left,
                          inorder_root - 1, index);

  root->right = build_tree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1,
                           inorder_right, index);
  return root;
}

TreeNode *leetcode_105(vector<int> &preorder, vector<int> &inorder) {
  int n = preorder.size();
  unordered_map<int, int> index;
  for (int i = 0; i < n; i++) {
    index[inorder[i]] = i;
  }
  return build_tree(preorder, inorder, 0, n - 1, 0, n - 1, index);
}

TreeNode *helper(vector<int> &nums, int left, int right) {
  if (left > right) {
    return nullptr;
  }
  int mid = (left + right) / 2;
  TreeNode *node = new TreeNode(nums[mid]);
  node->left = helper(nums, left, mid - 1);
  node->right = helper(nums, mid + 1, right);
  return node;
}

TreeNode *leetcode_108(vector<int> &nums) {
  return helper(nums, 0, nums.size() - 1);
}

bool leetcode_112(TreeNode *root, int targetSum) {
  if (root == nullptr) {
    return false;
  }
  if (root->left == nullptr and root->right == nullptr) {
    return targetSum == root->val;
  }
  return leetcode_112(root->left, targetSum - root->val) ||
         leetcode_112(root->right, targetSum - root->val);
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

class leetcode_155 {
public:
    leetcode_155() {
      min_stack.push(INT_MAX);
    }

    void push(int val) {
      x_stack.push(val);
      min_stack.push(min(min_stack.top(), val));
    }

    void pop() {
      x_stack.pop();
      min_stack.pop();
    }

    int top() {
      return x_stack.top();
    }

    int getMin() {
      return min_stack.top();
    }

private:
    stack<int> x_stack;
    stack<int> min_stack;
};

vector<int> leetcode_167(vector<int> &numbers, int target) {
  int i = 0, j = numbers.size() - 1;
  vector<int> result;
  while (i < j) {
    int sum = numbers[i] + numbers[j];
    if (sum > target) {
      j--;
    }
    if (sum < target) {
      i++;
    }
    if (sum == target) {
      result.push_back(i + 1);
      result.push_back(j + 1);
      break;
    }
  }
  return result;
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

int leetcode_209(int target, vector<int> &nums) {
  if (nums.size() == 0) {
    return 0;
  }
  int fast = 0, slow = 0;
  int sum = 0;
  int min_count = INT_MAX;
  while (fast < nums.size()) {
    sum += nums[fast];
    while (sum >= target) {
      min_count = min(min_count, (fast - slow + 1));
      sum -= nums[slow];
      slow++;
    }
    fast++;
    return min_count == INT_MAX ? 0 : min_count;
  }
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
  if (root == NULL)
    return 0;
  return 1 + leetcode_222(root->left) + leetcode_222(root->right);
}

TreeNode *leetcode_226(TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }
  TreeNode *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  leetcode_226(root->left);
  leetcode_226(root->right);
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
// s 1 2 6 24
// e 24 24 12 4
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

int leetcode_128(vector<int> &nums) {
  unordered_set<int> num_set;
  for (const auto i: nums) {
    num_set.insert(i);
  }
  int result = 0;
  for (const auto &i: num_set) {
    if (!num_set.count(i - 1)) {
      int cur = i;
      int curLength = 1;
      while (num_set.count(cur + 1)) {
        curLength++;
        cur++;
      }
      result = max(curLength, result);
    }
  }
  return result;
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

class leetcode_208 {
public:
    leetcode_208() : children(26), isEnd(false) {

    }

    void insert(string word) {
      leetcode_208 *node = this;
      for (char c: word) {
        c -= 'a';
        if (node->children[c] == nullptr) {
          node->children[c] = new leetcode_208();
        }
        node = node->children[c];
      }
      node->isEnd = true;
    }

    bool search(string word) {
      leetcode_208 *node = this->searchPrefix(word);
      return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
      return searchPrefix(prefix) != nullptr;
    }

private:
    leetcode_208 *searchPrefix(string prefix) {
      leetcode_208 *node = this;
      for (char c: prefix) {
        c -= 'a';
        if (node->children[c] == nullptr) {
          return nullptr;
        }
        node = node->children[c];
      }
      return node;
    }

private:
    vector<leetcode_208 *> children;
    bool isEnd;
};

int leetcode_224(string s) {
  stack<int> ops;
  ops.push(1);
  int sign = 1;

  int ret = 0;
  int n = s.length();
  int i = 0;
  while (i < n) {
    if (s[i] == ' ') {
      i++;
    } else if (s[i] == '+') {
      sign = ops.top();
      i++;
    } else if (s[i] == '-') {
      sign = -ops.top();
      i++;
    } else if (s[i] == '(') {
      ops.push(sign);
      i++;
    } else if (s[i] == ')') {
      ops.pop();
      i++;
    } else {
      long num = 0;
      while (i < n && s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + s[i] - '0';
        i++;
      }
      ret += sign * num;
    }
  }
  return ret;
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

void dfs(TreeNode *node, int level, vector<double> &sum, vector<int> count) {
  if (node == nullptr) {
    return;
  }
  if (level < sum.size()) {
    sum[level] += node->val;
    count[level]++;
  } else {
    sum.push_back(1.0 * node->val);
    count.push_back(1);
  }
  dfs(node->left, level + 1, sum, count);
  dfs(node->right, level + 1, sum, count);
}

vector<double> leetcode_637(TreeNode *root) {
  vector<double> sum;
  vector<int> count;
  dfs(root, 0, sum, count);
  vector<double> result;
  for (int i = 0; i < sum.size(); i++) {
    result.push_back(sum[i] / count[i]);
  }
  return result;
}

// main entry point
int main() {
  cout << "Hello, World!" << endl;

  // 58
//  std::string str = "luffy is still joyboy";
//  int c = leetcode_58(str);
//  cout << "count:" << c << endl;

  leetcode_3("abba");

  vector<int> a = {-1, 0, 1, 2, -1, -4};
//  threeSum(a);

  cout << "finished" << endl;
  return 0;
}
