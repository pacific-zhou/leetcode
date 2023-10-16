package io.printfzhou.leetcode;

import java.util.Arrays;
import java.util.stream.IntStream;

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
