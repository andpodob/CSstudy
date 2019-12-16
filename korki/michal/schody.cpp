#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int sch[n];

    int ilosc = 0;
    for(int i = 0; i < n; i++){
        cin>>sch[i];
        if(sch[i] == 1)ilosc++;
    }

    int odp[ilosc];
    int k = 0;

    for(int i = 0; i < n; i++){
        if(sch[i] == 1){
            if(i > 0){
                odp[k] = sch[i-1];
                k++;
            }
        }
    }
    odp[k] = sch[n-1];

    cout<<ilosc<<endl;
    for(int i = 0; i < ilosc; i++){
        cout<<odp[i]<<" ";
    }
    cout<<endl;
}