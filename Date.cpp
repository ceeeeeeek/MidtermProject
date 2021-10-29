//Step 2: Date Class Implementation (.cpp file) with const member functions
#include <iostream>
#include <iomanip>
using namespace std;

#include "Date.h"

//Date user-created default constructor
Date::Date(int mn, int dy, int yr)
{
    setDate(mn, dy, yr);
}

//utility function with 3 int arguments/parameters: setMonth, setDay, setYear
void Date::setDate(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= 12)
    {
        month = mn;
    }

    else
    {
        month = 1;
        cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
    }

    year = yr;  //could also validate year

    day = checkDay(dy);  //to validate the day

    cout << endl;
}

//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (testDay > 0 && testDay <= daysPerMonth[month])
    {
        return testDay;
    }

    //determine whether testDay is valid for a specific month
    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    {
        return testDay;
    }

    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}

//set functions - not const since they modify private data
//setYear function is now set up to enable cascading
Date &Date::setYear(int yr) 
{
    year = (yr > 0) ? yr : 0;
    return *this;
}

//setMonth function is now set up to enable cascading
Date &Date::setMonth(int mn) 
{
    month = (mn <= 1 || mn <= 12) ? mn : 0; //not month = (mn >= 1 || mn <= 12) ? mn : 0; ?? mn >= 1?
    return *this;
}

//setDay function is now set up to enable cascading
Date &Date::setDay(int dy) 
{
    day = dy;
    return *this;
}

//get functions - not const since they modify private data
int Date::getDay() const 
{
    return day;
}

int Date::getMonth() const 
{
    return month;
}

int Date::getYear() const 
{
    return year;
}

//3.Overload the << operator for this Date class.
//overloaded stream insertion operator << is now set up to enable cascading for class Date
//as shown by ostream &operator <<(ostream &output, const Time &time1) and returning
//output
ostream &operator <<(ostream& output, const Date& date1)
{
    output << setw(2) << setfill('0') << date1.month << '/' << setw(2) << date1.day << '/' << date1.year;      
    return output;
}

//4. Overload the >> operator for this Date class.
//overloaded stream extraction operator >> is now set up to enable cascading for class Date
//as shown by istream &operator >>(istream &input, Time &time1) and returning
//time1.standardTimeToUniversal(hr, min, meridiem); and time1.standardTimeToUniversal(hr, min, meridiem);
//and input;
istream &operator >>(istream& input, Date& date1)
{
    input >> setw(2) >> date1.month;
    input.ignore();
    input >> setw(2) >> date1.day;
    input.ignore();
    input >> setw(4) >> date1.year;
    return input;
}

//5. Overload the >, <, >=, <=, ==, and != operators for this Date class.
//6 overloaded operators
//overloaded operator #1 >
bool Date::operator>(const Date& instance) const 
{
    if (year > instance.year) 
    {
        return true;
    }
    else if (year == instance.year && month > instance.month)
    {
        return true;
    }
    else if (year == instance.year && month == instance.month && day > instance.day) 
    {
        return true;
    }
    return false;
}

//overloaded operator #2 <
bool Date::operator<(const Date& instance) const 
{
    if (year < instance.year) 
    {
        return true;
    }
    else if (year == instance.year && month < instance.month) 
    {
        return true;
    }
    else if (year == instance.year && month == instance.month && day < instance.day) 
    {
        return true;
    }
    return false;
}

//overloaded operator #3 >=
bool Date::operator>=(const Date& instance) const 
{
    return (operator>(instance) || operator==(instance));
}

//overloaded operator #4 <=
bool Date::operator<=(const Date& instance) const 
{
    return (operator<(instance) || operator==(instance));
}

//overloaded operator #5 ==
bool Date::operator==(const Date& instance) const 
{
    return (month == instance.month && day == instance.day && year == instance.year);
}

//overloaded operator #6 !=
bool Date::operator!=(const Date& instance) const 
{
    return (operator==(instance) == false);
}