//Step 3: Course Class Implementation (.cpp file) with const member functions
#include <iostream>
#include <iomanip>

using namespace std;

#include "Course.h"

//1. Course user-based default constructor with 8 arguments
//Course user-based default constructor with a member initiazation list.
Course::Course(const string& cNumber, const string& cName, const string& cDays, const double cUnits, const Date& dStart, const Date& dEnd, const Time& tStart, const Time& tEnd) :
    courseNumber(cNumber), courseName(cName), courseDays(cDays), courseUnits(cUnits), startDate(dStart), endDate(dEnd), startTime(tStart), endTime(tEnd)
{

}

//2. Create a destructor that prints a message saying a course has been deleted.
Course::~Course()
{
    cout << "This course has been deleted.\n";
}

//set functions - not const since they modify private data
//5. Create set functions that ALLOW CASCADING for the following member variables: the course number, the course name, the course meeting days, an the number of units the course is worth.
//6. Create set functions for the following the 4 Date and Time member variables 
//setCourseNumber function is now set up to enable cascading
Course &Course::setCourseNumber(const string& num)
{
    courseNumber = num;
    return *this;
}

//setCourseName function is now set up to enable cascading
Course &Course::setCourseName(const string& name)
{
    courseName = name;
    return *this;
}

//setCourseDays function is now set up to enable cascading
Course &Course::setCourseDays(const string& days)
{
    courseDays = days;
    return *this;
}

//setCourseUnits function is now set up to enable cascading
Course &Course::setCourseUnits(const double units)
{
    courseUnits = units;
    return *this;
}

//get functions - (normally always declared const)
//3. Create get functions for the following member variables: the course number, the course name, the course meeting days, an the number of units the course is worth.
string Course::getCourseNumber() const
{
    return courseNumber;
}

string Course::getCourseName() const
{
    return courseName;
}

string Course::getCourseDays() const
{
    return courseDays;
}

double Course::getCourseUnits() const
{
    return courseUnits;
}

//4. Create get functions for the following the 4 Date and Time member variables 
Time Course::getCourseStartTime() const
{
    return startTime;
}

Time Course::getCourseEndTime() const
{
    return endTime;
}

Date Course::getCourseStartDate() const
{
    return startDate;
}

Date Course::getCourseEndDate() const
{
    return endDate;
}

//8. Create a function namesd calcDailyDuration which calculates the hours the student will be in the class for one daily class meeting.
double Course::calcDailyDuration() const
{
    double dailyDur;
    dailyDur = getCourseStartTime() - getCourseEndTime();
    return dailyDur;
}

//7. Overload the << operator for this class.
//overloaded stream insertion operator << is now set up to enable cascading for class Course
//as shown by ostream &operator<<(ostream& output, const Course& course) and returning
//output
ostream &operator <<(ostream& output, const Course& course)
{
    output << setw(16) << setfill(' ') << left << "Course Info:" << course.courseNumber << " -- " << course.courseName << endl
        << setw(16) << left << "# of Units:" << course.courseUnits << endl
        << setw(16) << left << "Course Dates:" << course.startDate << " - " << course.endDate << endl
        << setw(16) << setfill(' ') << left << "Meeting Days:" << course.courseDays << endl
        << setw(16) << setfill(' ') << left << "Meeting Time:" << course.startTime << " - " << course.endTime << endl
        << setw(16) << setfill(' ') << left << "Daily Duration:" << course.calcDailyDuration() << " hours" << endl;
    return output;
}