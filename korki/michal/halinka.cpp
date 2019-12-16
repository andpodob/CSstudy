#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int tab[n];
    for(int i = 0; i < n; i++){
        cin >> tab[i];
    }
    
    int licznik=0;
    
    int k = 0;
    while(k < n and tab[k] == 0) k++;
    
    for(int i = k; i < n; i++){
        if(tab[i] == 1) licznik++;
        else if(i < n-1 and tab[i+1] == 1)licznik++;
        else{
            while (i < n-1 and tab[i+1] == 0)
            {
                i++;
            }
            
        }
    }
    
    cout<<licznik<<endl;
}