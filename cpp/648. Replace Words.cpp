// Use trie. Insert every word from the dict to trie and for each word from the
// sentence, try to search the shortest prefix from the trie.
// Trie trie; trie.insert(word); don't need to free space at the end.
// Trie* trie = new Trie(); trie->insert(word);  need to delete it after finishing.
struct TrieNode {
    TrieNode* node[26];
    bool isWord;
    TrieNode(): isWord(false) {
        memset(node,0, sizeof(node));
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
    
    int findPrefix(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; i++) {
            int ind = word[i]-'a';
            if (cur->node[ind]==nullptr) return -1;
            cur = cur->node[ind];
            if (cur->isWord == true) return i;
        }
        return -1;
    }
};

class Solution {
public:
    vector<string> split(string s, char delim) {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            if (item.size() > 0) res.push_back(item);
        }
        return res;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        int n = dict.size();
        string res;
        Trie trie;
        for (int i = 0; i < n; i++) {
            trie.insert(dict[i]);
        }
        vector<string> words = split(sentence, ' ');
        int m = words.size();
        for (int i = 0; i < m; i++) {
            int ind = trie.findPrefix(words[i]);
            if (ind != -1) words[i] = words[i].substr(0, ind+1);
            res += words[i] + " ";
        }
        res = res.substr(0, res.size()-1);
        return res;
    }
};