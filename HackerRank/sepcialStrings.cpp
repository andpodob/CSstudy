#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    if(s.size() == 0) return 0;
    int counter = 0;
    vector<pair<char, int>> groupedStrings;
    pair<char, int> p = make_pair(s[0], 1);
    for(int i = 1; i < s.size(); i++){
        if(s[i] == p.first) p.second++;
        else{
            groupedStrings.push_back(p);
            p = make_pair(s[i], 1);
        }
    }
    groupedStrings.push_back(p);
    for(int i = 0; i < groupedStrings.size(); i++){
        if(i > 0 and i < groupedStrings.size()-1 and groupedStrings[i].second == 1){
            if(groupedStrings[i-1].first == groupedStrings[i+1].first){
                counter+=min(groupedStrings[i-1].second, groupedStrings[i+1].second);
            }
        }
        
        counter+=((groupedStrings[i].second + 1)*groupedStrings[i].second)/2;
        
    }
    return counter;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    //int n;
    //cin >> n;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // string s;
    // getline(cin, s);

    string s = "abcbaba";
    long result = substrCount(s.size(), s);

    cout<<result;
    //fout << result << "\n";

    //fout.close();

    return 0;
}
