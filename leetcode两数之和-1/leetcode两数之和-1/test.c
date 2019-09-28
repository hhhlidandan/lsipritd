//C
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i = 0;
	int j = 0;
	int *ret = (int *)malloc(sizeof(int)* 2);
	for (; i <= numsSize - 1; i++)
	{
		for (j = i + 1; j<numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	return ret;
}

