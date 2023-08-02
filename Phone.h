#ifndef _PHONE_H
#define _PHONE_H
#include <string>
#include <iostream>


using namespace std;

class Fan;
class Phone{
    public:
        Fan *fanptr;
        Phone(string phonenum,string area_code, Fan* fanptr);
        Phone(string phonenum,string area_code);
        Phone();
        string GetData();
        string phonenum;
        string area_code;
        string getAreacode();
        Fan get_pointer();
        void set_pointer(Fan* fan);
        string getphonenum() const;
        bool operator==(const Phone &rhs) const;

        friend bool operator > (const Phone& rhs, const Phone& lhs){
            return rhs.getphonenum()>lhs.getphonenum();
        }
        friend bool operator < (const Phone& rhs, const Phone& lhs){
            return rhs.getphonenum()<lhs.getphonenum();
        }
        
       friend ostream& operator<<(ostream& os, const Phone& dt){
            os << dt.getphonenum()<<endl;
            return os;
        } 
};

#endif