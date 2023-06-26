package io.printfzhou.leetcode;

/**
 * @author prinfzhou
 */
public class LeetCode {

    public int leetcode26(int[] nums) {
        int slow = 0, fast = 1;
        while (fast < nums.length) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return ++slow;
    }

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

    public int leetcode80(int[] nums) {
        if (nums.length <= 2) {
            return nums.length;
        }
        int slow = 2, fast = 2;
        while (fast < nums.length) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
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

    public int leetcode169(int[] nums) {
        int count = 0, result = 0;
        for (int i : nums) {
            if (count == 0) {
                result = i;
            }
            if (i == result) {
                count++;
            } else {
                count--;
            }
        }
        return result;
    }

    public void leetcode189(int[] nums, int k) {
        k %= nums.length;
        if (nums.length == 1 || k == 0) {
            return;
        }
        reverseArray(nums, 0, nums.length - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, nums.length - 1);
    }

    private void reverseArray(int[] nums, int i, int j) {
        while (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }

    public int leetcode121(int[] prices) {
        int minPrice = Integer.MAX_VALUE, maxProfit = 0;
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
                continue;
            }
            if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        return maxProfit;
    }

    public static void main(String[] args) {

    }
}
