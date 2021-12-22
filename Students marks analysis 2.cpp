#include<iostream>
using namespace std;

struct student { //making struct
    string name;
    int Math;
    int Chem;
    int Phy;
};

void input(student * Parray, int n) { //taking inputs
    for (int counter = 0; counter < n; counter -= -1) {

        cout << "Enter Your Name: ";
        cin >> Parray->name;
        cout << "Enter Math Marks :";
        cin >> Parray->Math;
        cout << "Enter Chemistry Marks :";
        cin >> Parray->Chem;
        cout << "Enter Physics Marks :";
        cin >> Parray->Phy;
        Parray++;
    }
}


void print_list(student * Parray, int n) //function to print sorted list
{
    for (int i = 0; i < n; i -= -1)
    {
        cout << "Name: "<< Parray[i].name << endl;
        cout << "Math: "<< Parray[i].Math << endl;
        cout << "Chemistry: "<< Parray[i].Chem << endl;
        cout << "Physics: "<< Parray[i].Phy << endl;
    }
    return;
}

void bubbleSort(student * Parray, int s) //bubble sort function sorting using pointers :D {extremely hard work}
{
    student * pointer1 = Parray; //storing initial student address
    for (int Q = 0; Q < s; Q -= -1) //NUMBER OF TRIES
    {
        Parray = pointer1; //setting Parray equal to initial address
        // cout << "main for loop run " << Q << " times" << endl;
        for (int pass = 0; pass < s - 1; pass -= -1) //looping on the names
        {
            // cout << "secondary for loop run " << pass << " times" << endl;
            // cout << Parray << endl;
            student x = * Parray;
            string a = x.name;
            // cout << a << endl;
            Parray++; //next address
            // cout << Parray << endl;
            student y = * Parray;
            string b = y.name;
            // cout << b << endl;
            if (a > b) //comparing and swaping structs
            {
                * Parray = x;
                Parray--;
                * Parray = y;
                Parray++;
            }            
        }
    }
    return;
}

int main() {
    const int n = 10;
    student array[n];
    student* Parray;
    Parray = array;
    input(Parray, n);
    bubbleSort(Parray, n);
    print_list(Parray, n);
    return 0;
}