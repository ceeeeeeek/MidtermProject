//Step 5: CourseSchedule Class Implementaion (.cpp file) with const member functions
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "CourseSchedule.h"

//1. CourseSchedule user-based default constructor with 3 arguments
//CourseSchedule user-based default constructor with a member initiazation list.
CourseSchedule::CourseSchedule(const string& studentName, const Semester& s, int maxSize) : coursePointer(nullptr), studentName(studentName), semester(s), maxSize(maxSize), numCourses(0)
{
    coursePointer = new Course[maxSize]; //Create space for pointer-based array
}

//CourseSchedule copy constructor
CourseSchedule::CourseSchedule(const CourseSchedule&) : coursePointer(nullptr), studentName(" "), maxSize(0), numCourses(0)
{

}

//2. Create a destructor that de-allocates memory appropriately when a CourseSchedule is destroyed.
CourseSchedule::~CourseSchedule()
{
    delete[] coursePointer;
    //coursePointer = nullptr;
}

//4. Create set functions for the following member variables: the student name. 
//Once the other member variables are set once the user should not be allowed to reset them.
//set functions - not const since they modify private data
void CourseSchedule::setStudentName(string studentName)
{
    this->studentName = studentName;
}

//3. Create get functions for the following following member variables: the student name, the Semester, and the number of courses.
//get functions - (normally always declared const)
string CourseSchedule::getStudentName() const
{
    return studentName;
}


Semester CourseSchedule::getSemesterName() const
{
    return semester;
}


int CourseSchedule::getNumCourses() const
{
    return numCourses;
}

//5. Create a utility functions named checkDates that takes three arguments: a Semester instance, a beginning course 
//Date instance and an ending course Date instance. The function should check to make sure the start date of the class
//and/or the end date of the class are not outside the Semester Dates.
bool CourseSchedule::checkDates(const Semester& courseDate, const Date& startSemesterDate, const Date& endSemesterDate) const
{
    if (courseDate.getSemesterStartDate() > startSemesterDate)
    {
        return false;
    }
    else if (courseDate.getSemesterEndDate() < endSemesterDate)
    {
        return false;
    }
    else
    {
        return true;
    }
}


bool CourseSchedule::addCourse(const Course& course)
{
    if (numCourses < maxSize)
    {
        if (checkDates(semester, course.getCourseStartDate(), course.getCourseEndDate()))
        {
            for (int count = 0; count < numCourses; count++)
            {
                if (coursePointer[count].getCourseNumber() == course.getCourseNumber() &&
                    coursePointer[count].getCourseName() == course.getCourseName())
                {
                    return false; // if the course is already on the schedule, return false so it can't add the same course more than once.
                }
            }
            coursePointer[numCourses] = course;
            numCourses++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}


bool CourseSchedule::removeCourse(const Course& course)
{
    if (numCourses > 0)
    {
        int index = -1;
        for (int count = 0; count < numCourses; count++)
        {
            if (coursePointer[count].getCourseNumber() == course.getCourseNumber() &&
                coursePointer[count].getCourseName() == course.getCourseName())
            {
                index = count;
            }
        }
        if (index != -1)
        {
            coursePointer[index] = coursePointer[numCourses - 1];
            numCourses--;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//overloaded stream insertion operator << is now set up to enable cascading for class CourseSchedule
//as shown by ostream &operator<<(ostream& output, const CourseSchedule& schedule1) and returning
//output
ostream &operator <<(ostream& output, const CourseSchedule& schedule1)
{
    output << "\n\nCLASS SCHEDULE\n"
        << "------------------------------------------\n"
        << "Name: " << schedule1.getStudentName() << endl
        << "Semester: " << schedule1.getSemesterName() << "(" << "______" << ")" << endl
        << "Number of Classes: " << schedule1.numCourses << endl
        << "------------------------------------------\n";
    for (int count = 0; count < schedule1.numCourses; count++)
    {
        cout << schedule1.coursePointer[count] << "\n\n";
    }
    return output;
}

//overloaded operator(s)
//void CourseSchedule::operator=(const CourseSchedule&) const
//{

//}