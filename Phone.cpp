#include "Phone.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Fan.h"



using namespace std;


Phone::Phone(string phonenum,string area_code,Fan* fanptr){
    this->phonenum= phonenum;
    this->area_code = area_code;
    this->fanptr = fanptr;
}

Phone::Phone(string phonenum, string area_code){
    this->phonenum= phonenum;
    this->area_code = area_code;
    this->fanptr = nullptr;

}

Phone::Phone(){
    this->phonenum="";
    this->area_code ="";
    this->fanptr = nullptr;
}

Fan Phone::get_pointer(){
    return *fanptr;
}



void Phone::set_pointer(Fan* fan){
    fanptr=fan;

}

string Phone:: getAreacode(){
    return this->area_code;
}

string Phone :: getphonenum() const{
    return this->phonenum;
}


bool Phone::operator==(const Phone &rhs) const{
    return phonenum==rhs.phonenum and area_code==rhs.area_code ;
}

string Phone::GetData() {
    return this->phonenum;
}




