struct Node {
    int key, value, freq;
    Node* prev;
    Node* next;
    Node(int k, int v, int f) : key(k), value(v), freq(f), prev(nullptr), next(nullptr) {}
};

struct FreqList {
    Node* head;
    Node* tail;
    
    FreqList() {
        head = new Node(-1, -1, 0);
        tail = new Node(-1, -1, 0);
        head->next = tail;
        tail->prev = head;
    }

    void add(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    bool empty() {
        return head->next == tail;
    }
};

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, FreqList> freqToList;

public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) return -1;
        Node* node = keyToNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (keyToNode.size() >= capacity) {
            evict();
        }

        Node* node = new Node(key, value, 1);
        keyToNode[key] = node;
        freqToList[1].add(node);
        minFreq = 1;
    }

private:
    void updateFreq(Node* node) {
        int freq = node->freq;
        freqToList[freq].remove(node);
        if (freqToList[freq].empty() && minFreq == freq) minFreq++;

        node->freq++;
        freqToList[node->freq].add(node);
    }

    void evict() {
        Node* node = freqToList[minFreq].tail->prev;
        keyToNode.erase(node->key);
        freqToList[minFreq].remove(node);
        delete node;
    }
};
