
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long result[nums1Size + nums2Size];
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            result[k++] = nums1[i++];
        } else {
            result[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        result[k++] = nums1[i++];
    }
    
    while (j < nums2Size) {
        result[k++] = nums2[j++];
    }

    long long ind = 0;
    double avg = 0;
    if ((nums1Size + nums2Size) % 2 == 0) {
        ind = ((nums1Size + nums2Size)) / 2;
        avg = ((result[ind - 1] + result[ind]) / 2.0);
    } else {
        ind = ((nums1Size + nums2Size)) / 2;
        avg = result[ind];
    }
    return avg;
}