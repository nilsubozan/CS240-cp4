#include "Email.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Fan.h"


using namespace std;

Email ::Email(string email,string name, Fan* fanptr2){
    this->email = email;
    this->name = name;
    this->fanptr2=fanptr2;
}

Email::Email(string email, string name){
    this->email=email;
    this->name = name;
    this->fanptr2 = nullptr;
}

void Email::set_pointer(Fan* fan){
    fanptr2=fan;
}

Email :: Email(){
    this->email="";
    this->name="";
    this->fanptr2=nullptr;
}

string Email:: getemailName(){
    return this->name;
}

Fan Email::get_pointer(){
    return *fanptr2;
}

string Email::getEmail() const{
    return this->email;
}

bool Email::operator==(const Email &rhs) const{
    return email==rhs.email and name==rhs.name ;
}

string Email::GetData() {
    return this->email;
}

ostream& operator<<(ostream& os, const Email& dt)
{
    os << dt.getEmail()<<" "<<endl;
    return os;
}