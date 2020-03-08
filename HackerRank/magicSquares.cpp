#include <bits/stdc++.h>

using namespace std;

const int N = 9;

struct MagicSqr{
    int square[3][3];

    MagicSqr(int a, int b, int d){
        square[0][0] = a;
        square[1][0] = b;
        square[0][1] = d;
    }
};

void generateThreeElementSubsets(int n, int i, vector<vector<int>>& subsets){
    if(n != 0){
        if(N-i+1 == n){
            while (n > 0){
                subsets[subsets.size()-1].push_back(i);
                n--;i++;
            }
        }
        else{
            vector<int> cp = subsets[subsets.size()-1];
            subsets[subsets.size()-1].push_back(i);
            generateThreeElementSubsets(n-1, i+1, subsets);
            subsets.push_back(cp);
            generateThreeElementSubsets(n, i+1, subsets);
        }
    }
}

bool fillUpAndValidateMagicSqr(MagicSqr* mSqr){
    int* counters = new int[10];
    for(int i = 0; i < 10; i++){
        counters[i] = 0;
    }
    int a = mSqr->square[0][0], b = mSqr->square[1][0], d = mSqr->square[0][1];
    counters[a]++; counters[b]++; counters[d]++;
    int c = 15 - b - a;if(c >= 1 and c <= 9)counters[c]++;
    int g = 15 - a - d;if(g >= 1 and g <= 9)counters[g]++;
    int e = 15 - c - g;if(e >= 1 and e <= 9)counters[e]++;
    int f = 15 - e - d;if(f >= 1 and f <= 9)counters[f]++;
    int h = 15 - b - e;if(h >= 1 and h <= 9)counters[h]++;
    int i = 15 - c - f;if(i >= 1 and i <= 9)counters[i]++;

    for(int j = 1; j < 10; j++){
        if(counters[j] != 1){
            return false;
        }
    }
    if(a+e+i != 15) return false;
    if(g+e+c != 15) return false;
    delete[] counters;
    mSqr->square[0][0] = a; mSqr->square[0][1] = b; mSqr->square[0][2] = c;
    mSqr->square[1][0] = d; mSqr->square[1][1] = e; mSqr->square[1][2] = f;
    mSqr->square[2][0] = g; mSqr->square[2][1] = h; mSqr->square[2][2] = i;
    return true;
}

void generateMagicSquares(vector<MagicSqr>& magicSquares){
    vector<vector<int>> subsets;
    vector<int> v;
    subsets.push_back(v);
    generateThreeElementSubsets(3,1,subsets);
    MagicSqr* mSqr = NULL;

    for(int i = 0; i < subsets.size(); i++){
        //1
        mSqr = new MagicSqr(subsets[i][0],subsets[i][1],subsets[i][2]);
        if(fillUpAndValidateMagicSqr(mSqr)) magicSquares.push_back(*mSqr);
        else delete mSqr;
        //2
        mSqr = new MagicSqr(subsets[i][0],subsets[i][2],subsets[i][1]);
        if(fillUpAndValidateMagicSqr(mSqr)) magicSquares.push_back(*mSqr);
        else delete mSqr;
        //3
        mSqr = new MagicSqr(subsets[i][1],subsets[i][0],subsets[i][2]);
        if(fillUpAndValidateMagicSqr(mSqr)) magicSquares.push_back(*mSqr);
        else delete mSqr;
        //4
        mSqr = new MagicSqr(subsets[i][1],subsets[i][2],subsets[i][0]);
        if(fillUpAndValidateMagicSqr(mSqr)) magicSquares.push_back(*mSqr);
        else delete mSqr;
        //5
        mSqr = new MagicSqr(subsets[i][2],subsets[i][1],subsets[i][0]);
        if(fillUpAndValidateMagicSqr(mSqr)) magicSquares.push_back(*mSqr);
        else delete mSqr;
        //6
        mSqr = new MagicSqr(subsets[i][2],subsets[i][0],subsets[i][1]);
        if(fillUpAndValidateMagicSqr(mSqr)) magicSquares.push_back(*mSqr);
        else delete mSqr;
    }

    //cout<<magicSquares.size()<<endl;

}

int calculateCost(vector<vector<int>> s, MagicSqr& m){
    int cost = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cost += abs(m.square[i][j] - s[i][j]);
        }
    }
    return cost;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector<MagicSqr> magicSqrs;
    generateMagicSquares(magicSqrs);
    cout<<magicSqrs.size()<<endl;
    int minCost = INT_MAX;
    int cost = 0;
    for(int i = 0; i < magicSqrs.size(); i++){
        cost = calculateCost(s, magicSqrs[i]);
        minCost = min(minCost, cost);
    }
    return minCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

    fout.close();

    return 0;
}