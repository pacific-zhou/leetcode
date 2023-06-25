package main

import "fmt"

func leetcode26(nums []int) int {
	slow, fast := 0, 1
	for fast < len(nums) {
		if nums[slow] != nums[fast] {
			slow++
			nums[slow] = nums[fast]
		}
		fast++
	}
	return slow + 1
}

func leetcode27(nums []int, val int) int {
	var index, resultSzie int
	for _, i := range nums {
		if i != val {
			nums[index] = i
			index++
			resultSzie++
		}
	}
	return resultSzie
}

func leetcode80(nums []int) int {
	if len(nums) <= 2 {
		return len(nums)
	}

	slow, fast := 2, 2
	for fast < len(nums) {
		if nums[fast] != nums[slow-2] {
			nums[slow] = nums[fast]
			slow++
		}
		fast++
	}
	return slow
}

func leetcode88(nums1 []int, m int, nums2 []int, n int) {
	s := m + n - 1
	for m > 0 && n > 0 {
		if nums1[m-1] >= nums2[n-1] {
			nums1[s] = nums1[m-1]
			s--
			m--
		} else {
			nums1[s] = nums2[n-1]
			s--
			n--
		}
	}
	for i := n; i > 0; i-- {
		nums1[s] = nums2[i-1]
		s--
	}
}

func main() {
	fmt.Println("hello world")
}
