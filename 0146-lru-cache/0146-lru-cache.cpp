class LRUCache {
public:
    struct Node {
        int key, value;

        Node *prev, *next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;

            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, Node*> mp;

    Node *head, *tail;

    int capacity = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = nullptr;
        tail = nullptr;
    }

    void deleteNode(Node* node) {
        if (node->prev == nullptr)
            head = node->next;
        else
            node->prev->next = node->next;

        if (node->next == nullptr)
            tail = node->prev;
        else
            node->next->prev = node->prev;
    }

    void insertNode(Node* node) {
        node->prev = nullptr;
        node->next = head;

        if (head != nullptr)
            head->prev = node;

        head = node;

        if (tail == nullptr)
            tail = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        insertNode(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            mp[key]->value = value;

            deleteNode(node);
            insertNode(node);

            return;
        }

        if (mp.size() == capacity) {
            Node* node = tail;

            mp.erase(node->key);

            deleteNode(node);
            delete (node);
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;

        insertNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */