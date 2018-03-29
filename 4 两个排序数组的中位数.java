public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length = nums1.length + nums2.length;
        if (length%2 == 1){
            return recrusive(nums1, nums2, 0, nums1.length-1, 0, nums2.length-1, length/2 + 1);
        } else {
            return (recrusive(nums1, nums2, 0, nums1.length-1, 0, nums2.length-1, length/2)+recrusive(nums1, nums2, 0, nums1.length-1, 0, nums2.length-1, length/2 + 1))/2.0;
        }
    }
    
    public double recrusive(int[] A, int[] B, int i, int i2, int j, int j2, int k) {
        int m = i2-i+1;
        int n = j2-j+1;
        if (m > n) return recrusive(B, A, j, j2, i, i2, k);
        if (m == 0) {
            return B[j+k-1];
        }
        if (k == 1) {
            return Math.min(A[i], B[j]);
        }
        int posA = Math.min(k/2, m);
        int posB = k-posA;
        if(A[i+posA-1] == B[j+posB-1]) {
            return A[i+posA-1];
        } else if (A[i+posA-1] < B[j+posB-1]) {
            return recrusive(A, B, i+posA, i2, j, j+posB-1, k-posA);
        } else {
            return recrusive(A, B, i, i+posA-1, j+posB, j2, k-posB);
        }
    }
}
