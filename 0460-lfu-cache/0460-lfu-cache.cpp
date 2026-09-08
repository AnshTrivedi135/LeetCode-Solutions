class LFUCache {
private:

    struct Node {
        int key;
        int value;
        int freq;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, list<Node*>> freqList;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void increaseFreq(Node* node) {

        int oldFreq = node->freq;

        freqList[oldFreq].remove(node);

        if (freqList[oldFreq].empty()) {
            freqList.erase(oldFreq);

            if (minFreq == oldFreq) {
                minFreq++;
            }
        }

        node->freq++;

        freqList[node->freq].push_back(node);
    }

    int get(int key) {

        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];

        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0) {
            return;
        }

        // Key already exists
        if (keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            node->value = value;

            increaseFreq(node);

            return;
        }

        // Cache is full
        if (keyNode.size() == capacity) {

            auto& list = freqList[minFreq];

            Node* nodeToRemove = list.front();

            list.pop_front();

            keyNode.erase(nodeToRemove->key);

            delete nodeToRemove;

            if (list.empty()) {
                freqList.erase(minFreq);
            }
        }

        // Insert new node
        Node* newNode = new Node(key, value);

        keyNode[key] = newNode;

        freqList[1].push_back(newNode);

        minFreq = 1;
    }
};