#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{  
public:
    const static int daysArraySize = 3;
private:
    string studentID;
    string f_Name;
    string l_Name;
    string email;
    int age;
    double days[daysArraySize];
    DegreeProgram degreeProgram;
    
public:
Student();
Student(string studentID, string f_Name, string l_Name, string email, int age, double days[], DegreeProgram degreeProgram);
~Student();

//getters

    string getID();
    string getF_name();
    string getL_name();
    string getEmail();
    int getAge();
    double* getDays();
    DegreeProgram getDegreeProgram();
    
//setters
    void setID (string ID);
    void setF_name(string f_Name);
    void setL_name(string l_Name);
    void setEmail(string email);
    void setAge(int age);
    void setDays(double days[]);
    void setDegreeProgram(DegreeProgram dp);
    
    
    
    void print();
};
    
