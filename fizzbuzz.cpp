#include <bits/stdc++.h>

using namespace std;

void fizzBuzz();
string translateNumber(int);
void test();
bool assertEquals();

void fizzBuzz(){
    for(int a = 1; a <= 100; a++){ //that fu** bitch iterates through 100 numbers...
        cout<<translateNumber(a);
        cout<<endl;
    }
}

int mod26(int x){
   return (x%26+26)%26; 
}

string translateNumber(int toTranslate){
    string temp= "";
    if(toTranslate%3 != 0 && toTranslate%5 != 0){
            temp = to_string(toTranslate);
    }else{
        if(toTranslate%3==0){
            temp+="Fizz";
        }
        if(toTranslate%5==0){
            temp+="Buzz";
        }
    }
    return temp;   
}

bool assertEquals(string a, string b){
    string e ="Bład kurcze bele " + b;
    if(a == b) return true;
    throw e;
}

void test(){
    try{
    /*test 1 liczbu*/
        assertEquals(translateNumber(19), "18");
    /*test 2 Fizz*/
        assertEquals(translateNumber(33), "Fizz");
    /*test 3 Buzz*/
        assertEquals(translateNumber(25), "Buzz");
    /*test 4 FizzBuzz*/
        assertEquals(translateNumber(15), "FizzBuzz");
    }catch(string e){
        cout<<e<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    float a = 0.345678;
    // for(int a = 0; a < 256; a++)cout<<(char)a<<endl;
    // fizzBuzz();
    test();
    cout<<endl;
}