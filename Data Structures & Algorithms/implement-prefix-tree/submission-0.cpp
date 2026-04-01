class TrieNode{
    public:
        TrieNode* children[26];
        bool isTerminal;
    
    TrieNode(){
        isTerminal = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(char c: word){
            int i = c - 'a';
            if(!current->children[i]){
                current->children[i] = new TrieNode();
            }

            current = current->children[i];
        }
        current->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for(char c: word){
            int i = c - 'a';
            if(!current->children[i]) return false;
            current = current->children[i];
        }

        return current->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for(char c: prefix){
            int i = c - 'a';
            if(!current->children[i]) return false;
            current = current->children[i];
        }
        return true;
    }
};
