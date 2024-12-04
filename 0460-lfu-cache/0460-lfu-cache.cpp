class LFUCache {
public:
    class Node {
    public:
        int key;
        int val;
        int cnt;
        Node* prev = NULL;
        Node* next = NULL;
        Node(int key_, int val_) {
            key = key_;
            val = val_;
            cnt = 1;
        }
    };
    class LinkedList {
    public:
        int size;
        Node* head;
        Node* tail;
        LinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void add(Node* newNode) {
            Node* temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
            size++;
        }
        void delet(Node* del) {
            Node* delprev = del->prev;
            Node* delnext = del->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };
    map<int, Node*> mppKey;
    map<int, LinkedList*> mppList;
    int cap;
    int mini;
    int curr; 

    LFUCache(int capacity) {
        cap = capacity;
        mini = 0;
        curr = 0;
    }
    void update(Node* node) {
        mppKey.erase(node->key);
        mppList[node->cnt]->delet(node);
        if (node->cnt == mini && mppList[node->cnt]->size == 0) {
            mini++;
        }
        LinkedList* neeHighList = new LinkedList();
        if (mppList.find(node->cnt + 1) != mppList.end()) {
            neeHighList = mppList[node->cnt + 1];
        }
        node->cnt++;
        neeHighList->add(node);
        mppList[node->cnt] = neeHighList;
        mppKey[node->key] = node;
    }
    int get(int key) {
        if (mppKey.find(key) != mppKey.end()) {
            Node* node = mppKey[key];
            int res = node->val;
            update(node);
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;
        if (mppKey.find(key) != mppKey.end()) {
            Node* node = mppKey[key];
            node->val = value;
            update(node);
        } else {
            if (curr == cap) {
                LinkedList* minifreq = mppList[mini];
                mppKey.erase(minifreq->tail->prev->key);
                mppList[mini]->delet(minifreq->tail->prev);
                curr--;
            }
            curr++;
            mini = 1;
            LinkedList* freq = new LinkedList();
            if (mppList.find(mini) != mppList.end()) {
                freq = mppList[mini];
            }
            Node* newNode = new Node(key, value);
            freq->add(newNode);
            mppKey[key] = newNode;
            mppList[mini] = freq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */