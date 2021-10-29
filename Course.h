//Step 3: Course Class Definition/Header (.h file) with const member functions
#ifndef COURSE_H
#define COURSE_H

#include "Date.h"
#include "Time.h"

class Course
{
    //7. Overload the << operator for this class.
    friend ostream &operator<<(ostream&, const Course&);

    private:
        string courseNumber; //A course number
        string courseName; //A course name
        string courseDays; //A variable for the course meeting days
        double courseUnits; //A variable representing the number of units the course is worth.
        Date startDate; //A Date object for the state date of the class.
        Date endDate; //A Date object for the end date of the class.
        Time startTime; //A Time object for the start time of the class.
        Time endTime; //A Time object for the end time of the class.

    public:
        //1. Course user-based default constructor with 8 arguments
        Course(const string & = " ", const string & = " ", const string & = " ",
            const double = 0, const Date & = Date(), const Date & = Date(), const Time & = Time(),
            const Time & = Time());

        //2. Create a destructor that prints a message saying a course has been deleted.
        //Course Destructor
        ~Course();

        //set functions - not const since they modify private data
        //The & return type enables cascading
        //5. Create set functions that ALLOW CASCADING for the following member variables: the course number, the course name, the course meeting days, an the number of units the course is worth.
        //6. Create set functions for the following the 4 Date and Time member variables 
        Course &setCourseNumber(const string&);
        Course &setCourseName(const string&);
        Course &setCourseDays(const string&);
        Course &setCourseUnits(const double);

        //get functions - (normally always declared const)
        //3. Create get functions for the following member variables: the course number, the course name, the course meeting days, an the number of units the course is worth.
        string getCourseNumber() const;
        string getCourseName() const;
        string getCourseDays() const;
        double getCourseUnits() const;
        //4. Create get functions for the following the 4 Date and Time member variables 
        Time getCourseStartTime() const;
        Time getCourseEndTime() const;
        Date getCourseStartDate() const;
        Date getCourseEndDate() const;

        //8. Create a function namesd calcDailyDuration which calculates the hours the student will be in the class for one daily class meeting.
        double calcDailyDuration() const;
};

#endif