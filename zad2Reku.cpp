#include <bits/stdc++.h>

using namespace std;

void wypiszPermutacjeRequ(int tab[9], int idx, int wykorzystane[10]){
    if(idx == 9){
        for(int i = 0; i < 9; i++){
            cout<<tab[i]<<" ";
        }
        cout<<endl;
    }else{
        if(tab[idx-1] == 2 || tab[idx-1] == 3 || tab[idx-1] == 5 || tab[idx-1] == 7){
            for(int i = 2; i <= 9; i++){
                if(wykorzystane[i] == 0 
                and i != 2 and i != 3 and i != 5 and i != 7
                and abs(tab[idx-1]-i) >=2){
                    
                    tab[idx] = i;
                    wykorzystane[i] = 1;
                    wypiszPermutacjeRequ(tab, idx+1, wykorzystane);
                    wykorzystane[i] = 0;
                }
            }
        }else{
            for(int i = 2; i <= 9; i++){
                if(wykorzystane[i] == 0 and abs(tab[idx-1]-i) >=2){
                    tab[idx] = i;
                    wykorzystane[i] = 1;
                    wypiszPermutacjeRequ(tab, idx+1, wykorzystane);
                    wykorzystane[i] = 0;
                }
            }
        }
    }
}

void wypiszPermutacje(){
    int wykorzystane[10];
    for(int i = 0; i < 10; i++){
        wykorzystane[i] = 0;
    }
    //wykorzystane[0] = 1;
    wykorzystane[1] = 1;
    int tab[9];
    tab[0] = 1;
    wypiszPermutacjeRequ(tab,1,wykorzystane);
}


int main(){
    wypiszPermutacje();
}