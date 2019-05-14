#include <bits/stdc++.h>

using namespace std;

int modularHash(int key, int size){
    return key%size;
}

struct hashNode{
    int key, value;
    hashNode *next;

    hashNode(int key, int value){
        this->key = key;
        this->value = value;
    }

    int getHash(int size){
        return modularHash(key, size);
    }
};

struct hashList{
    hashNode* head;

    hashList(){
        head = new hashNode(0,0);
    }

    void put(hashNode *node){
        hashNode* temp = head->next;
        head->next = node;
        head->next->next = temp;
    }

    hashNode* exists(int key){
        hashNode *temp = head->next;
        while(temp != nullptr){
            if(temp->key == key) return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void remove(int key){
        hashNode *temp = head;
        hashNode *temp2 = head->next;
        while(temp2 != nullptr){
            if(temp2->key == key){
                temp->next = temp2->next;
                delete temp2;
                return;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    }

    void print(){
        hashNode *temp = head->next;
        while(temp != nullptr){
            cout<<temp->key<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

struct HashTable{
    int size;
    hashList **table;
    HashTable(int size){
        this->size = size;
        table = new hashList*[size];
        for(int i = 0; i < size; i++){
            table[i] = new hashList();
        }
    }
    
    void insert(hashNode *n){
        
        table[n->getHash(this->size)]->put(n);
    }

    hashNode *get(int key){
        int hash = modularHash(key, this->size);
        return this->table[hash]->exists(key);
    }
};

int main(){
    HashTable *ht = new HashTable(100);

    for(int i = 0; i < 200; i++){
        hashNode *n = new hashNode(i,11*i);
        ht->insert(n);
    }

    cout<<ht->get(1)->value<<endl;
    cout<<ht->get(29)->value<<endl;
    cout<<ht->get(105)->value<<endl;
    cout<<ht->get(189)->value<<endl;
}
