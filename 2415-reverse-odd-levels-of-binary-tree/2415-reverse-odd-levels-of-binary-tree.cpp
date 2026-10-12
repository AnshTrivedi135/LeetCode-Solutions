
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }

private:
    void dfs(TreeNode* left, TreeNode* right, bool odd) {
        if (left == nullptr || right == nullptr)
            return;

        if (odd) {
            swap(left->val, right->val);
        }

        dfs(left->left, right->right, !odd);
        dfs(left->right, right->left, !odd);
    }
};
