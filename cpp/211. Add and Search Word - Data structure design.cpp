// Use trie to solve the problem. Write a function mysearch to search
// recursively.
struct TrieNode {
    TrieNode* node[26];
    bool isWord;
    TrieNode(): isWord(false) {
        memset(node, false, sizeof(node));
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
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
    
    bool search(string word) {
        return mysearch(root, word, 0);
    }
    bool mysearch(TrieNode* root, string word, int ind) {
        TrieNode* cur = root;
        if (cur==nullptr) return false;
        if (ind == word.size()) return cur->isWord;
        if (word[ind] == '.') {
            for (int i = 0; i < 26; i++) {
                if (mysearch(cur->node[i], word, ind+1)) return true;
            }
            return false;
        } else {
            int curind = word[ind]-'a';
            return mysearch(cur->node[curind], word, ind+1);
        }
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie.search(word);
    }
private:
    Trie trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */