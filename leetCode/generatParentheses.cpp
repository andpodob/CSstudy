#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void generator(vector<string>& results, int opening, int closing, int n, string* s){
        if(opening == n && closing == n){
            results.push_back(*s);
        }else{
            if(opening == closing){
                s->push_back('(');
                generator(results, opening+1, closing, n, s);
            }else{
                if(opening == n){
                    s->push_back(')');
                    generator(results, opening, closing+1, n, s);
                }else{
                    s->push_back(')');
                    generator(results, opening, closing+1, n, s);
                    s->push_back('(');
                    generator(results, opening+1, closing, n, s);
                }
            }
        }
        s->pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string s = "(";
        generator(results, 1, 0, n, &s);
        return results;
    }
};

int main(){
    Solution s;
    vector<string> result = s.generateParenthesis(3);
    cout<<"["<<endl;
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<","<<endl;
    }
    cout<<"]"<<endl;
}