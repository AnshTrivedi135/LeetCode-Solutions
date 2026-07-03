class Solution {
    struct TrieNode {
        TrieNode* child[2];
        TrieNode() {
            child[0] = child[1] = nullptr;
        }
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for (int num : nums) {
            TrieNode* node = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!node->child[bit])
                    node->child[bit] = new TrieNode();
                node = node->child[bit];
            }
        }

        int ans = 0;

        for (int num : nums) {
            TrieNode* node = root;
            int cur = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (node->child[1 - bit]) {
                    cur |= (1 << i);
                    node = node->child[1 - bit];
                } else {
                    node = node->child[bit];
                }
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};