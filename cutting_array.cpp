#include <bits/stdc++.h>

using namespace std;

int check_array(int array[], int start, int sum, int N){
    int cut_counter = 0;
    int current_sum = 0;
    for(int i = start; i < N; i++){
        current_sum+=array[i];
        if(current_sum > sum) return -1;
        if(current_sum == sum){
            current_sum = 0;
            cut_counter++;
        }
    }
    return cut_counter;
}

int count_cuts(int array[], int N){
    int m = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum+= array[i];
        m = max(m, check_array(array, i+1, sum, N));
    }
    m = (m == 0)?0:m+1;
    return m;
}

int main(){
    // int test_array[] = {2,2,4,4};
    // int N = 4;
    // int test_array[] = {2,3,5,7,1,8};
    // int N = 6;
    int test_array[] = {8,3,5,7,1,8};
    int N = 6;
    cout<<count_cuts(test_array, N)<<endl;
}