class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base Case: Agar root NULL hai ya value mil gayi
        if (root == nullptr || root->val == val) { 
            return root; 
        }
        
        // BST Property: Agar val choti hai toh left mein jao, nahi toh right mein
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        
        else return searchBST(root->right, val);
    }
};