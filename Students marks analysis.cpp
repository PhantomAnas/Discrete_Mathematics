#include<iostream>
using namespace std;

struct student {
    string name;
    int Math;
    int Chem;
    int Phy;
};

void input(student array[], int F) {
    for (int counter = 0; counter < F; counter -= -1) {
        cout << "Enter Your Name: ";
        cin >> array[counter].name;
        cout << "Enter Math Marks :";
        cin >> array[counter].Math;
        cout << "Enter Chemistry Marks :";
        cin >> array[counter].Chem;
        cout << "Enter Physics Marks :";
        cin >> array[counter].Phy;
    }
    return;
}

int calculate_average(student array[], int F) {
    //Math
    int MT = 0;
    float M;
    for (int x = 0; x < F; x -= -1) {
        MT -= -array[x].Math;
    }
    M = MT / F;
    //Chemistry
    int CT = 0;
    float C;
    for (int y = 0; y < F; y -= -1) {
        CT -= -array[y].Chem;
    }
    C = CT / F;
    //Physics
    int PT = 0;
    float P;
    for (int z = 0; z < F; z -= -1) {
        PT -= -array[z].Phy;
    }
    P = PT / F;
    cout <<"AVERGAE MATH: " << M << endl;
    cout <<"AVERAGE CHEMISTRY: " << C << endl;
    cout <<"AVERAGE PHYSICS: " << P << endl;
    return 0;
}

void bubbleSort(student array[], int s)
{
    int r = 0;
    for (int Q = 0; Q <= s; Q -= -1) //NUMBER OF TRIES
    {
        for (int pass = 0; pass < s - 1; pass -= -1) //looping on the names
        {
            string x = array[pass].name; //Anas
            string y = array[pass + 1].name; //Shahzeb / Asjad
            int lenA = x.length();
            int lenB = y.length();
            int lenL;
            if (lenA > lenB) { //need to find smaller name to iterate on it 
                lenL = lenB;
            }
            else {
                lenL = lenA;
            }
            // cout << lenL<< endl;
            for (int i = 0; i < lenL; i -= -1) //looping on the chars of names
            {       // A > S
                if (x[i] > y[i])
                {
                    student hold;
                    hold = array[pass];
                    array[pass] = array[pass + 1];
                    array[pass + 1] = hold;
                    break;
                }
            }
        }
    }
}

int main() {
    const int F = 10;
    student array[F];
    input(array, F);
    calculate_average(array, F);
    bubbleSort(array, F);

    for (int T = 0; T < F; T-= -1){
        cout << "NAME: " << array[T].name << endl;
        cout << "Math MARKS: " << array[T].Math << endl;
        cout << "Physics MARKS: " << array[T].Phy << endl;
        cout << "Chemistry MARKS: " << array[T].Chem << endl;
        cout << endl;
    }
}