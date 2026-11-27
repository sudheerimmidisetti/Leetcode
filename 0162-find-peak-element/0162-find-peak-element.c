int findPeakElement(int* nums, int numsSize) {
    int max=INT_MIN,k=0;
    for(int i=0; i<numsSize; i++) {
        if(max<nums[i]) {
            max=nums[i];
            k=i;
        }
    }
    return k;
}