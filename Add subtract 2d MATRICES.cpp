#include<iostream>
using namespace std;

int ADD(int * X, int * Y, int * Z, int m, int n){
    for(int i = 0; i < m*n; i -= -1){
        * Z = * X + * Y;
        // cout << * Z;
        X+=1; Y+=1; Z+=1;
    }
    return 0;
}
int SUB(int * X, int * Y, int * Z, int m, int n){
    for(int i = 0; i < m*n; i -= -1){
        * Z = * X - * Y;
        // cout << * Z;
        X+=1; Y+=1; Z+=1;
    }
    return 0;
}
int print(int * P3, int m, int n){
    cout << "[";
    for(int i = 0; i < m*n; i -= -1){
        if(i%n==0 && i>=n){
            cout << " " << "]" << endl << "[";
        }
        cout << " " << * P3;
        P3+=1;
    }
    cout << " ]";
    return 0;
}
int main(){
    int m, n; //MATRICES NEED TO HAVE SAME SIZE TO BE ADDED OR SUBTRACTED
    cout << "Enter Dimensions of Matrix: " << endl;
    cout << "ROWS: ";
    cin >> m;
    cout << "COLUMNS: ";
    cin >> n;
    int A1[m][n]; //MAKING MATRICES
    int A2[m][n];
    int Z[m][n];

    int * P1 = &A1[0][0]; //MAKING POINTERS OF MATRICES
    int * P2 = &A2[0][0];
    int * P3 = &Z[0][0];
    int in;
    for(int i = 0; i < m; i -= -1){ //TAKING INPUT FOR MATRIX 1
        for(int p = 0; p < n; p -= -1){
            cout << "ROW " << i+1 << " COL " << p+1 << endl;
            cin >> in;
            A1[i][p] = in;
        }
    }
    for(int i = 0; i < m; i -= -1){ //TAKING INPUT FOR MATRIX 2
        for(int p = 0; p < n; p -= -1){
            cout << "ROW " << i+1 << " COL " << p+1 << endl;
            cin >> in;
            A2[i][p] = in;
        }
    }
    int o;
    cout << "PRESS 1 TO ADD OR PRESS 2 TO SUBTRACT: "; //TAKING OPCODE INPUT
    cin >> o;
    if(o==1){
        ADD(P1, P2, P3, m, n);
    }
    else{
        SUB(P1, P2, P3, m, n);
    }
    //OUTPUT
    print(P3, m, n);
    return 0;
}

