/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    // Use istringstream and ostringstream. istringstream would read in val
    // by spliting with whitespace automatically.cout would stdout to the screen
    // while ostringstream would write to out and using out.str() to output
    // as a string. cin >> val would read from the user input (screen) to val
    // while istringstream would read from istringstream to val.
private:
    void serialize(TreeNode* root, ostringstream& out) {
        if(root == nullptr) {
            out << "# ";
            return;
        }
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }
    
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));