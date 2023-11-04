
#include <iostream>
#include "roster.h"
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

int main()
{
    
    cout << "Language: C++" << std::endl;
    cout << "Created by: David Krupar\n" << std::endl;
    
    const string studentData[] = 
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
    "A5,David,Krupar,dkrupar@my.wgu.edu,35,53,30,55,SOFTWARE", 
    };
    
    const int numStudents = 5;
    Roster classRoster;
    
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << std:: endl;
    classRoster.printAll();
    cout << std::endl;
    
    cout << "Displaying invalid emails:\n" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    
    for (int i = 0; i< numStudents; i++) classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i] -> getID());
    
  
    
        cout << "\nShowing students in degree program: SOFTWARE \n" <<  std::endl;
        classRoster.printByDegreeProgram(SOFTWARE);
    
    
    
    
    cout << "Removing A3:";
    classRoster.remove("A3");
    cout << std::endl;
    
    classRoster.printAll();
    
    cout << "\nRemoving A3 again\n" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    
    return 0;
    
}
