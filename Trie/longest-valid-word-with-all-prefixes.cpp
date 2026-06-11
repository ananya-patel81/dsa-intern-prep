struct Node{
    Node* links[26]={nullptr};
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    void endWord(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root= new Node();
        
    }
    
    void insert(string word){
        Node* node=root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node);
            }
            node=node->get(ch);
        }
        
        node->endWord();
    }
    
    bool checkPrefixExist(string word){
        bool fl=true;
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch)) return false;
            node=node->get(ch);
            if(node->flag==false) return false;
        }
        return true;
        
    }
};


class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie trie;
        for(auto &it : words){
            trie.insert(it);
        }
        string longest="";
        for(auto &it : words){
            if(trie.checkPrefixExist(it)){
                if(it.length()>longest.length()){
                    longest=it;
                }
                else if(it.length() == longest.length() && it<longest){
                    longest=it;
                }
                
            }
        }
        
        return longest;
        
        
        
    }
};
