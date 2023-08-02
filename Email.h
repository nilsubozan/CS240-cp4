#ifndef _EMAIL_H
#define _EMAIL_H
#include <string>
#include <iostream>

using namespace std;

class Fan;
class Email{
    public:
        Fan *fanptr2;
        Email(string email, string name, Fan* fanptr);
        Email(string email, string name);
        Email();
        void set_pointer(Fan* fan);
        Fan get_pointer();
        string GetData();
        string email;
        string name;
        string getemailName() ;
        string getEmail() const;
        bool operator==(const Email &rhs) const;

        friend bool operator > (const Email& rhs, const Email& lhs){
            return rhs.getEmail()>lhs.getEmail();
        }

        friend bool operator < (const Email& rhs, const Email& lhs){
            return rhs.getEmail()<lhs.getEmail();
        }
        
        friend ostream& operator<<(ostream& os, const Email& dt);
         
        
};

#endif