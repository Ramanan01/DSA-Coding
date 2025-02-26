class Solution {
public:
    int binarySearch(vector<int>& potions, long long num1, long long success) {
        int start = 0, end = potions.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (num1 * potions[mid] >= success) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return potions.size() - start;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> res;

        for (int i = 0; i < m; i++) {
            res.push_back(binarySearch(potions, static_cast<long long>(spells[i]), success));
        }

        return res;
    }
};
