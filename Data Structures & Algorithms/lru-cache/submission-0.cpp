class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    // Node(int k, int v){
    //     key = k;
    //     val = v;
    //     prev = nullptr;
    //     next = nullptr;
    // }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
        }else{
            if(mp.size() == capacity){
                Node* lru = head->next;
                remove(lru);
                mp.erase(lru->key);
            }

            Node* node = new Node();
            node->key = key;
            node->val = value;
            mp[key] = node;
            insert(node);
        }
    }
};
