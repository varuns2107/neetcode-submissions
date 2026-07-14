class Node {
public:
    int key;
    int data;
    Node* next;
    Node* prev;

    Node(int key_, int val) {
        key = key_;
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity_) {
        capacity = capacity_;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* node){
        Node* front = node->next;
        Node* back = node->prev;
        back->next = front;
        front->prev = back;
    }

    void insert(Node* node) {
        Node* front = head->next;
        head->next = node;
        node->next = front;
        node->prev = head;
        front->prev =node;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* newnode = mpp[key];
        deletenode(newnode);
        insert(newnode);
        return newnode->data;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* newnode = mpp[key];
            newnode->data = value;
            deletenode(newnode);
            insert(newnode);
        }
        else {
            if(mpp.size() == capacity) {
                Node* newnode = tail->prev;
                mpp.erase(newnode->key);
                deletenode(newnode);
                delete newnode;
            }
            Node* newnode = new Node(key, value);
            mpp[key] = newnode;
            insert(newnode);
        }
    }
};
