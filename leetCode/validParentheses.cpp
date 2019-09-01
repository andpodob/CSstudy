#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        char c;
        if(s.size() == 0) return true;
        if(s[0] == '}' || s[0] == ']' || s[0] == ')') return false;
        else{
            stack.push(s[0]);
        }
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if(stack.size()==0) return false;
                
                c = stack.top();
                if((c == '{' && s[i] == '}') || (c == '[' && s[i] == ']') || (c == '(' && s[i] == ')')) stack.pop();
                else return false;
            }else stack.push(s[i]);
        }
        return (stack.size() == 0);
    }
};

int main(){
    Solution s;
    cout<<s.isValid("{{}[()}")<<endl;
}