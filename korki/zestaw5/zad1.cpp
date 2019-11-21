#include <bits/stdc++.h>

using namespace std;

struct ulamek{
    int l;
    int m;
};

int pow(int a, int n){
    int wynik = 1;
    for(int i = 0; i < n; i++){
        wynik*=a;
    }
    return wynik;
}

int euklides(int a, int b){
    while (a != b)
    {
        if(a > b){
            a -= b;
        }else
        {
            b -= a;
        }
    }
    return a;
}

ulamek skroc(ulamek u){
    int nwd = euklides(u.l, u.m);
    u.l = u.l/nwd;
    u.m = u.m/nwd;

    return u;
}

ulamek dodaj(ulamek u1, ulamek u2){
    ulamek wynik;
    u1.l = u1.l * u2.m;

    u2.l = u2.l * u1.m;

    wynik.l = u1.l + u2.l;
    wynik.m = u1.m * u2.m;

    return skroc(wynik);
}

ulamek odejmowanie(ulamek u1, ulamek u2){
    ulamek wynik;
    u1.l = u1.l * u2.m;

    u2.l = u2.l * u1.m;

    wynik.l = u1.l - u2.l;
    wynik.m = u1.m * u2.m;

    return skroc(wynik);
}


ulamek dzielenie(ulamek u1, ulamek u2){
    ulamek wynik;
    
    wynik.l = u1.l * u2.m;
    wynik.l = u1.m * u2.l; 

    return skroc(wynik);
}

ulamek pow(ulamek u, int n){
    u.l = pow(u.l, n);
    u.m = pow(u.m, n);

    return skroc(u);
}

ulamek read(int l, int m){
    ulamek u;
    u.l = l;
    u.m = m;

    return u;
}

void print(ulamek u){
    cout<<u.l<<'/'<<u.m;
}

int main(){

}