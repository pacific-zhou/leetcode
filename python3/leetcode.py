from typing import List


def leetcode27(nums: List[int], val: int) -> int:
    index = 0
    size = 0
    for v in nums:
        if v != val:
            nums[index] = v
            index = index + 1
            size = size + 1
    return size


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
