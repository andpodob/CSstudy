#include <bits/stdc++.h>

using namespace std;

void kubelkowe(int tab[], int n){
    int cmax=tab[0];
    int cmin=tab[0];
    for (int i = 0; i < n; i++){
        if (tab[i]>cmax){
            cmax=tab[i];
        }
        if (tab[i]<cmin){
            cmin=tab[i];
        }
    }

    int* liczniki = new int[cmax-cmin+1];
    for (int i = 0; i<cmax-cmin+1;i++){
        liczniki[i]=0;
    }

    int adr = 0;
    for (int i = 0; i < n;i++){
        adr = tab[i]-cmin;
        liczniki[adr]++;// = liczniki[adr]+1;
    }

    adr = 0;
    for(int i = 0; i < cmax-cmin+1; i++){
        while(liczniki[i] > 0){
            tab[adr] = i + cmin;
            liczniki[i]--;
            adr++;
        }
    }
}
/*

 <typ_danych> nazwa[ilosc elentow]; //statyczna!!!

 <typ_danych>* nazwa = new <typ_danych>[ilosc_elementow]; //dynamiczna!!!
*/
int main(){
    int tab[] = {-456, 1002, 1001, 1008, 1008, 1007, 1007, 1001, 3004,-1, 701};
    int n = 11;

    for(int i = 0; i< n; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    kubelkowe(tab, n);

    for(int i = 0; i< n; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    return 0;
}