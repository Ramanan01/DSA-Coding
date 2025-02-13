class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        int curr=0;
        for(int i=0;i<n;i++){
            left[i]=curr;
            if(nums[i]==1){
                curr++;
            }
            else{
                curr=0;
            }
        }

        curr=0;
        int res=0;

        for(int i=n-1;i>=0;i--){
            res=max(left[i]+curr, res);
            if(nums[i]==1){
                curr++;
            }
            else{
                curr=0;
            }
        }
        return res;
    }
};
