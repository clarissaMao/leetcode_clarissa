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
    // Inorder traverse the tree. Serialize every subtree met when doing recursion.
    // Store node for every subtree in a map, and the key is the corresponding serialized
    // string for that subtree. If two subtrees are the same, they would have the same
    // key. Find duplicates from the map by checking the size for value for each (key, value).
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, vector<TreeNode*>> treemap;
        serialize(root, treemap);
        for (auto it = treemap.begin(); it != treemap.end(); it++) {
            if (it->second.size() > 1) res.push_back(it->second[0]);
        }
        return res;
    }
    string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>> &treemap) {
        if (root == nullptr) return "# ";
        string s = to_string(root->val) + " " + serialize(root->left, treemap) + serialize(root->right, treemap);
        treemap[s].push_back(root);
        return s;
    }
};