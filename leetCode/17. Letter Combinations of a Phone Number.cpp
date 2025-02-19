class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        queue<string> q;
        unordered_map<int, string> m;
        char curr = 'a';

        // Populate the digit-to-letters mapping
        for (int i = 2; i <= 9; i++) {
            string temp = "";
            for (int j = 0; j < 3; j++) {
                temp.append(1, curr);
                curr++;
            }
            if (i == 7 || i == 9) {
                temp.append(1, curr);
                curr++;
            }
            m[i] = temp;
        }

        // Edge case: if input is empty
        if (digits.empty()) {
            return res;
        }

        // Initialize queue with first digit's letters
        for (int k = 0; k < m[digits[0] - '0'].size(); k++) {
            q.push(string(1, m[digits[0] - '0'][k]));
        }

        // Process remaining digits
        for (int i = 1; i < digits.size(); i++) {
            int n = q.size();
            for (int j = 0; j < n; j++) {
                string temp = q.front();
                q.pop();
                for (int k = 0; k < m[digits[i] - '0'].size(); k++) {
                    q.push(temp + m[digits[i] - '0'][k]);
                }
            }
        }

        // Transfer queue contents to result vector
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};
