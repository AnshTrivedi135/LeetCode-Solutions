#include <vector>
#include <string>

class Solution {
private:
    bool isSubsequence(const std::string& word, const std::string& s) {
        int i = 0, j = 0;
        while (i < word.length() && j < s.length()) {
            if (word[i] == s[j]) i++;
            j++;
        }
        return i == word.length();
    }

public:
    std::string findLongestWord(std::string s, std::vector<std::string>& dictionary) {
        std::string result = "";

        for (const std::string& word : dictionary) {
            if (isSubsequence(word, s)) {
                if (word.length() > result.length() || 
                   (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};