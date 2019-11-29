#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int N = 5;

int waga(int n){
    int result = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) {
            result++;
        }
        while (n % i == 0){
            n = n/i;
        }
    }
    return result;
}

bool sum(int sum1, int sum2, int sum3, int wagi[N], int indeks){
    if(indeks==N && sum1==sum2 && sum2==sum3)return true;
    if(indeks==N)return false;
    return sum(sum1 + wagi[indeks], sum2, sum3, wagi, indeks + 1) ||
           sum(sum1, sum2 + wagi[indeks], sum3, wagi, indeks + 1) ||
           sum(sum1, sum2, sum3 + wagi[indeks], wagi, indeks + 1);
}

bool sprawdz(int liczby[N]){
    int wagi[N];
    for (int i = 0; i < N; ++i) {
        wagi[i] = waga(liczby[i]);
    }

}

int main() {
    int t[]={30,10,8,9,18};
    printf("%d", sprawdz(t));
    return 0;
}