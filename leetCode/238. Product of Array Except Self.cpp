class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int productLeft = 1, productRight = 1;
        vector<int> answer(n, 1);

        for (int i = 0; i < n; i++) {
            answer[i] *= productLeft;
            productLeft *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= productRight;
            productRight *= nums[i];
        }

        return answer;
    }
};
