class Node{
    Node* links[26]={nullptr};
   public:
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
        fl=true;
    }
};

class Trie{
    Node* root;
   public:
    Trie(){
        root = new Node();
    }
    
    void insert(string& word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->putKey(ch, new Node());
            }
            node = node->getKey(ch);
        }
        
        node->setEnd();
    }
    
    bool checkValidWord(string& word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node=node->getKey(ch);
            if(node->fl==false) return false;
        }
        
        return true;
    }
};



class Solution {
   public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for(string word : words){
            trie.insert(word);
        }
        string longest="";
        for(string word : words){
            if(trie.checkValidWord(word)){
                if(word.length()>longest.length()){
                    longest = word;
                }
                else if(word.length()==longest.length() && word < longest){
                    longest = word;
                }
            }
        }
        return longest;
    }
};
