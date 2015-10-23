// Name: Mavey Ma
// Created: Thursday, October 22, 2015
// FILERB PRACTICE
#include <iostream>
#include <fstream> //ALLOWS YOU TO READ AND WRITE TO FILES
#include <cstdlib>
#include <iomanip> //setw()
using namespace std;

int main()
{
    ifstream fin; //scores.txt
    ofstream fout; //result.txt
    double val;
    string firstName, lastName, highestFirstName, highestLastName;
    double s1, s2, s3, s4, s5, s6, average;
    double highestScore = 0;
    
    char userChoosesFile[12];
    cout << "Enter the file you wish to open: " << endl;
    cin >> userChoosesFile;
    
    //OPEN SESAME, FILES!
    fin.open(userChoosesFile);
    fout.open("result.txt");
    
    //IN CASE FILE DOESN'T OPEN PROPERLY
    if (fin.fail())
    {
        cout << "ERROR OPENING INPUT FILE.\n";
        exit(1);
    }
    if (fout.fail())
    {
        cout << "ERROR OPENING INPUT FILE.\n";
        exit(1);
    }
    
    while (fin >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        fout.setf(ios::left);
        average = (s1 + s2 + s3 + s4 + s5 + s6) / 6.0;
        
        fout << setw(12) << firstName 
             << setw(12) << lastName
             << setw(6) << s1 
             << setw(6) << s2
             << setw(6) << s3 
             << setw(6) << s4 
             << setw(6) << s5 
             << setw(6) << s6 
             << setw(6) << "Average: " << average
             << endl;
        
        highestScore = max(average, highestScore);
        /*
        if (highestScore)  
        {
            highestFirstName = firstName;
            highestLastName = lastName;
        }
        */
    }
    fout << "\nHighest score: " << highestScore << endl;
    //fout << "\nHighest score: " << firstName << " " << lastName << endl;
    //CLOSE FILES
    fin.close();
    fout.close();
    return 0;
}
