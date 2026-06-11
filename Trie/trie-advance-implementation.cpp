#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26] = {nullptr};
    int cntEndwith=0;
    int cntPrefix=0;
    
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    void increaseEnd(){
        cntEndwith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndwith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
};

class Trie{
private:
    Node* root;
    

public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node=root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return 0;
            }
            node=node->get(ch);
        }
        return node->cntEndwith;
    }

    int countWordsStartingWith(string prefix){
        Node* node = root;
        for(char ch : prefix){
            if(!node->containsKey(ch)){
                return 0;
            }
            node=node->get(ch);
        }
        
        return node->cntPrefix;
    }

    void erase(string word){
        Node* node=root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return;
            }
            node=node->get(ch);
            node->reducePrefix();
            
        }
        
        node->deleteEnd();
    }
};








int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("apple");
    cout << "Inserting strings 'apple' twice into Trie" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    return 0;
}
