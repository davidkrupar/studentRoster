
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>



using namespace std;

#include "roster.h"
#include "student.h"
#include "degree.h"


void Roster::parse(string studentData)
{
    
    int rhs = studentData.find(",");
    string sID = studentData.substr(0, rhs);
    
    int lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    string sFname = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string sLname = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string sEmail = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double sAge = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double d1 = stod(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double d2 = stod(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double d3 = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    DegreeProgram dp;
    string programInputString = studentData.substr(lhs, studentData.length() - lhs);
    
    
     if (programInputString == "SECURITY") { dp = DegreeProgram::SECURITY; }
        else if  (programInputString == "SOFTWARE") { dp = DegreeProgram::SOFTWARE; }
        else    dp = DegreeProgram::NETWORK; 
    
        
       
   
    
    add(sID, sFname, sLname, sEmail, sAge, d1, d2, d3, dp);
}

void Roster::add(string studentID, string f_Name, string l_Name, string sEmail, int sAge, double days1, double days2, double days3, DegreeProgram dp)
{
    double darr[3] = {days1,days2,days3};
    
    classRosterArray[++lastIndex] = new Student(studentID, f_Name, l_Name, sEmail, sAge, darr, dp);
}

void Roster::printAll()
{
    
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        Roster::classRosterArray[i] -> print();
        
    }
}    
    
void Roster::printByDegreeProgram(DegreeProgram dp)
{
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i] -> getDegreeProgram() == dp) classRosterArray[i] -> print();
    }
    cout << std::endl;
}

void Roster::printInvalidEmails()
{
    bool any = true;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string sEmail = (classRosterArray[i] ->getEmail());
        if(sEmail.find(' ') != string::npos || sEmail.find('.') == string::npos || sEmail.find('@') == string::npos)
        {
            
            any = false;
            cout << sEmail << " - is invalid. " << std::endl;
        }
        
    }
    if (any) cout << "NONE" << std::endl;
}
    
void Roster::printAverageDaysInCourse(string studentID)
{
    
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if(classRosterArray[i] -> getID() == studentID) {
           cout <<  "Student ID: " << studentID << ", average days in course is: ";
        cout << std::llround((classRosterArray[i] -> getDays()[0]
        + classRosterArray[i] -> getDays()[1]
        + classRosterArray[i] -> getDays()[2])/3) << std::endl;
    }
   
        }
}


void Roster::remove(string studentID)
{
    bool success = false;
    for (int i = 0; i < Roster::lastIndex; i++)
    {
        if (classRosterArray[i] -> getID() == studentID)
        {
            success = true;
            Student* temp = classRosterArray[i];
            Student* temp1 = classRosterArray[numStudents - 2];
            Student* temp2 = classRosterArray[numStudents - 1];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = temp;
            classRosterArray[numStudents - 2] = temp2;
            classRosterArray[numStudents - 3] = temp1;
            Roster::lastIndex--;
            
        }
    }
   if (success)
{
       cout <<endl;
}
        
else cout << "The student with the ID: " << studentID << " was not found.";
}
    
    Roster::~Roster()
{
    cout << "DONE" << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
  
    
    
    
    

