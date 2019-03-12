#include <bits/stdc++.h>

using namespace std;
const int MAX_H = 100;

struct box{
    bool full;
    int to_fill;
    int width;
    int floor_y, ceil_y;

    box(int c_x, int c_y, int f_x, int f_y){
        floor_y = f_y;
        ceil_y = c_y;
        to_fill = c_y-f_y;
        width = f_x-c_x;
        full = false;
    }

    void fill_layer(){
        to_fill--;
        if(to_fill == 0) full = true;
    }
};

vector<box*> boxes;
vector<box*> MODEL[MAX_H];

void insert_box(box *b){
    boxes.push_back(b);
    int f_y = b->floor_y;
    int c_y = b->ceil_y;
    for(int i = f_y; i < c_y; i++){
        MODEL[i].push_back(b);
    }
}

int fill_MODEL(int A){
    int width_sum;
    int count = 0;
    int layer = 0;
    while(A > 0){
        width_sum = 0;
        for(int i = 0; i < MODEL[layer].size(); i++){
            width_sum+=MODEL[layer][i]->width;
        }
        if(A >= width_sum && width_sum != 0){
            for(int i = 0; i < MODEL[layer].size(); i++){
                MODEL[layer][i]->fill_layer();
            }
            layer++;
        }
        A-=width_sum;
    }
    for(box* a : boxes)if(a->full)count++;

    return count;
}

int main(){
    box* b1 = new box(0,1,2,0);
    box* b2 = new box(3,3,4,0);
    box* b3 = new box(1,4,5,2);

    insert_box(b1);
    insert_box(b2);
    insert_box(b3);

    cout<<fill_MODEL(5)<<endl;

}

