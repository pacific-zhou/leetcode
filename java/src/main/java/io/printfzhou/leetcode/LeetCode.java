package io.printfzhou.leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

/**
 * @author prinfzhou
 */
public class LeetCode {

    public void leetcode_88_1(int[] nums1, int m, int[] nums2, int n) {
        int i = m + n;
        while (m > 0 && n > 0) {
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

    public void leetcode_88_2(int[] nums1, int m, int[] nums2, int n) {
        if (n >= 0) {
            System.arraycopy(nums2, 0, nums1, m, n);
        }
        Arrays.sort(nums1);
    }

    public int leetcode_128(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        int result = 0;
        for (int num : numSet) {
            if (!numSet.contains(num - 1)) {
                int cur = num;
                int curLength = 1;
                while (numSet.contains(cur + 1)) {
                    cur++;
                    curLength++;
                }
                result = Math.max(result, curLength);
            }
        }
        return result;
    }

    public static class leetcode_155 {

        public leetcode_155() {
            xStack = new Stack<>();
            minStack = new Stack<>();
            minStack.push(Integer.MAX_VALUE);
        }

        public void push(int val) {
            xStack.push(val);
            minStack.push(Math.min(val, minStack.peek()));
        }

        public void pop() {
            xStack.pop();
            minStack.pop();
        }

        public int top() {
            return xStack.peek();
        }

        public int getMin() {
            return minStack.peek();
        }

        private final Stack<Integer> xStack;
        private final Stack<Integer> minStack;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        LeetCode leetcode = new LeetCode();
//        leetcode.leetcode_88_1(nums1, 3, nums2, 3);
//        System.out.println(Arrays.toString(nums1));
        leetcode.leetcode_88_2(nums1, 3, nums2, 3);
        System.out.println(Arrays.toString(nums1));

    }
}
