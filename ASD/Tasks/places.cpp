#include <bits/stdc++.h>

using namespace std;

const int N = 10;

struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int availablePlaces(bool *tab[], int x, int y){
    int count = 0;
    queue<Point*> q;
    Point *temp;
    if(tab[x][y] == false) return count;
    else{
        count++;
        q.push(new Point(x,y));
        while(!q.empty){
            temp = q.front();
            q.pop();
            tab[temp->x][temp->y]=false;
            if(temp->x+1 < N and tab[temp->x+1][temp->y])q.push(new Point(temp->x+1, temp->y));
            if(temp->y+1 < N and tab[temp->x][temp->y+1])q.push(new Point(temp->x, temp->y+1));
            if(temp->x-1 >= 0 and tab[temp->x-1][temp->y])q.push(new Point(temp->x-1, temp->y));
            if(temp->y-1 < N and tab[temp->x][temp->y-1])q.push(new Point(temp->x, temp->y-1));
        }
    }
}

int main(){

}