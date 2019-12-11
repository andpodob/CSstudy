#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void reverseTab(int* tab, int len){
    for(int i = 0; i < len/2; i++){
        swap(tab+i,tab+(len-i-1));
    }
}

//przekazywanie przez kopie i przez wskaznik
//jak "zwrocic" trzy wartosci z funkcji
void jakasOperacja(int *a, int *b, int *c){
    *a = (*a) * (*b);
    *b = (*b) * (*c);
    *c = (*a) * (*c);
}

int main(){
    // operator *-wyluskania i &-pobranie adresu
    int a = 8; // <- rezerwujemy 4 bajty i wpisujemy w nie wartosc 8
    int* adres8 = &a; //<- mozemy pobrac adres tych 4 bajtow
    cout<<"Wartosc w zmiennej a: "<<a<<endl;
    cout<<"Adres naszej osemki: "<<adres8<<endl;
    cout<<"Wartosc pod tym adresem: "<<*adres8<<endl;
    //majac adres pola w ktorym znajduje sie 8, bez tykania zmiennej 'a', mozemy zmienic dane zamisane 
    //na tym obszarze pamieci
    *adres8 = 5;
    cout<<"Wartosc pod tym adresem: "<<*adres8<<endl;
    //co ciekawe jako ze na dokladnie tym samym obszarze operuje zmienna a, jej wartosc tez sie zmienila
    cout<<"Wartosc w zmiennej a: "<<a<<endl;
    //dziala to tez w druga strone
    a = 3;
    cout<<"Wartosc pod tym adresem: "<<*adres8<<endl;
    cout<<"Wartosc w zmiennej a: "<<a<<endl;

    a = 3;
    int b = 4;
    int c = 1;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    jakasOperacja(&a,&b,&c);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;

    int tab[] = {1,2,3,4,5,6,7};
    int len = 7;

    for(int i = 0; i<len; i++){
        cout<<tab[i]<<" "; 
    }
    cout<<endl;
    reverseTab(tab, len);
    for(int i = 0; i<len; i++){
        cout<<tab[i]<<" "; 
    }
    cout<<endl;
}