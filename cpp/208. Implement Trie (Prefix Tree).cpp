// for every TrieNode, there'll be a bool element to indicate whether this is the last
// char for an inserted word, and also 26 TrieNodes, represent 26 conditions from "a"
// to "z". The difference between search a word and a prefix is that for a word, we
// must also check whether the isWord for last char is true. After check,
// set cur = cur->node[ind].
struct TrieNode {
    TrieNode* node[26];
    bool isWord;
    TrieNode(): isWord(false){
        memset(node, 0, sizeof(node));
    }
};
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; i++) {
            int ind = word[i]-'a';
            if (cur->node[ind] == nullptr) cur->node[ind] = new TrieNode();
            cur = cur->node[ind];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; i++) {
            int ind = word[i]-'a';
            if (cur->node[ind] == nullptr) return false;
            cur = cur->node[ind];
        }
        return (cur->isWord) ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; i++) {
            int ind = prefix[i]-'a';
            if (cur->node[ind] == nullptr) return false;
            cur = cur->node[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */