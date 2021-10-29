//Step 1: Time Class Implementation(.cpp file) with const member functions
//1. Remove the "seconds" member variable. You will need to remove the corresponding member functions and any functions where "seconds" was used as a parameter.
#include <iostream>
#include <iomanip>
using namespace std;

#include "Time.h"

//Time user-based default constructor
//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do 
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute)
{
    setTime(hour, minute);
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/
//2. Create a utility function that convertts standard time to universal time.
//utility function with 2 int parameters/arguments: setHour and setMinute
//setTime function now is set up to enable cascading
Time &Time::setTime(int hour, int minute)
{
    setHour(hour);
    setMinute(minute);
    return *this;
}

//setHour function is now set up to enable cascading
Time &Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
    return *this;
}

//setMinute function is now set up to enable cascading
Time &Time::setMinute(int m)
{
    minute = (m >= 0 && m < 24) ? m : 0;  //validates minute, if valid set to m, else set to 0
    return *this;
}

/*GET FUNCTIONS:  Do not modify private member data normally always const*/
//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/
void Time::printUniversal() const  //must be const since prototype is const
{
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << endl;
}

void Time::printStandard() const  //must be const since prototype is const
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << setfill('0') << setw(2) << minute << ":"
        << setw(2) << (hour < 12 ? "AM" : "PM") << endl;
}

//private utility function to convert standard time to universal
void Time::standardTimeToUniversal(int hr, int min, string meridiem)
{
    if (hr == 12)
    {
        hr = 0;
    }
    if (meridiem == "AM")
    {
        setTime(hr, min);
    }
    else if (meridiem == "PM")
    {
        setTime(hr + 12, min);
    }
}

//3.Overload the << operator for this Time class.
//overloaded stream insertion operator << is now set up to enable cascading for class Time
//as shown by ostream &operator <<(ostream &output, const Time &time1) and returning
//output.
ostream &operator <<(ostream& output, const Time& time1)
{
    int hr = time1.hour;
    int min = time1.minute;
    output << ((hr == 0 || hr == 12) ? 12 : hr % 12) << ":"
        << setfill('0') << setw(2) << min << " " << (hr < 12 ? "AM" : "PM");

    return output;
}

//4. Overload the >> operator for this Time class.
//overloaded stream extraction operator >> is now set up to enable cascading for class Time
//as shown by istream &operator >>(istream &input, Time &time1) and returning
//input.
istream &operator >>(istream& input, Time& time1)
{
    int hr, min;
    string meridiem;
    input >> setw(2) >> hr;
    input.ignore();
    input >> setw(2) >> min;
    input.ignore();
    input >> setw(2) >> meridiem;
    if (meridiem == "AM" || meridiem == "am")
    {
        time1.standardTimeToUniversal(hr, min, meridiem);
    }
    else if (meridiem == "PM" || meridiem == "pm")
    {
        time1.standardTimeToUniversal(hr, min, meridiem);
    }
    return input;
}

//5. Overload the - (subtraction) operator.
//overloaded operator(s) taking two Time instances double and minute and caluclating the hours and mintues between them.
double Time::operator-(const Time &instance)
{
    double timeDifference;
    timeDifference = double(hour) + double(minute) / 60.00 - double(instance.hour) - double(instance.minute) / 60.00;
    return timeDifference;
}
