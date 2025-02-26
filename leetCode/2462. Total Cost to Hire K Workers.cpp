class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;

        // Populate the left heap with the first 'candidates' elements
        for (int i = 0; i < candidates; i++) {
            left.push(costs[i]);
        }

        // Determine the starting index for the right heap
        int rightIndex = (n - candidates > candidates) ? n - candidates : candidates;

        // Populate the right heap with the last 'candidates' elements
        for (int i = rightIndex; i < n; i++) {
            right.push(costs[i]);
        }

        long long res = 0;
        int leftIndex = candidates;
        rightIndex--;

        for (int i = 0; i < k; i++) {
            if (right.empty()) {
                res += left.top();
                left.pop();
            } else if (left.empty()) {
                res += right.top();
                right.pop();
            } else if (left.top() <= right.top()) {
                res += left.top();
                left.pop();
                if (leftIndex <= rightIndex) {
                    left.push(costs[leftIndex]);
                    leftIndex++;
                }
            } else {
                res += right.top();
                right.pop();
                if (leftIndex <= rightIndex) {
                    right.push(costs[rightIndex]);
                    rightIndex--;
                }
            }
        }

        return res;
    }
};
