#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 0.0001;

double funckja(int a){
    return a;
}


double quadratic(double x, double a, double b, double c){
    return a*pow(x,2)+b*x+c;
}

double bisection(double a, double b, double c_a, double c_b, double c_c){
    double c = (a+b)/2;
    double f_c = quadratic(c, c_a, c_b, c_c);
    double f_a, f_b;
    while (abs(f_c) > EPSILON)
    {   
        c = (a+b)/2;
        f_a = quadratic(a, c_a, c_b, c_c);
        f_b = quadratic(b, c_a, c_b, c_c);
        f_c = quadratic(c, c_a, c_b, c_c);

        if(f_b < 0 and f_c < 0 and f_a > 0){
            b = c;
        }else if(f_a < 0 and f_c < 0 and f_b > 0){
            a = c;
        }else if(f_b > 0 and f_c > 0 and f_a < 0){
            b = c;
        }else{
            a = c;
        }
    }
    
    return c;
}

// double bisection(double a, double b, function<double (double)> f){
//     double c = (a+b)/2;
    
//     while (abs(f(c)) > EPSILON)
//     {
//         if(f(c) < 0 and f(b) < 0 and f(a) > 0){
//             b = c;
//         }else if(f(c) < 0 and f(a) < 0 and f(b) > 0){
//             a = c;
//         }else if(f(c) > 0 and f(b) > 0 and f(a) < 0){
//             b = c;
//         }else{
//             a = c;
//         }
//         c = (a+b)/2;
//     }
    
//     return c;
// }

int main(){
    function<double (double)> f = [](double x){
        return sqrt(pow(2.71828,x))-pow(2,x+7)+5.18;
    }; 

    cout<<bisection(1.5, 2.5, 4.5,-13.2,8)<<endl;
    


}