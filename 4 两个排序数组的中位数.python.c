
class Solution(object):
    def findMedianSortedArrays(self, a, b):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        c = a+b
        c.sort()
        m = len(c) / 2
        mm = len(c) % 2
        if mm > 0 :
            return c[m]
        return (c[m-1]+c[m])/2.# + (c[m-1]+c[m])%2
