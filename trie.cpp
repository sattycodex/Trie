#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* ch[26];
    bool isEnd=false;
    int prefix=0;
    
    void setEnd(){
        this->isEnd=true;
    }
    bool getEnd(){
        return this->isEnd;
    }
    
    void increasePrefix(char ch){
        this->prefix++;
    }
    int getPrefix(){
        return this->prefix;
    }
    
    bool contains(char ch){
        return this->ch[ch-'a']!=NULL;
    }
    void put(char ch){
        this->ch[ch-'a']=new Node();
    }
    Node* get(char ch){
        return this->ch[ch-'a'];
    }
};
class Trie{
    private:
    Node* root;
    public:
     Trie(){
         root=new Node();
     }
     void insert(string str){
         Node* temp=root;
         for(char ch:str){
             if(!temp->contains(ch))temp->put(ch);
             temp=temp->get(ch);
             temp->increasePrefix(ch);
         }
         temp->setEnd();
     }
     
     bool containstring(string str){
         Node* temp=root;
         for(char ch:str){
             if(!temp->contains(ch))return false;
             temp=temp->get(ch);
         }
         return temp->getEnd();
     }
     
     int getPrefix(string str){
         Node* temp=root;
         for(char ch:str){
             if(!temp->contains(ch))return 0;
             temp=temp->get(ch);
         }
         return temp->getPrefix();
     }
};




int main()
{
    Trie* trie=new Trie();
    trie->insert("hell");
    trie->insert("hel");
    trie->insert("hello");
    cout<<trie->containstring("hell")<<endl;
    cout<<trie->getPrefix("he");

    return 0;
}
