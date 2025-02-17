class Solution {
public:
    void writeCompressedChar(vector<char>& chars, int& finalSize, char currChar, int currCount) {
        chars[finalSize++] = currChar;  // Store the character
        if (currCount > 1) {
            string countStr = to_string(currCount);
            for (char c : countStr) {
                chars[finalSize++] = c;  // Store each digit of the count
            }
        }
    }

    int compress(vector<char>& chars) {
        int finalSize = 0, currCount = 1, n = chars.size();
        char currChar = chars[0];

        for (int i = 1; i < n; i++) {
            if (chars[i] != currChar) {
                writeCompressedChar(chars, finalSize, currChar, currCount); 
                currCount = 1;
                currChar = chars[i];
            } else {
                currCount++;
            }
        }

        // Process the last character sequence
        writeCompressedChar(chars, finalSize, currChar, currCount);

        return finalSize;
    }
};
