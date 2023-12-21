package main

import (
	"fmt"
	"math"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func leetcode2(l1 *ListNode, l2 *ListNode) *ListNode {
	var head, tail *ListNode
	carry := 0
	for l1 != nil || l2 != nil {
		n1, n2 := 0, 0
		if l1 != nil {
			n1 = l1.Val
		}
		if l2 != nil {
			n2 = l2.Val
		}
		sum := n1 + n2 + carry
		if head == nil {
			head = &ListNode{Val: sum % 10}
			tail = head
		} else {
			tail.Next = &ListNode{Val: sum % 10}
			tail = tail.Next
		}
		carry = sum / 10
		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
	}
	if carry > 0 {
		tail.Next = &ListNode{
			Val: carry,
		}
	}
	return head
}

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

func leetcode128(nums []int) int {
	numSet := map[int]bool{}
	for _, num := range nums {
		numSet[num] = true
	}
	result := 0
	for i := range numSet {
		if !numSet[i-1] {
			cur := i
			curLength := 1
			for numSet[cur+1] {
				cur++
				curLength++
			}
			if curLength > result {
				result = curLength
			}
		}
	}
	return result
}

type leetcode155 struct {
	stack    []int
	minStack []int
}

func Constructor() leetcode155 {
	return leetcode155{
		stack:    []int{},
		minStack: []int{math.MaxInt64},
	}
}

func (this *leetcode155) Push(val int) {
	this.stack = append(this.stack, val)
	this.minStack = append(this.minStack, min(val, this.minStack[len(this.minStack)-1]))
}

func (this *leetcode155) Pop() {
	this.stack = this.stack[:len(this.stack)-1]
	this.minStack = this.minStack[:len(this.minStack)-1]
}

func (this *leetcode155) Top() int {
	return this.stack[len(this.stack)-1]
}

func (this *leetcode155) GetMin() int {
	return this.minStack[len(this.minStack)-1]
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
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
