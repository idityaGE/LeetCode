class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delNext = delNode->next;
        Node* delPrev = delNode->prev;
        delNext->prev = delPrev;
        delPrev->next = delNext;
    }

    int get(int key_) {
        if (mp.find(key_) != mp.end()) {
            Node* temp = mp[key_];
            int res = temp->val;
            mp.erase(key_);
            deleteNode(temp);
            addNode(temp);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (mp.find(key_) != mp.end()) {
            Node* existingNode = mp[key_];
            mp.erase(key_);
            deleteNode(existingNode);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key_, value));
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */