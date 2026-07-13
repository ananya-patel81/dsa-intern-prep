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

class Solution {
  public:
    int countSubs(string& s) {
        Node* root = new Node();
        int n = s.length();
        int count=0;
        for(int i =0 ; i<n;i++){
            Node* node= root;
            for(int j=i;j<n;j++){
                if(!node->containsKey(s[j])){
                    count++; //IMP OBSERVATION 
                    node->put(s[j],new Node());
                }
                node=node->get(s[j]);
            }
            node->endWord();
        }
        
        return count;
        
    }
};
