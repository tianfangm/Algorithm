class Trie {
private:
    vector<Trie*>children;
    bool isEnd;

    Trie* searchPrefix(string word)
    {
        Trie*node = this;
        for(auto ch:word)
        {
            ch = ch - 'a';
            if(!node->children[ch])
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie():children(26),isEnd(false) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie*node = this;
        for(auto ch:word)
        {
            ch = ch -'a';
            if(!node->children[ch])
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = searchPrefix(word);
        return node!=nullptr&&node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = searchPrefix(prefix);
        return node!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
