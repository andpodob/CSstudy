#include <bits/stdc++.h>

using namespace std;

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = temp;
}

int partition(string T[], int p, int k){
    int i = p-1;
    int j = k+1;
    string pivot = T[p];
    while(true){
        do{
            i++;
        }while(T[i].length() < pivot.length());
        do{
            j--;
        }while(T[j].length() > pivot.length());
        if(i < j){
            swap(T[i], T[j]);
        }else return j;
    }
}

void quickSortByLength(string T[], int p, int k){
    if(p < k){
        int j = partition(T, p, k);
        quickSortByLength(T, p, j);
        quickSortByLength(T, j+1, k);       
    }
}

void counting_sort(string T[], int p, int n, int pos){
    int N = (int)'z'-(int)'a';
    int C[N];
    string result[n-p];
    for(int i = 0; i < N; i++)C[i]=0;
    for(int i = p; i < n; i++)C[(int)T[i][pos]-(int)('a')]++;
    for(int i = 1; i < N; i++)C[i]+=C[i-1];
    for(int i = p; i < n; i++){
        cout<<T[i][pos]<<endl;
        int x = --C[(int)T[i][pos]-(int)('a')];
        result[x]=T[i];
    }
    for(int i = 0; i < n-p; i++)T[i+p] = result[i];
}

void radix(string T[], int n){
    int max_len = 0, p;
    for(int i = 0; i < n; i++)if(T[i].length() > max_len)max_len=T[i].length();
    for(int i = 0; i < max_len; i++){
        p = n;
        for(int j = n-1; j >=0; j--){
            if(T[j].length() >= max_len - i)p--;
        }
        for(int x = 0; x < n; x++)cout<<T[x]<<endl;
        cout<<endl;
        counting_sort(T, p, n, i);
    }
}

int main(){
    string T[10];
    int len = 0;
    string temp;
    for(int i = 0; i<10; i++){
        temp = "";
        len = rand()%5+1;
        for(int i = 0; i < len; i++){
            temp+=((char)(rand()%20+(int)'a'));
        }
        T[i] = temp;
    }
    for(string a : T)cout<<a<<endl;
    quickSortByLength(T, 0, 9);
    radix(T,10);
    cout<<endl;
    for(string a : T)cout<<a<<endl;
}
