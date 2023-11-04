#include "student.h"
#include <string>
using std::string;
using std::cout;
using namespace std;

Student::Student()
{
    this->studentID =""; 
    this ->f_Name ="";
    this->l_Name ="";
    this->email ="";
    this->age =0;
    for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string f_Name, string l_Name, string email, int age,  double days[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this ->f_Name = f_Name;
    this->l_Name = l_Name;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {}     
    
string Student::getID() {return this->studentID; }
string Student::getF_name() {return this ->f_Name; }
string Student::getL_name() {return this->l_Name; }
string Student::getEmail() {return this->email; }
int    Student::getAge() {return this->age; }
double* Student::getDays() {return this ->days; }
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setF_name(string f_Name) { this ->f_Name = f_Name; }
void Student::setL_name(string l_Name) { this->l_Name = l_Name; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(double days[]) 
{
    for (int i = 0; i < daysArraySize; i++ ) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }



void Student::print()
{
    cout << this->getID() << '\t';
    cout << this->getF_name() << '\t';
    cout << this->getL_name() << '\t';
    cout << this->getAge() << '\t' << '{';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '}' << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
};
