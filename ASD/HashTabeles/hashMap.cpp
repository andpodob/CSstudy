#include <bits/stdc++.h>

using namespace std;
struct Entry{
	string key;
	string value;

	Entry(string key, string value){
		this->key = key;
		this->value = value;
	}
};

struct HashTable{
	int size;
	Entry **tab;
	int *state;  //0-empty 1-occupied 2-sth was here
    int hashFunc(string);
	bool put(string, string);
	string get(string);

	HashTable(int size){
		this->size = size;
		this->tab = new Entry*[size];
		this->state = new int[size];
        for(int i = 0; i < size; i++){
            this->state[i] = 0;
        }
	}
};

int HashTable::hashFunc(string s){
	unsigned int p = 37;
	unsigned int hash = 0;
    for(int i = 0; i < s.size(); i++){
		hash+=(int)s[i]*p;
		p*=37;
	}
	hash = hash % this->size;
	return hash;
}

bool HashTable::put(string key, string value){
	unsigned int hash = this->hashFunc(key);
	int counter = 0;
    while(this->state[hash] == 1 and counter < this->size){
		hash++;
		hash = hash % this->size;
		counter++;
	}

	if(counter == this->size){
		return false;
    }else{
	    this->tab[hash] = new Entry(key, value);
        this->state[hash] = 1;
	    return true;
    }
}
string HashTable::get(string key){
	int hash = this->hashFunc(key);
	int counter = 0;

    while(this->tab[hash]->key != key and (this->state[hash] == 1 or this->state[hash] == 2) and counter < this->size){
        hash++;
        counter++;
    }
    if(this->state[hash] == 1 and this->tab[hash]->key == key){
	    return this->tab[hash]->value;
    }
    else{
	    return NULL;
    }
}


int main(){
    HashTable h(3);

    cout<<h.put("1","Ala")<<endl;
    cout<<h.put("2", "Banan")<<endl;
    cout<<h.put("3","Cebula")<<endl;
    cout<<h.put("4", "Down")<<endl;
    cout<<h.put("5","Entry")<<endl;

    cout<<h.get("1")<<endl;
    cout<<h.get("2")<<endl;
    cout<<h.get("3")<<endl;
    cout<<h.get("4")<<endl;
    cout<<h.get("5")<<endl;
}
