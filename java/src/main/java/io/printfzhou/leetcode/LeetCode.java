package io.printfzhou.leetcode;

/**
 * @author prinfzhou
 */
public class LeetCode {

    public int leetcode27(int[] nums, int val) {
        int index = 0, size = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
                size++;
            }
        }
        return size;
    }

    public void leetcode88(int[] num1, int m, int[] num2, int n) {
        int s = m + n - 1;
        while (m > 0 && n > 0) {
            if (num1[m - 1] >= num2[n - 1]) {
                num1[s--] = num1[m-- - 1];
            } else {
                num1[s--] = num2[n-- - 1];
            }
        }
        for (int i = n; i > 0; --i) {
            num1[s--] = num2[i - 1];
        }
    }

    public static void main(String[] args) {

    }
}
