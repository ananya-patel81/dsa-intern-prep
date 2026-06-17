class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

    
        Node(int key,int val){
            this->key=key;
            this->val=val;

            next=nullptr;
            prev=nullptr;
        }
    

        
    };
    void addNode(Node* node,Node* head){
            
        Node* after=head->next;
        if(head) head->next=node;
        if(node) node->prev=head;
        if(after) after->prev=node;
        if(node) node->next=after;

    }

    void delNode(Node* node){
        Node* before=node->prev;
        Node* after=node->next;
        if(before) before->next=after;
        if(after) after->prev=before;
            
    }

    int cap;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }

    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node=mp[key];
        delNode(node);
        addNode(node,head);
        
        mp[key]=head->next;
        return node->val;

        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* currnode=mp[key];
            delNode(currnode);
            addNode(currnode,head);
            currnode->val=value;
            mp[key]=head->next;
        }
        else{ //matlab naya key hai 
            if(mp.size()==cap){
                Node* oldnode=tail->prev;

                mp.erase(oldnode->key);
                delNode(oldnode);
                Node* newnode= new Node(key,value);
                mp[key]=newnode;
                addNode(newnode,head);

            }
            else{
                Node* newnode= new Node(key,value);
                mp[key]=newnode;
                addNode(newnode,head);
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
