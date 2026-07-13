#include<bits/stdc++.h>
using namespace std;

class Node{
    Node* links[26]={nullptr};
public:
    int cntEndsWith=0;
    int cntPrefix=0;
    
public:
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    
    Node* getKey(char ch){
        return links[ch-'a'];
    }
    
    void putKey(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    void increaseEnd(){
        cntEndsWith++;
    }
    
    void increasePrefix(){
        cntPrefix++;
    }
    
    void deleteEnd(){
        cntEndsWith--;
    }
    
    void reducePrefix(){
        cntPrefix--;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->putKey(ch, new Node());
            }
            node= node->getKey(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    
    int countWordEquals(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return 0;
            }
            node = node->getKey(ch);
            
        }
        return node->cntEndsWith;
    }
    
    int countStartsWith(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return 0;
            }
            node = node->getKey(ch);
            
        }
        return node->cntPrefix;
        
    }
    
    void erase(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return;
            }
            node = node->getKey(ch);
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
    cout << trie.countWordEquals("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countStartsWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countStartsWith("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countStartsWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Starting With 'app': ";
    cout << trie.countStartsWith("app") << endl;
    return 0;
}
