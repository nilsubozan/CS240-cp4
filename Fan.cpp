#include <iostream>
#include <string>
#include <fstream>
#include "Fan.h"
#include "Phone.h"
#include "Email.h"

using namespace std;

 Fan ::Fan(string lastname, string firstname, Phone& phonenum, Email& email, int seat, int concessions){
    this->lastname = lastname;
    this->firstname= firstname;
	this->phonenum = phonenum;
    this->email = email;
    this->seat = seat;
    this->concessions=concessions;

}
Fan::Fan() {
    this->lastname = "";
    this->firstname= "";
	this->phonenum = Phone();
    this->email =Email();
    this->seat = 0;
    this->concessions = 0;

}

void setConces(Fan& fp,int dolar){
    fp.concessions=dolar;
}


string Fan ::getEmail() const{
    return email.getEmail();
}

string Fan :: getphonenum() const {
    return phonenum.getphonenum();
}

string Fan::getlastname(){
    return this->lastname;
}

string Fan::getfirstname(){
    return this->firstname;
}

int Fan::getSeat(){
    return this->seat;
}

int Fan::getconcession(){
    return this->concessions;
}




ostream& operator<<(ostream& os, const Fan& dt)
{
    os << dt.lastname <<" " << dt.firstname <<" " << dt.getphonenum()<<" " << dt.getEmail() <<" "<< dt.seat<<" "<< dt.concessions;
    return os;
}


bool Fan::operator==(const Fan &rhs) const{
    return lastname==rhs.lastname and firstname==rhs.firstname and phonenum==rhs.phonenum and email==rhs.email and seat==rhs.seat and concessions==rhs.concessions;
}

int Fan:: operator + (const Fan& c) const{
    return (c.concessions +this->concessions);

}


bool Fan::operator!=(const Fan &rhs) const{
    return !(lastname==rhs.lastname and firstname==rhs.firstname and phonenum==rhs.phonenum and email==rhs.email and seat==rhs.seat and concessions==rhs.concessions);
}






