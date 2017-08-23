/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Use recursion to compare.
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return t==nullptr;
        if (isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSame(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr || s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Serialize the t tree. When a treenode is nullptr, use "#" to represent.
    // When serialize the s tree, try to compare the subtrees in s with t tree in
    // recursion. This method is quite slow.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "# ";
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }
    string serializeTree(TreeNode* root, string target, bool& flag) {
        // when flag equals to true, end the recusion and other branches immediately.
        if (flag == true) return "";
        if (root == nullptr) return "# ";
        string res = to_string(root->val) + " " + serializeTree(root->left, target, flag)
        + serializeTree(root->right, target, flag);
        if (res == target) flag = true;
        return res;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string ttree = serialize(t);
        bool flag = false;
        serializeTree(s, ttree, flag);
        return flag;
        
    }
};