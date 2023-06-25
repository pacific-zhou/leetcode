from typing import List


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


if __name__ == '__main__':
    print("ok")
