class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.length(); i++) {
            if (!cur->t[word[i]-'a']) {
                cur->t[word[i]-'a'] = new Trie();
            }
            cur = cur->t[word[i]-'a'];
        }
        cur->done = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.length(); i++) {
            if (!cur->t[word[i]-'a']) {
                return false;
            }
            cur = cur->t[word[i]-'a'];
        }
        return cur->done;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (int i = 0; i < prefix.length(); i++) {
            if (!cur->t[prefix[i]-'a']) {
                return false;
            }
            cur = cur->t[prefix[i]-'a'];
        }
        return true;
    }

private:
    Trie* t[26] = {};
    bool done = false;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */