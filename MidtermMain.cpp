//Step 6: Client Program
#include <iostream>
#include <string>

using namespace std;

#include "CourseSchedule.h"

int main() 
{
    char userChoice;

    string userName;
    string semesterName;
    string courseName;
    string courseNumber;
    double courseNumberOfUnits;
    string meetingDays;
    Time startTime;
    Time endTime;
    Date startDate;
    Date endDate;
    int maximumNumberOfClasses;

    cout << "Please enter your name: ";
    getline(cin, userName);
    cout << "PLease enter the semester name: ";
    getline(cin, semesterName);
    cout << "Please enter the start date (in this format mo/day/yr): ";
    cin >> startDate;
    cout << "Please enter the end date (in this format mo/day/yr): ";
    cin >> endDate;
    cout << "Please enter the maximum number of classes you would like to have: ";
    cin >> maximumNumberOfClasses;

    Semester semester(semesterName, startDate, endDate);
    CourseSchedule studentCourseSchedule(userName, semester, maximumNumberOfClasses);

    do 
    {
        cout << "COURSE ENTRY MENU FOR: " << semester << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "1) Enter a new course" << endl;
        cout << "2) Remove a course" << endl;
        cout << "3) Print a Semester Schedule" << endl;
        cout << "q) Quit the program" << endl;
        cin >> userChoice;
        cin.ignore();

        switch (userChoice) 
        {
            case '1':
            {
                if (studentCourseSchedule.getNumCourses() == maximumNumberOfClasses)
                {
                    cout << endl << "The class schedule is full. Please remove a class to make room to add a desired class." << endl;
                    break;
                }

                cout << "Please enter the course number: ";
                    getline(cin, courseNumber);
                cout << "Please enter the course name: ";
                    getline(cin, courseName);
                cout << "Please enter the number of units for the course: ";
                    cin >> courseNumberOfUnits;
                    cin.ignore();
                cout << "Please enter the class meeting days: ";
                    getline(cin, meetingDays);
                cout << "Please enter the class starting time (in this format hour:minute AM/PM): ";
                    cin >> startTime;
                cout << "Please enter the class ending time (in this format hour:minute AM/PM): ";
                    cin >> endTime;
                cout << "Please enter the class start date (in this format mo/day/yr): ";
                    cin >> startDate;
                cout << "Please enter the class end date (in this format moh/day/yr): ";
                    cin >> endDate;

                Course course(courseNumber, courseName, meetingDays, courseNumberOfUnits, startDate, endDate, startTime, endTime);

                if (studentCourseSchedule.addCourse(course))
                {
                    cout << "Course has been added." << endl;
                }
                else
                {
                    cout << "That input was invalid" << endl;
                }
                break;
            }
            case '2':
            {
                if (studentCourseSchedule.getNumCourses() == 0)
                {
                    cout << "\nThere are no courses to remove.\n";
                    break;
                }
                    cout << "Please enter the course number: ";
                    getline(cin, courseNumber);
                    cout << "Please enter the course name: ";
                    getline(cin, courseName);

                    Course course(courseNumber, courseName);

                if (studentCourseSchedule.removeCourse(course)) 
                {
                    cout << "Course has been removed." << endl;
                }
                else 
                {
                    cout << "That input was invalid." << endl;
                }
                break;
            }
            case '3':
            {
                cout << studentCourseSchedule;
                break;
            }
            case 'Q':
            {
                cout << "Thank you for using our course entry menu!" << endl;
                break;
            }
            case 'q':
            {
                cout << "Thank you for using our course entry menu!" << endl;
                break;
            }
            default:
            {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    }while (toupper(userChoice) != ('Q') || userChoice != ('q'));

    //system("PAUSE");
    //return 0;
}