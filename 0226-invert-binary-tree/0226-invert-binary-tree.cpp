/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
    
    return root;
}
};


// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {

//         // Base case
//         if (root == NULL) {
//             return NULL;
//         }

//         // Swap left and right children
//         swap(root->left, root->right);

//         // Invert left subtree
//         invertTree(root->left);

//         // Invert right subtree
//         invertTree(root->right);

//         return root;
//     }
// };
