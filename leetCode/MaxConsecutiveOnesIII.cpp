class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int count=0;
        int zeroes=0;
        int max1=0;
        while(j<nums.size()){
            if(nums[j]==1){
                count++;
                max1=max(count,max1);
                j++;
            }
            else{
                if(zeroes<k){
                    zeroes++;
                    count++;
                    max1=max(count,max1);
                    j++;
                }
                else{
                    if(nums[i]==0){
                        zeroes--;
                    }
                    count--;
                    i++;
                }
            }
        }
        return max1;
    }
};
