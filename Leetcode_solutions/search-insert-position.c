int searchInsert(int* nums, int numsSize, int target) {
    int begin = 0, end = numsSize;
    while(true) {
        if (begin >= end) return begin;
        int pivot = (begin + end) / 2;
        if (nums[pivot] >= target) {
            if (pivot == 0 || nums[pivot - 1] < target) {
                return pivot;
            }
            end = end - (end - begin) / 2;
        } else {
            begin = begin + (end - begin) / 2 + 1;
        }
    }
    return 0;
}
