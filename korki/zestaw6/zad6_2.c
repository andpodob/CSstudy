#include <stdio.h>
#include <stdbool.h>

int N = 6;

bool odwaz(int odwazniki[N], int masa, int indeks){
    if (masa == 0) {
        return true;
    }
    for (int i = indeks; i < N; i++) {
        if (odwaz(odwazniki, masa - odwazniki[i], i + 1) ||
            odwaz(odwazniki, masa + odwazniki[i], i + 1)) return true;
    }
    return false;
}

int main() {
    int t[]={30,10,8,9,18};
    printf(odwaz(t, 0, 0) ? "true" : "false");
    return 0;
}