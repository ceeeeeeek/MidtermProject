//Step 1: Time Class Definition/Header (.h file) with const member functions.
//1. Remove the "seconds" member variable. You will need to remove the corresponding member functions and any functions where "seconds" was used as a parameter.
#ifndef TIME_H
#define TIME_H

class Time
{
    //3.Overload the << operator for this Time class.
    //4. Overload the >> operator for this Time class.
    friend ostream &operator<<(ostream&, const Time&);
    friend istream &operator>>(istream&, Time&);

    private:
        void standardTimeToUniversal(int, int, string);
        int hour;  //0-23 (24 hour clock format)
        int minute; //0-59
    
    public:
        //Time user-based default constructor
        Time(int = 0, int = 0);

        //set functions - not const since they modify private data
        //The & return type enables cascading
        //2. Create a utility function that convertts standard time to universal time.
        //utility function with 2 int parameters/arguments: setHour and setMinute.
        Time &setTime(int, int);
        //setHour and setMinute are the 2 int parameters/arguments in setTime
        Time &setHour(int);
        Time &setMinute(int);

        //get functions - (normally always declared const)
        int getHour() const;
        int getMinute() const;

        //print functions - (normally always declared const since they do not modify private members, merely inspect
        void printUniversal() const;
        void printStandard()const;

        //5. Overload the - (subtraction) operator.
        //overloaded operator(s)
        double operator-(const Time&);
};

#endif

