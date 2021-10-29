//Step 4: Semester Class Implementation (.cppS file) with const member functions
#include <iostream>
#include <iomanip>

using namespace std;

#include "Semester.h"

//Semester user-based default constructor
Semester::Semester(const string& nm, const Date& start, const Date& end) : semesterName(nm), startDate(start), endDate(end)
{

}

//set functions
//setName function is now set up to enable cascading
Semester &Semester::setSemesterName(string nm)
{
    semesterName = nm;
    return *this;
}

//setStartDate function is now set up to enable cascading
Semester &Semester::setSemesterStartDate(int month, int day, int year) 
{
    //cout << "(";
    startDate.setMonth(month);
    startDate.setDay(day);
    startDate.setYear(year);
    
    return *this;
}

//setEndDate function is now set up to enable cascading
Semester &Semester::setSemesterEndDate(int month, int day, int year) 
{
    endDate.setMonth(month);
    endDate.setDay(day);
    endDate.setYear(year);
    //cout << ")";
    return *this;
}

string Semester::getSemesterName() const 
{
    return semesterName;
}

Date Semester::getSemesterStartDate() const 
{
    return startDate;
}

Date Semester::getSemesterEndDate() const 
{
    return endDate;
}

//overloaded stream insertion operator << is now set up to enable cascading for class Semester
//as shown by ostream &operator<<(ostream& output, const Semester& sem) and returning
//output
ostream &operator <<(ostream& output, const Semester& sem)
{
    output << "Semester: " << sem.semesterName << " "
        << " (" << sem.startDate << "-" << sem.endDate << ")";
    return output;
}

//overloaded stream extraction operator >> is now set up to enable cascading for class Semeseter
//as shown by istream &operator>>(istream& input, Semester& sem) and returning
//input
istream &operator >>(istream& input, Semester& sem)
{
    input >> sem.semesterName;
    input.ignore(2); //ignores " ("
    input >> sem.startDate;
    input.ignore(); //ignores "-"
    input >> sem.endDate;
    return input;
}
