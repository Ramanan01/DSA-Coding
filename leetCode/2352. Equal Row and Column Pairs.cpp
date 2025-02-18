class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> hashmap;
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        // Store frequency of each row in the hashmap
        for (int i = 0; i < row; i++) {
            hashmap[grid[i]]++;
        }

        // Compare columns with stored rows
        for (int j = 0; j < col; j++) {
            vector<int> curr;
            for (int i = 0; i < row; i++) {
                curr.push_back(grid[i][j]);
            }
            ans += hashmap[curr];  // Count occurrences
        }

        return ans;
    }
};
