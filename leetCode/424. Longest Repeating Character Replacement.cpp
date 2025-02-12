class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int left=0, right=0, res=0, maxCountInAWindow=0;
        while(right < s.size()){
            m[s[right]]++;
            maxCountInAWindow = max(maxCountInAWindow, m[s[right]]);
            if((right-left+1) - maxCountInAWindow > k){
                m[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};
