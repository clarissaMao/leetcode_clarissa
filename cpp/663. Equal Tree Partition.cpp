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
    // Use recursion to calculate the sum for every subtree and use an unordered map to
    // record the number of subtrees whose sum equals to the key. corner case: if the sum
    // for the whole tree equals to 0, check whether it has at least two subtrees equal to 0.
    // If sum_all is an even number and there exists a subtree whose sum is sum_all/2, return true.
    // The advantage of using the sum for the subtreeas the key but not the TreeNode is we don't
    // need to traverse the map to find whether there's a tree whose sum is sum_all/2.
    int sumTree(TreeNode* root, unordered_map<int, int>& treesum) {
        if (root==nullptr) return 0;
        int sum =sumTree(root->left, treesum) + sumTree(root->right, treesum) + root->val;
        treesum[sum]++;
        return sum;
    }
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> treesum;
        int sum_all = sumTree(root, treesum);
        if (sum_all == 0) return treesum[0] > 1;
        return sum_all % 2 == 0 && treesum[sum_all/2] > 0;
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
    // Use recursion to calculate the sum for every subtree and record in an unordered map.
    // If sum for the whole tree is an odd number then return false. corner case:[0], when we
    // check whether a subtree is 1/2*sum of the whole tree, we need to check whether it's the
    // root or not.
    int sumTree(TreeNode* root, unordered_map<TreeNode*, int>& treesum) {
        if (root==nullptr) return 0;
        treesum[root]=sumTree(root->left, treesum) + sumTree(root->right, treesum) + root->val;
        return treesum[root];
    }
    bool checkEqualTree(TreeNode* root) {
        unordered_map<TreeNode*, int> treesum;
        sumTree(root, treesum);
        if (abs(treesum[root]) % 2 == 1) return false;
        for (auto ele:treesum) {
            if (ele.second == treesum[root] / 2 && ele.first!=root) return true;
        }
        return false;
    }
};