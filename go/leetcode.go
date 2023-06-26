package main

import (
	"fmt"
	"math"
)

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

func leetcode121(prices []int) int {
	minPrice, maxProfit := math.MaxInt, 0
	for _, price := range prices {
		if price < minPrice {
			minPrice = price
		} else if price-minPrice > maxProfit {
			maxProfit = price - minPrice
		}
	}
	return maxProfit
}

func leetcode169(nums []int) int {
	count, result := 0, 0
	for _, v := range nums {
		if count == 0 {
			result = v
		}
		if v == result {
			count++
		} else {
			count--
		}
	}
	return result
}

func leetcode189(nums []int, k int) {
	k %= len(nums)
	if k == 0 || len(nums) == 1 {
		return
	}
	reverseArray(nums, 0, len(nums)-1)
	reverseArray(nums, 0, k-1)
	reverseArray(nums, k, len(nums)-1)
}

func reverseArray(nums []int, i int, j int) {
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
}

func main() {
	fmt.Println("hello world")
}
