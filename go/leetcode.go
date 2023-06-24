package main

import "fmt"

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
