class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid + 1]) {
                end = mid;  // Move towards the peak
            } else {
                start = mid + 1;  // Peak must be on the right side
            }
        }
        return start;  // `start` and `end` converge to the peak element index
    }
};
