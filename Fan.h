#ifndef _FAN_H
#define _FAN_H
#include <string>
#include <iostream>
#include "Phone.h"
#include "Email.h"

using namespace std;


class Fan{
    public:
        Fan(string lastname, string firstname, Phone& phonenum,Email& email, int seat, int concessions);
        Fan();
        string lastname;
        string firstname;
        Email email; 
        Phone phonenum; 
        int seat;
        int concessions;
        string getEmail() const;
        string getphonenum() const;
        string getlastname();
        string getfirstname();
        int getSeat();
        int getconcession();
        void setConces(Fan& fan,int dolar);
        friend ostream& operator<<(ostream& os, const Fan& dt);
        bool operator==(const Fan& rhs) const;
        bool operator!=(const Fan& rhs) const;
        int operator + (const Fan&) const;
};

#endif