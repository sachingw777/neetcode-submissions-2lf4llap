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

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for(char c : word){
            int i = c - 'a';
            if(!current->children[i]){
                current->children[i] = new TrieNode();
            }
            current = current->children[i];
        }
        current->isTerminal = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

// bool dfs(string &word, int i, TrieNode* node) {
//     if (i == word.size()) return node->word;

//     char c = word[i];

//     if (c == '.') {
//         for (TrieNode* child : node->children) {
//             if (child && dfs(word, i + 1, child))
//                 return true;
//         }
//         return false;
//     }

//     if (!node->children[c - 'a']) return false;

//     return dfs(word, i + 1, node->children[c - 'a']);
// }

    bool dfs(string& word, int i, TrieNode* root){
        if(i == word.size()) return root->isTerminal;

        char c = word[i];
        int index = c - 'a';

        if(c == '.'){
            for(TrieNode* child: root->children){
                if(child && dfs(word, i+1, child)) return true;
            }
            return false;
        }

        if(!root->children[index]) return false;
        return dfs(word, i+1, root->children[index]);
    }
};




