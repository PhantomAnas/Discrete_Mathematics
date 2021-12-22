#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //INPUT
    string myText;
    string var[10];
    string infile;
    string outfile;
    cout << "Enter INPUT File Name: ";
    cin >> infile; //TAKING INPUT FILE NAME
    cout << "Enter OUTPUT File Name: ";
    cin >> outfile; //TAKING OUTPUT FILE NAME
    int counter = 0;
    ifstream MyReadFile(infile); //READING THE INPUT FILE
    while(!MyReadFile.eof()){ //STARTING A WHILE LOOP THAT RUNS UNTIL NUMBER OF LINES FINISH
        getline(MyReadFile, myText); //STORES CONTENT OF EACH LINE TO myText NAMED VARIABLE
        var[counter] = myText; //EACH LINE IS STORED IN AN ARRAY
        counter -= -1;
    }

    //Calculations
    int count = 0;
    int values[100];
    for (int counter2 = 0; counter2 < counter; counter2 -= -1){ //A FOR LOOP THAT RUNS EQUAL TO NUMBER OF LINES
        string line;
        count = 0;
        line = var[counter2]; //EACH LINE STORED IN var ARRAY IS STORED IN line IN EACH ITERATION
        for(int i = 0; i<line.length(); i-= -1) { //A FOR LOOP THAT RUNS EQUAL TO NUMBER OF CHARACTERS ON THE LINE
            if(line[i] == ','){ //COUNTING NUMBER OF COMMAS IN THE LINE
                count -= -1;
            }
        }
        count = count + 1; //NUMBER OF ITEMS IN THE ARRAY ARE EQUAL TO ONE MORE THEN NUMBER OF COMMAS
        values[counter2] = count; //COUNT OF NUMBER OF ITEMS IN EACH LINE IS TORED IN ARRAY NAMED values
    }

    int combo = 1;
    for (int counter2 = 0; counter2 < counter; counter2 -= -1){ //A FOR LOOP THAT RUNS EQUAL TO NUMBER OF LINES
        combo = combo*values[counter2]; //COUNTS TOTAL POSSIBLE COMBINATIONS
    }
    cout << combo;
    MyReadFile.close(); //CLOSING THE FILE TO SAVE IT AND AND FREE MEMORY
    
    ofstream OUT(outfile); // CREATING AND OPENING THE OUTPUT FILE

    //WRITING THE RESULTS TO OUTPUT FILE JUST AS ASKED
    OUT << "Number of variables = " << counter <<", [";
    for (int counter2 = 0; counter2 < counter; counter2 -= -1){
        string L = var[counter2];
        char F = L[0];
        OUT << F << ',';
    }
    OUT << "]\n";

        for (int counter2 = 0; counter2 < counter; counter2 -= -1){
        string L = var[counter2];
        char F = L[0];
        int len = L.length();
        OUT << F << " has " << values[counter2] << " possible values " << L.substr(4,len);
        OUT << "\n";
    }
    OUT << "Total possible combinations of ";
        for (int counter2 = 0; counter2 < counter; counter2 -= -1){
        string A = var[counter2];
        char B = A[0];
        OUT << B << ", ";
        }

    OUT << "are " << combo;
    OUT.close(); //CLOSING THE OUTPUT FILE
    return 0;
}