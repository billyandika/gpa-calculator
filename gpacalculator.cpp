#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

int main()
{
  string response;
  do {
    
    string s;
    do {
      cout << "Enter subject, units, and letter grade to calculate total grade points" << endl
           << "and GPA (e.g. CSE30 4 A HIST100 4 B+): ";
      getline(cin, s);
    }while(s.compare("")==0);

    istringstream iss(s);
    string subject;
    string grade;
    float hours;

    float totalPoints = 0;
    float totalHours = 0;

    cout << "------------------------------" << endl;
    cout << left << setw(7) << "Subject" << "\t" << "Units" << "\t" << "Grade" << endl;
    while(iss >> subject >> hours >> grade)
    {
      totalHours += hours;
      float gradeVal;
      if(grade.compare("A+")==0) gradeVal = 4.00;
      else if(grade.compare("A")==0)  gradeVal = 4.0;
      else if(grade.compare("A-")==0) gradeVal = 3.7;
      else if(grade.compare("B+")==0) gradeVal = 3.3;
      else if(grade.compare("B")==0)  gradeVal = 3.0;
      else if(grade.compare("B-")==0) gradeVal = 2.7;
      else if(grade.compare("C+")==0) gradeVal = 2.3;
      else if(grade.compare("C")==0)  gradeVal = 2.0;
      else if(grade.compare("C-")==0) gradeVal = 1.7;
      else if(grade.compare("D+")==0) gradeVal = 1.3;
      else if(grade.compare("D")==0)  gradeVal = 1.0;
      else if(grade.compare("D-")==0) gradeVal = 0.7;
      else cout << "Grade entered is invalid" << endl;

      cout << setw(7) << subject << "\t" << hours << "\t" << grade << endl;
      totalPoints += hours*gradeVal;
    }
    cout << "------------------------------" << endl;
    cout << setw(22) << left << "Total grade points: " << totalPoints << endl;
    cout << setw(22) << left << "Total units: " << totalHours << endl;
    cout << setw(22) << left << "GPA: " << totalPoints/totalHours << endl;
    cout << "------------------------------" << endl;

    cout << endl << "Would you like to enter grades again? (y to run again): ";
    getline(cin,response);

  }while(response.compare("Y")==0 || response.compare("y")==0);
}
