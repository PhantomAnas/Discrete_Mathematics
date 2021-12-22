#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int Arthimetic(float n, float a, float d){
    return (n/2)*(2*a + (n-1)* d);
}

int Geometric(float n, float a, float r){
    if (r>1){
        return (a*((pow(r, n))-1))/(r-1);
    }
    else{
        return (a*(1-pow(r, n)))/(1-r);
    }
}

int main() {
    float n;
    float d;
    float a;
    cout << "Enter number of values in series: ";
    cin >> n;
    cout << "Enter First value of series: ";
    cin >> a;
    cout << "Enter common difference/common ratio: ";
    cin >> d;
    int mode;
    cout << "Press 1 to calculate Arthimetic Sum AND 2 to calculate Geometric Sum: ";
    cin >> mode;
    if (mode == 1){
        cout << Arthimetic(n, a, d);
    }
    else{
        cout << Geometric(n, a, d);
    }
    return 0;
}

