void merge(int *A, int l, int m, int h)
{
	int i=l,j=m+1,k=0;
	int result[h-l+1];
	while(i<=m && j<=h)
	{
		if(A[i]<=A[j])
		{
			result[k++]=A[i++];
		}
		else
		{
			result[k++]=A[j++];
		}
	}
	while(i<=m)
	{
		result[k++]=A[i++];
	}
	while(j<=h)
	{
		result[k++]=A[j++];
	}
	k=0;
	for(i=l;i<=h;i++)
	{
		A[i]=result[k++];
	}
}
void merge_sort(int *A, int l, int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
		merge_sort(A, l, m);
		merge_sort(A, m+1, h);
		merge(A, l, m, h);
	}
}
int findKthLargest(int* nums, int numsSize, int k) {
    merge_sort(nums, 0, numsSize - 1);
    return nums[numsSize - k];
}