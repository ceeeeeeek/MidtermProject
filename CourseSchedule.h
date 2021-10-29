//Step 5: CourseSchedule Class Definition/Header (.h file) with const member functions
#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H

#include "Date.h"
#include "Time.h"
#include "Course.h"
#include "Semester.h"

using namespace std;

class CourseSchedule
{
    //7. Overload the << operator for this class.
    friend ostream &operator<<(ostream&, const CourseSchedule&);

    private:
        string studentName; //A student name (the name of the student this schedule if for)
        Semester semester; //A Semester object
        Course *coursePointer; //A pointer to a Course.
        int maxSize; //A maxSize variable that indicates the maximum number of courses that can be added to this student schedule (the array of Courses)
        int numCourses;   // A numCourses variable that keeps track of how many courses have been added to the student schedule. (the aray of Courses)
        bool checkDates(const Semester&, const Date&, const Date&) const; //5. Create a utility functions named checkDates that takes three arguments: a Semester instance, a beginning course 
                                                                          //Date instance and an ending course Date instance. The function should check to make sure the start date of the class
                                                                          //and/or the end date of the class are not outside the Semester Dates.

    public:
        //1. CourseSchedule user-based default constructor with 3 arguments
        CourseSchedule(const string & = "Student Name", const Semester & = Semester(), int = 0);
        CourseSchedule(const CourseSchedule &); //CourseSchedule copy constructor prototype

        //2. Create a destructor that de-allocates memory appropriately when a CourseSchedule is destroyed.
        ~CourseSchedule();

        //4. Create set functions for the following member variables: the student name
        //set functions - not const since they modify private data
        void setStudentName(string);

        //3.Create get functions for the following member variables: the student name, the Semseter, and the number of courses.
        //get functions - (normally always declared const)
        string getStudentName() const;
        Semester getSemesterName() const;
        int getNumCourses() const;

        bool addCourse(const Course&); //6. Create a function named AddCourse that takes a Course as an argument and adds the course to the ClassSchedule array.
        bool removeCourse(const Course&); //8. Create a function called reomveCourse that allows the user to delete a course from their schedule.
};

#endif

