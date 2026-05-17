inline int max(int a, int b) {
    return (a > b) ? a : b;
}
inline int min(int a, int b) {
    return (a < b) ? a : b;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size;
    int n = nums2Size;
    int* arrsmall = nums1;
    int* arrBig = nums2;
    if (nums1Size >nums2Size){
        m = nums2Size;
        n = nums1Size;
        arrsmall = nums2;
        arrBig = nums1;
    }
    int low = 0;
    int high = m;
    while(low <= high){
        int i = low + (high - low) / 2;
        int j = (m + n + 1) / 2 - i;

        int maxLeft1 = (i == 0) ? INT_MIN : arrsmall[i - 1];
        int minRight1 = (i == m) ? INT_MAX : arrsmall[i];

        int maxLeft2 = (j == 0) ? INT_MIN : arrBig[j - 1];
        int minRight2 = (j == n) ? INT_MAX : arrBig[j];

        if (maxLeft1 > minRight2) {
            high = i - 1;
        }else if (maxLeft2 > minRight1) {
            low = i + 1;
        }else if ((m + n) % 2 == 0) {
                return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
        }else {
                return (double)max(maxLeft1, maxLeft2);
        }
    }
    return 0.0;
}