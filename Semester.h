//Step 4: Semester Class Definition/Header (.h file) with const member functions
#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
using namespace std;

#include "Course.h"
#include "Date.h"
#include "Time.h"


class Semester 
{
    friend ostream &operator<<(ostream&, const Semester&);
    friend istream &operator>>(istream&, Semester&);

    private:
        string semesterName; //A Semester Name
        Date startDate; //A Date instance for the start date of the semester.
        Date endDate; //A date instance for the end date of the semester. 

    public:
        //Semester user-based constructor
        Semester(const string & = " ", const Date & = Date(), const Date & = Date());

        //set functions - not const since they modify private data
        //The & return type enables cascading
        Semester &setSemesterName(string);
        Semester &setSemesterStartDate(int, int, int);
        Semester &setSemesterEndDate(int, int, int);

        //get functions - (normally always declared const)
        string getSemesterName() const;
        Date getSemesterStartDate() const;
        Date getSemesterEndDate() const;
};
#endif