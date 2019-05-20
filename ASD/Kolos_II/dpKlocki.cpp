#include <bits/stdc++.h>

using namespace std;

struct range{
    int x, y;
    range(int x, int y){
        this->x = x; this->y = y;
    }

    bool isOverlapping(range *r){
        if((r->x >= x && r->x <= y ) || (r->y >= x && r->y <= y))return true;
        else return false;
    }
};

int N = 10; // liczba przedzialow
int dp[10]; // cache do rekurencji


int range_h(range ** ranges, int i){
    int j = i;
    if(dp[i] != 0){
        cout<<"dzust kecz!"<<endl; 
        return dp[i];
    }
    else{
        range* r = ranges[i];
        int max = 0, temp; i--;
        for(; i >= 0; i--){
            if(r->isOverlapping(ranges[i]) == true){
                temp = range_h(ranges, i);
                if(temp > max) max = temp;
            }
        }
        dp[j] = max+1;
        return dp[j];
    }
}

int main(){
    range* ranges[10];
    for(int i = 0; i < 10; i++){
        ranges[i] = new range(rand()%10, rand()%10);
    }

    cout<<ranges[0]->isOverlapping(ranges[1])<<endl;
    cout<<range_h(ranges, 4)<<endl;
}