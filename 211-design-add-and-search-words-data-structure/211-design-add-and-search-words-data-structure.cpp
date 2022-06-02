class Trie {
public:
    bool done;
    Trie* dict[26];
    Trie() {
        done = false;
        memset(dict, 0, sizeof(dict));
    }
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie* cur = node;
        for (char c : word) {
            if (!cur -> dict[c - 'a']) {
                cur -> dict[c - 'a'] = new Trie();
            }
            cur = cur -> dict[c - 'a'];
        }
        cur -> done = true;
    }
    
    bool search(string word) {
        return searchH(word, node);
    }
private:
    Trie* node = new Trie();
    bool searchH(string word, Trie* cur) {
        bool ret = false;
        for (int j = 0; j < word.length(); j++) {
            if (word[j] == '.') {
                for (int i = 0; i < 26; i++) {
                    if (cur->dict[i] && searchH(word.substr(j+1,word.length()),cur->dict[i])) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!cur->dict[word[j]-'a']) {
                    return false;
                }
                cur = cur->dict[word[j]-'a'];
            }
        }
        return cur->done;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */