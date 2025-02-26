bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first && a.second > b.second) {
        return true;
    }
    return false;
}

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> q;
        long long res = 0;
        vector<pair<int, int>> p;

        for (int i = 0; i < n; i++) {
            p.emplace_back(nums2[i], nums1[i]);
        }

        sort(p.begin(), p.end(), comp);

        long long currSum = 0;
        for (int i = 0; i < k - 1; i++) {
            q.push(p[i].second);
            currSum += p[i].second;
        }

        for (int i = k - 1; i < n; i++) {
            q.push(p[i].second);
            currSum += p[i].second;
            res = max(res, currSum * p[i].first);
            currSum -= q.top();
            q.pop();
        }

        return res;
    }
};
