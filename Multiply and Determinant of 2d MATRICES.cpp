#include<iostream>
#include<new>
using namespace std;
int MUL(int * X, int * Y, int * Z, int m, int n, int l, int k){
    //MATRCIES ARE AVAILABLE TILL HERE SUCCESSFULLY
    int *XL;
    int *YL;
    int *ZL;
// [ 0 1 2 ] x [ 0 1 ]   // 0x0 + 1x2 + 2x4     0x1 + 1x3 + 2x5  ==   [10 13]
// [ 3 4 5 ]   [ 2 3 ] 
//             [ 4 5] 
    for(int c1 = 0; c1 < m; c1-= -1){ //RUNS m = 2 times FOR ROWS
        for(int c2 = 0; c2 < k ; c2-= -1){  //RUNS k = 2 times FOR COLS
            int f = 0; 
            XL = X; //CLONE OF ADDRESSES TO PRESERVE ORIGNAL ADDRESSES
            YL = Y;
            ZL = Z;
            /////
            YL+=c2; //ADDRESS WILL BE SAME IN 1ST LOOP as C2 = 0
                    //ADDRESS WILL INCREMENT BY c2 to MULTIPLY WITH 2ND COLUMN NEXT TIME
            // cout << "YL = " << YL << " LOOP : " << c1 << " NESTED LOOP : " << c2;    
            for(int c3 = 0; c3 < n; c3-= -1){ //RUNS n = 3 times for each ENTRY
                f+= ((*XL) * (*YL));
                XL+=1;
                YL+=k; //ADDING k = 2 to REACH NEXT ELEMENT IN NEXT ROW WHICH ARE 0 2 4 AND 1 3 5
            }
            *Z = f;
            Z+=1; //INCREMENTING Z TO REACH NEXT ELEMENT OF FINAL MATRICE WHICH IS A 2X2
            /////
        }
        X+=n;
    }
    // cout << Z << endl;
    // PRINTING THE FINAL MATRIX
    Z-=(m*k);
    // cout << Z;
    cout << "[";
    for(int i = 0; i < m*k; i -= -1){
        if(i%k==0 && i>=k){
            cout << " " << "]" << endl << "[";
        }
        cout << " " << * Z;
        Z+=1;
    }
    cout << " ]";
    return 0;
}
int DET(int * X, int m){ //lets do for a 1x1 2x2 AND 3x3 for a nxn matrix 
    int F = 0;
    int A; // INDEX ELEMENT
    int* AM = new int[(m - 1) * (m - 1)]; //ARRAY TO STORE MATRIX OF INDEX ELEMENT
    int* AP = &AM[0];
    int* X1 = X;
    if((m == 1) || (m == 2)){
        if(m==1){
            return * X;
        }
        else{
            int a = * X;
            int b = * (X+1);
            int c = * (X+2);
            int d = * (X+3);
            return ((a*d) - (b*c));
        }
    }
// [ 0 1 2 ] [0][0] --> [1][1] [1][2] [2][1] [2][2] 0 ROW 1 2
// [ 3 4 5 ] [0][1] --> [1][0] [1][2] [2][0] [2][2] 1 ROW 0 2
// [ 6 7 8 ] [0][2] --> [1][0]] [1][1] [2][0] [2][1] 2 ROW 0 1
    else{
        for(int c1 = 0; c1 < m; c1-= -1){
            A = *X1; 
            if((c1+1)%2 == 0){
                A*= -1; //MULTIPLE BY - FOR EVEN VALUES
            }
            int count = 0;
            for(int r = 1; r < m; r-= -1){ // r =1 bcz we dont need elemnts from row 0
                for(int c= 0 ; c < m ; c -= -1){
                    if(c!=c1){ //MAKING SURE SAME COLUMN IS IGNORED 
                        int * address = (X + (r*m) + c); //TO FIND 1D ADDRESS FROM A 2D ADDRESS 
                        AM[count] = * address;
                        count-= -1;
                    }
                }
            }
            F+= (A * DET(AP, m-1));
            X1+=1;
        }
        return F;
    }
    
}

int main(){
    // cout << P3 << endl; 
    // MUL(P1, P2, P3, m, n, l, k);
    int o;
    cout << "PRESS 1 TO MULTIPLY OR PRESS 2 TO FIND DETERMINANT: "; //TAKING OPCODE INPUT
    cin >> o;
    if(o==1){
        int m, n, l, k;
        //MAKING DYNAMIC ARRAYS USING new
        cout << "Enter Dimensions of Matrix 1: " << endl;
        cout << "ROWS: ";
        cin >> m;
        cout << "COLUMNS: ";
        cin >> n;
        cout << "Enter Dimensions of Matrix 2: " << endl;
        cout << "ROWS: ";
        cin >> l;
        cout << "COLUMNS: ";
        cin >> k;
        if (n == l){
            int * P1 = new int [ m * n];
            int * P2 = new int [ l * k];
            int * P3 = new int [ m * k];

            int * PP1 = P1;
            int * PP2 = P2;
            int in;
            for(int i = 0; i < m; i -= -1){ //TAKING INPUT FOR MATRIX 1
                for(int p = 0; p < n; p -= -1){
                    cout << "ROW " << i+1 << " COL " << p+1 << endl;
                    cin >> in;
                    * PP1 = in;
                    PP1 += 1;
                }
            }

            for(int i = 0; i < l; i -= -1){ //TAKING INPUT FOR MATRIX 2
                for(int p = 0; p < k; p -= -1){
                    cout << "ROW " << i+1 << " COL " << p+1 << endl;
                    cin >> in;
                    * PP2 = in;
                    PP2 += 1;
                }
            }
            MUL(P1, P2, P3, m, n, l, k);
        }   
        else{
            cout << "MATRICES CANT BE MULTIPLED ROWS NOT EQUAL TO COLUMNS";
        }
    }
    else{
        int m;
        cout << "Enter Dimensions of Matrix : " << endl;
        cin >> m;
        int A1[m*m];
        int * P1 = &A1[0];
        int * PP1 = P1;
        int in;
        for(int i = 0; i < m; i -= -1){ //TAKING INPUT FOR MATRIX 1
            for(int p = 0; p < m; p -= -1){
                cout << "ROW " << i+1 << " COL " << p+1 << endl;
                cin >> in;
                * PP1 = in;
                PP1 += 1;
            }
        }
        cout << DET(P1, m);
    }
    return 0;
}
