struct Node{
    int key,value,cnt;
    Node* next;
    Node* prev;

    Node(int _key, int _val){
        key = _key;
        value=_val;
        cnt=1;
    }

};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail ->prev = head;
        size=0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
        size++;
    }

    void removeNode(Node* delnode){
        Node* prevNode = delnode->prev;
        Node* nextnode= delnode->next;
        prevNode->next = nextnode;
        nextnode->prev = prevNode;
        size--;
    }
};

class LFUCache {
private:
    map<int,Node*> keyNode;
    map<int,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int cursize;
public:
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        minFreq=0;
        cursize=0;
        
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        if (freqListMap.find(1) == freqListMap.end()) {
            freqListMap[1] = new List();
        }
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[minFreq]->size==0){
            minFreq++;
        }
        List* nextHighFreqList = new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHighFreqList = freqListMap[node->cnt+1];
        }
        node->cnt += 1;
        nextHighFreqList->addFront(node);
        freqListMap[node->cnt]=nextHighFreqList;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0){
            return;
        }
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{
            if(cursize==maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minFreq=1;
            List* listfreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listfreq = freqListMap[minFreq];

            }
            Node* node = new Node(key,value);
            listfreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
