import math
from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def addTwoNumbers(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    head = None
    tail = None
    carry = 0
    while l1 is not None or l2 is not None:
        n1 = n2 = 0
        if l1 is not None:
            n1 = l1.val
        if l2 is not None:
            n2 = l2.val
        sum_val = n1 + n2 + carry
        carry = int(sum_val / 10)
        if head is None:
            head = tail = ListNode(val=sum_val % 10)
        else:
            tail.next = ListNode(val=sum_val % 10)
            tail = tail.next
        if l1 is not None:
            l1 = l1.next
        if l2 is not None:
            l2 = l2.next
    if carry > 0:
        tail.next = ListNode(val=carry)
    return head


def leetcode26(self, nums: List[int]) -> int:
    slow, fast = 0, 1
    while fast < len(nums):
        if nums[fast] != nums[slow]:
            slow += 1
            nums[slow] = nums[fast]
        fast += 1
    return slow + 1


def leetcode27(nums: List[int], val: int) -> int:
    index = 0
    size = 0
    for v in nums:
        if v != val:
            nums[index] = v
            index = index + 1
            size = size + 1
    return size


def leetcode80(self, nums: List[int]) -> int:
    if len(nums) <= 2:
        return len(nums)
    slow, fast = 2, 2
    while fast < len(nums):
        if nums[fast] != nums[slow - 2]:
            nums[slow] = nums[fast]
            slow += 1
        fast += 1
    return slow


def leetcode88(nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    """
    Do not return anything, modify nums1 in-place instead.
    """
    s = m + n - 1
    while m > 0 and n > 0:
        if nums1[m - 1] >= nums2[n - 1]:
            nums1[s] = nums1[m - 1]
            s -= 1
            m -= 1
        else:
            nums1[s] = nums2[n - 1]
            s -= 1
            n -= 1
    while n > 0:
        nums1[s] = nums2[n - 1]
        s -= 1
        n -= 1


def leetcode121(self, prices: List[int]) -> int:
    minPrice, maxProfit = prices[0], 0
    for price in prices:
        if price < minPrice:
            minPrice = price
        elif price - minPrice > maxProfit:
            maxProfit = price - minPrice
    return maxProfit


def leetcode128(self, nums: List[int]) -> int:
    result = 0
    num_set = set(nums)
    for e in num_set:
        if e - 1 not in num_set:
            cur = e
            curLength = 1
            while cur + 1 in num_set:
                cur += 1
                curLength += 1
            result = max(result, curLength)
    return result


class leetcode155:

    def __init__(self):
        self.x_stack = []
        self.min_stack = [math.inf]

    def push(self, val: int) -> None:
        self.x_stack.append(val)
        self.min_stack.append(min(val, self.min_stack[-1]))

    def pop(self) -> None:
        self.x_stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.x_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


def leetcode169(self, nums: List[int]) -> int:
    count, result = 0, 0
    for v in nums:
        if count == 0:
            result = v
        if v == result:
            count += 1
        else:
            count -= 1
    return result


def leetcode189(self, nums: List[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    k %= len(nums)
    if k == 0 or len(nums) == 1:
        return
    i, j = 0, len(nums) - 1
    while i < j:
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1

    i, j = 0, k - 1
    while i < j:
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1

    i, j = k, len(nums) - 1
    while i < j:
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1


if __name__ == '__main__':
    print("ok")
