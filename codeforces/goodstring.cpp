#include <bits/stdc++.h>

using namespace std;

int counter;
string word = "";

void produceGoodString(){
    if(word.size()%2 == 1){
        for(int i = 1; i < word.size(); i++){
            if(word[i-1] == word[i]){
                counter++;
                word.erase(word.begin()+i-1);
                produceGoodString();
            }
        }
    }else{
        for(int i = 0; i < word.size(); i++){
            if(i+1%2 == 0  && word[i] == word[i+1]){
                counter++;
                word.erase(word.begin()+i-1);
                produceGoodString();
            }
        }
    }
}   

int main(){
    int n; cin>>n;
    cin>>word;
    counter = 0;
    produceGoodString();
    cout<<counter<<endl;
    cout<<word<<endl;
}