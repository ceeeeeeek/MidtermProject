//Step 2: Date Class Definition/Header (.h file) with const member functions.
//1. Remove the print function and all occurences of it Also remove any printing done in the constructor and remove the destructor.
#ifndef DATE_H
#define DATE_H

class Date
{
    //3.Overload the << operator for this Date class.
    //4. Overload the >> operator for this Date class.
    friend ostream &operator<<(ostream&, const Date&);
    friend istream &operator>>(istream&, Date&);

    private:
        int month; //1-12
        int day; //1-31 depending on month
        int year; //any year

        //utility function to check if day is proper for month and year
        int checkDay(int) const;

    public:
        //Date user-created default constructor
        Date(int = 1, int = 1, int = 1990);

        //set functions - not const since they modify private data
        //The & return type enables cascading
        //2. Add get and set functions for all the member variables.
        //utility function with 3 int arguments/parameters: setMonth, setDay, setYear
        void setDate(int, int, int);
        //setMonth, setDay, setYear are the 3 int arguments/parameters in setDate
        Date &setMonth(int);
        Date &setDay(int);
        Date &setYear(int);

        //get functions - (normally always declared const)
        int getMonth() const;
        int getDay() const;
        int getYear() const;

        //5. Overload the >, <, >=, <=, ==, and != operators for this Date class.
        //overloaded operator(s)
        bool operator>(const Date&) const;
        bool operator<(const Date&) const;
        bool operator>=(const Date&) const;
        bool operator<=(const Date&) const;
        bool operator==(const Date&) const;
        bool operator!=(const Date&) const;
};

#endif
