#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    // vector<int> results;
    vector<pair<int, int>> hourGlass = 
    {
        make_pair(0,0), make_pair(1,0), make_pair(2,0),
                        make_pair(1,1),
        make_pair(0,2), make_pair(1,2), make_pair(2,2)
    };
    int sum = 0;
    int Max = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sum = 0;
            for(int k = 0; k < hourGlass.size(); k++){
                sum+=arr[i+hourGlass[k].first][j+hourGlass[k].second];
            }
            Max = max(Max, sum);
        }
    }
    return Max;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    arr[0] = {-9,-9,-9,1,1,1};
    arr[1] = {0,-9,0,4,3,2};
    arr[0] = {-9,-9,-9,1,2,3};
    arr[1] = {0,0,8,6,6,0};
    arr[0] = {0,0,0,-2,0,0};
    arr[1] = {0,0,1,2,4,0};
    // for (int i = 0; i < 6; i++) {
    //     arr[i].resize(6);

    //     for (int j = 0; j < 6; j++) {
    //         cin >> arr[i][j];
    //     }

    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}
