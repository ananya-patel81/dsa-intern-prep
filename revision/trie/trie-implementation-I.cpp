class Node{
    Node* links[26] = {nullptr};
    bool fl = false;
  public:
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    
    void putKey(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    Node* getKey(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        fl = true;
    }
    bool isEnd(){
        return fl;
    }
};

class Trie {
  private:
    Node* root;
  public:

    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->putKey(ch, new Node());
            }
            node= node->getKey(ch);
        }
        node->setEnd();
    }

    bool search(string &word) {
        // search word in the Trie
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->getKey(ch);
        }
        return node->isEnd();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->getKey(ch);
        }
        
        return true;
    }
};
