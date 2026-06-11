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
        
        Node* root=new Node();
        int cnt=0;
        for(int i=0;i<s.length();i++){
            Node* node=root;
            for(int j=i;j<s.length();j++){
                char ch=s[j];
                if(!(node->containsKey(ch))){
                    cnt++;
                    node->put(ch, new Node());
                }
                node=node->get(ch);
                
            }
        
            
        }
        
        return cnt;
        
        
    }
};
