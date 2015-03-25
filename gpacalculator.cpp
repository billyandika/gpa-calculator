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
      cout << "Enter subject, grade, and credit hours (e.g. 100 A 4.0 12 B 4.0): ";
      getline(cin, s);
    }while(s.compare("")==0);

    istringstream iss(s);
    string subject;
    string grade;
    float hours;

    float totalPoints = 0;
    float totalHours = 0;

    cout << "---------------------------" << endl;
    cout << setw(7) << "Subject" << setw(10) << "Grade" << setw(10) << "Hours" << endl;
    while(iss >> subject >> grade >> hours)
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

      cout << setw(7) << subject << setw(10) << grade << setw(10) << hours << endl;
      totalPoints += hours*gradeVal;
    }
    cout << "---------------------------" << endl;
    cout << setw(22) << left << "Total grade points: " << totalPoints << endl;
    cout << setw(22) << left << "Total hours: " << totalHours << endl;
    cout << setw(22) << left << "GPA: " << totalPoints/totalHours << endl;
    cout << "---------------------------" << endl;

    cout << endl << "Would you like to enter grades again? (y to run again): ";
    getline(cin,response);

  }while(response.compare("Y")==0 || response.compare("y")==0);
}
