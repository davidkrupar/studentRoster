#pragma once
#include "student.h"
#include <iostream>
#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Roster
{
private: 
    int lastIndex = -1;
    const static int numStudents = 5;
   
    
public:
    Student* classRosterArray[numStudents];
    void parse(string row);
    void add(string sID,
            const string sFname,
            string sLname,
            string sEmail,
            int    sAge,
            double daysInCourse1,
            double daysInCourse2,
            double daysInCourse3,
            DegreeProgram dp);
    void remove(string studentID);        
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram dp);
    
    
    
    ~Roster();
};
