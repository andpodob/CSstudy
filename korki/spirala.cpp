#include <bits/stdc++.h>

using namespace std;

const int MAX = 9;

void fillTable(int t[MAX][MAX]){
    //zaczynamy w sorku
    int x = MAX/2;
    int y = MAX/2;

    //zmienna direction będzie służyć do ogarniania w jaki sposób zmienić współrzędne
    //dir%4 == 0-dół, 1-prawo, 2-góra, 3-lewo 
    int dir = 2;
    int len = 1; //długość wpisywanego aktualnie ciagu liczb
    int m = 0;

    int i = 1;
    while(i < MAX*MAX){
        //ta petla wpisuje do tablicy ciag o dlugosci len
        for(int n = 0; n < len; n++){
            //wpisujemy kolejna liczbe naturalna do tablicy
            t[x][y] = i++;
            //rozkminiamy jakie bedzie kolejne pole do wpisania
            if(dir%4 == 0){
                y++; //idziemy o jedno pole do gore
            }else if(dir%4 == 1){
                x++; //w prawo
            }else if(dir%4 == 2){
                y--; //w dol
            }else{
                x--; //w lewo
            }
        }
        //po wpisaniu ciagu zmieniamy kierunek(aby zakrecic o 90*)
        dir++;
        //ciągi jakie kolejno wpisujemy do tablicy mają postać: (1),(2),(3,4),(5,6),(7,8,9),(10,11,12)... jak widać ciągów danej długości jest po 2
        //zmienna m dba o to żeby wpisywać po dwa ciągi do tablicy
        m++;
        if(m%2 == 0){
            len++;
        }

    }
}

int main(){
    int tab[MAX][MAX];
    fillTable(tab);
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout<<tab[j][i]<<' ';
        }
        cout<<endl;
    }
}