class Solution {
private:
    void dfs(TreeNode* node, string currentPath, vector<string>& result) {
        if (!node) return;

        currentPath += to_string(node->val);

        if (!node->left && !node->right) {
            result.push_back(currentPath);
            return;
        }

        currentPath += "->";

        if (node->left) {
            dfs(node->left, currentPath, result);
        }
        if (node->right) {
            dfs(node->right, currentPath, result);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) {
            dfs(root, "", result);
        }
        return result;
    }
};