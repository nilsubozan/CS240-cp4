#include <iostream>
#include <string>
#include <fstream>
#include "fans.h"
#include <unistd.h>
#include <ctype.h>
#include <cctype>
#include "Fan.h"
#include "Phone.h"
#include "Email.h"
#include <vector>
#include "LinkedList.h"
#include "BST.cpp"


using namespace std;
BinaryTree <Email> treemail;
BinaryTree <Phone> treephone;
LinkedList a;
ofstream outputfile;


int LastNameCheck(string lstnm){
    int isCapital=0;
    int isLetter=1;
    if(isupper(lstnm[0])){
        isCapital=1;                    
    }
    for(int i=0;i<lstnm.length();i++){
        if(!isalpha(lstnm[i])){
            isLetter=0;
                                
        }
    }
    if(isCapital==0 || isLetter==0){
        return 0;
    }
    else{
        return 1;
    }
}

int FirstNameCheck(string firstname){
    int isCapital2=0;
    int isLetter2=1;
    if(isupper(firstname[0])){
        isCapital2=1;
    }
    //checks the charcters in firstname
    for(int i=0; i<firstname.length();i++){
        if(!isalpha(firstname[i])){
            isLetter2=0;
        }
    }
    if(isCapital2==0 || isLetter2==0){
        return 0;
    }
    else{
        return 1;
    }


}

bool PhoneCheck(string phn){
    bool isTrueformat= true;
                        
    for(int i=0; i<phn.length();i++){
        if(i==0){
            if(phn[0]!='('){
                isTrueformat=false;
            }
        }
        if(i==4){
            if(phn[4]!=')'){
                isTrueformat=false;
            }
        }
        if(i==8){
            if(phn[8]!='-'){
                isTrueformat=false;
            }
        }
        else if(i!=0 && i!=4 && i!=8){
            if(!(isdigit(phn[i]))){
                isTrueformat=false;
            }
        }
    }

    return isTrueformat;
}

bool ConcessionCheck(string conces){
    bool ist=true;
    for(int i=0; i<conces.length();i++){
        if(!(isdigit(conces[i]))){
            ist=false;
        }
    }
    return ist;
}
int isPrintible(string mail){
    int isPrint= 1;
                    
    //Is this mail printible?

    for(int i=0; i<mail.length();i++){
                            
        if(mail[i]=='@'){
            continue;
        }
        else if(!isprint(mail[i])){
            isPrint=0;
        }
    }
    return isPrint;
}

string AreaCodeCheck(string phn){
    string areacode="";
    for(int i=1; i<phn.length();i++){
        if((phn[i])==')'){
            break;
                                
        }
        else{
            areacode+=phn[i];
        }
                            
    }
    return areacode;

}

string EmailNameCheck(string mail){
    string nme="";
    //Seperate the name from email
    

    for(int i =0; i<mail.length();i++){
        if(mail[i]!='@'){
            nme+=mail[i];
        }
        else{
            break;
        }
    }
    return nme;

}

void Process(string filename) {
    fstream f;
    f.open(filename, ios::in);
    if (f.is_open()) {
        string ln;
        while (getline(f, ln)) {
            Parser pars(ln);
            if (pars.getOperation() == "Quit") {
                if(pars.numArgs()>0){
                    cout<<std::endl<<"Ignoring "<< UNEXPECTED_ARGS <<endl;
                }
                if(pars.numArgs()==0){
                    a.display(outputfile);
                }
                exit(1);
            }
            if (pars.getOperation() == "Process"){
                if(pars.numArgs()==1){
                    string fname = pars.getArg1();
                    Process(fname);
                }
                else{
                    cout<<"MISSING OR UNEXPECTED ARGS!!"<<endl;
                }
            }
            if(pars.getOperation()=="Remove"){
                continue;
            }

            if(pars.getOperation()=="Load"){
                if(pars.numArgs()==1){
                string FileName= pars.getArg1();
                fstream read;
                read.open(FileName, ios::in);
                    if(read.is_open()){
                        string line2;
                        
                        Fan fanobj3;
                        int linecount1=1;

                        while(getline(read,line2)){
                            Parser command2(line2);
                            string lstnm=command2.getOperation();
                            int resultLastName= LastNameCheck(lstnm);
                            string frstnm= command2.getArg1();
                            int resultFirstName= FirstNameCheck(frstnm);
                            string phn=command2.getArg2();
                            bool resultPhone = PhoneCheck(phn);
                            string AreaCoderesult = AreaCodeCheck(phn);
                            string mail= command2.getArg3();
                            int resultMail = isPrintible(mail);
                            string EmailNameResult = EmailNameCheck(mail);
                            bool Resultconn= ConcessionCheck(command2.getArg5());                  
                            int st= stoi(command2.getArg4());
                            int cncs=stoi(command2.getArg5());
                            Phone phnm;
                            Email mll;
                            Fan* fptt;
                        

                            bool mailsimilar3=a.searchmail(command2.getArg3());
                            bool phonesimilar3=a.searchphone(command2.getArg2());

                            if(mailsimilar3==false && phonesimilar3 ==false && resultLastName==1 && resultFirstName==1 &&resultPhone==true && resultMail==1 && Resultconn==true){
                                phnm= Phone(command2.getArg2(),AreaCoderesult,fptt);
                                mll= Email(command2.getArg3(),EmailNameResult, fptt);
                                fanobj3 = Fan(command2.getOperation(), command2.getArg1(), phnm,mll,st,cncs);
                                a.insertnode(fanobj3);
                                fptt = a.get_fan_pointer();
                                phnm.set_pointer(fptt);
                                mll.set_pointer(fptt);
                                treephone.addNode(phnm);
                                treemail.addNode(mll);
                                
                            }
                            else if(mailsimilar3!=false || phonesimilar3 !=false|| resultLastName==0 ||resultFirstName==0 || resultPhone==false || resultMail==0 ||Resultconn==false){
                                if(phonesimilar3==true)
                                    cout<<"Phone number on line "<<linecount1<<"is used before"<<endl;
                                if(mailsimilar3==true){
                                    cout<<"Mail address on line "<<linecount1<<"is used before"<<endl;
                                }
                                if(resultMail==0){
                                    cout<<"ERROR: Email is not well-formatted!!! for the number line"<<linecount1<<"fan"<<endl;
                                }
                                if(Resultconn==false){
                                    cout<<"ERROR: Concession is not numeric !!! on line "<< linecount1<<"fan"<<endl;
                                }
                                if(resultPhone==false){
                                    cout<<"ERROR: Phone number is not well-formatted!!! for the number line"<<linecount1<<" fan" <<endl;
                                }
                                if(resultLastName==0){
                                    cout<<"ERROR: Lastname is not well-formatted!!! for the number line"<<linecount1<< " fan"<<endl;
                                }
                                if(resultFirstName==0){
                                    cout<<"ERROR: Firstname is not well-formatted!!! for the number line" <<linecount1<<" fan"<<endl;
                                }
                            }
                        
                                linecount1++;
                           
                        }
                        read.close();
                    }
                    else{
                        cout << "file cannot open..." << endl;
                        exit(1);
                    }
                }
                
            }
            if(pars.getOperation()=="Show"){
                if(pars.numArgs()>1){
                    cout<<std::endl<<"Ignoring " << UNEXPECTED_ARGS << endl;
                }
                if(pars.numArgs()<1){
                    cout << std::endl << MISSING_ARGS << endl;
                }
                else{
                    string fanid= pars.getArg1();
                    int isEmail=0;
                    for(int i=0; i<fanid.length();i++){
                        if(fanid[i]=='@'){
                            isEmail=1;
                        }
                    }
                    if(isEmail==1){
                        string EmailNameResultt = EmailNameCheck(fanid);
                        Email emaill;
                        emaill= Email(pars.getArg1(),EmailNameResultt);
                        treemail.lookupShow(emaill);
                    }
                    else if(isEmail==0){
                        string AreaCoderesultt = AreaCodeCheck(fanid);
                        Phone phonee;
                        phonee = Phone(pars.getArg1(),AreaCoderesultt);
                        treephone.lookupShow(phonee);
            
                    }
            }

                
            }
            if(pars.getOperation()=="Spend"){
                continue;
            }
        }
    }
}


int main(int argc, char* argv[]){
    string line;
    string command;
    int c;
    Fan fanobj;
    //LinkedList a;
    vector <Fan> vct;
    ifstream inputfile;
    
    string oop;
    

    //BinaryTree <Email> BSTEmail;
    //BinaryTree <Phone> BSTPhone;
    //BinaryTree <Email> treemail;
    //BinaryTree <Phone> treephone;


    while((c=getopt(argc,argv, "i:o:"))!= -1){
        switch(c){
            
            case 'i':{
                oop=optarg;
                if(oop==""){
                    oop= "fans.in.txt";
                }

                inputfile.open(oop, ios::in);
                

                if(inputfile.is_open()){
                   
                    cout<<oop<<endl;
                    int linecount=1;

                    while(getline(inputfile,line)){
                      
                        Parser command(line);
                        string lstnm=command.getOperation();
                        int resultLastName= LastNameCheck(lstnm);
                        string frstnm= command.getArg1();
                        int resultFirstName= FirstNameCheck(frstnm);
                        string phn=command.getArg2();
                        bool resultPhone = PhoneCheck(phn);
                        string AreaCoderesult = AreaCodeCheck(phn);
                        string mail= command.getArg3();
                        int resultMail = isPrintible(mail);
                        string EmailNameResult = EmailNameCheck(mail);
                        bool Resultcon= ConcessionCheck(command.getArg5());                        
                        int st= stoi(command.getArg4());
                        int cncs=stoi(command.getArg5());
                        Phone phnm;
                        Email mll;
                        Fan* fpt;
                        bool mailsimilar=a.searchmail(command.getArg3());
                        bool phonesimilar=a.searchphone(command.getArg2());

                        if(mailsimilar==false && phonesimilar ==false && resultLastName==1 && resultFirstName==1 &&resultPhone==true && resultMail==1 && Resultcon==true){
                            //cout<<fpt<<endl;
                            phnm= Phone(command.getArg2(),AreaCoderesult,fpt);
                            mll= Email(command.getArg3(),EmailNameResult,fpt);
                            //cout<<fpt<<endl;

                            fanobj = Fan(command.getOperation(), command.getArg1(), phnm,mll,st,cncs);
                            a.insertnode(fanobj);
                            fpt=a.get_fan_pointer();
                            phnm.set_pointer(fpt);
                            mll.set_pointer(fpt);
                            //fpt=a.get_fan_pointer();
                            //fpt=a.get_fan_pointer();
                            treephone.addNode(phnm);
                            treemail.addNode(mll);

                        //already in the tree and can not add this line
                        }
                        else if(mailsimilar!=false || phonesimilar !=false || resultLastName==0 ||resultFirstName==0 || resultPhone==false || resultMail==0 ||Resultcon==false){
                            if(phonesimilar==true)
                                cout<<"Phone number on line "<<linecount<<"is used before"<<endl;
                            if(mailsimilar==true){
                                cout<<"Mail address on line "<<linecount<<"is used before"<<endl;
                            }
                            if(resultMail==0){
                                cout<<"ERROR: Email is not well-formatted!!! for the number line"<<linecount<<"fan"<<endl;
                            }
                            if(Resultcon==false){
                                cout<<"ERROR: Concession is not numeric !!! on line "<< linecount<<"fan"<<endl;
                            }
                            if(resultPhone==false){
                                cout<<"ERROR: Phone number is not well-formatted!!! for the number line"<<linecount<<" fan" <<endl;
                            }
                            if(resultLastName==0){
                                cout<<"ERROR: Lastname is not well-formatted!!! for the number line"<<linecount<< " fan"<<endl;
                            }
                            if(resultFirstName==0){
                                cout<<"ERROR: Firstname is not well-formatted!!! for the number line" <<linecount<<" fan"<<endl;
                            }

                        }
                        
                        linecount++;

                        
                    }
                    inputfile.close();

                    
                }
                break;
            }

            case 'o':{
                oop=optarg;
                if(oop==" "){
                    oop = "fans.out.txt";
                }
                else{
                    outputfile.open(oop);
                }
                
                break;
            }
            case '?':{
                cout<<"Unknown command: "<<c<<endl; 
                break;
            }
        }
    }

    a.display22();
    //treephone.printInOrder();
    //treemail.printInOrder();


    while(1){
       cout << endl << "Enter a command:" << endl;
       cout<<"Choose from"<<endl;
       cout <<"  [\"Show [<fan-id>]\"" << std::endl << 
	       "    \"Load [<input-filename>]\"" << std::endl << 
           "    \"Spend <fan-id> <dollars>\"" <<std::endl<<
           "    \"Remove <fan-id>\"" <<std::endl<<
           "    \"Process <commands-filename>\"" <<std::endl<<
	       "    \"Quit\"]" << endl;
       cout << ": ";
       getline(cin, line);
       Parser command(line);
       if (command.getOperation().empty()){
          if (std::cin.fail())
              break;
          continue;
       }

       if(command.getOperation() == "Quit"){
            if(command.numArgs()>0){
                cout<<std::endl<<"Ignoring "<< UNEXPECTED_ARGS <<endl;
            }
            if(command.numArgs()==0){
               a.display(outputfile);
            }
            break; 
        }
        

       if(command.getOperation() == "Show"){
           if(command.numArgs()>1){
               cout<<std::endl<<"Ignoring " << UNEXPECTED_ARGS << endl;
            }
           if(command.numArgs()<1){
               cout << std::endl << MISSING_ARGS << endl;
            }
            else{
                
                string fanid= command.getArg1();
                int isEmail=0;
                for(int i=0; i<fanid.length();i++){
                    if(fanid[i]=='@'){
                        isEmail=1;
                    }
                }
                if(isEmail==1){
                    //we should lookup the email BST
                    string EmailNameResultt = EmailNameCheck(fanid);
                    Email emaill;
                    emaill= Email(command.getArg1(),EmailNameResultt);
                    treemail.lookupShow(emaill);
                }
                else if(isEmail==0){
                    string AreaCoderesultt = AreaCodeCheck(fanid);
                    Phone phonee;
                    phonee = Phone(command.getArg1(),AreaCoderesultt);
                    treephone.lookupShow(phonee);
            
                }
            }
       }
       if(command.getOperation() == "Load"){
           cout<<command.numArgs()<<endl;
           if(command.numArgs()==1){
                string FileName= command.getArg1();
                fstream read;
                read.open(FileName, ios::in);
                if(read.is_open()){
                    string line2;
                    int nm;
                    Fan fanobj3;
                    int linecount1=1;
                    while(getline(read,line2)){
                        Parser command2(line2);
                        string lstnm=command2.getOperation();
                        int resultLastName= LastNameCheck(lstnm);
                        string frstnm= command2.getArg1();
                        int resultFirstName= FirstNameCheck(frstnm);
                        string phn=command2.getArg2();
                        bool resultPhone = PhoneCheck(phn);
                        string AreaCoderesult = AreaCodeCheck(phn);
                        string mail= command2.getArg3();
                        int resultMail = isPrintible(mail);
                        string EmailNameResult = EmailNameCheck(mail);
                        bool Resultcon2= ConcessionCheck(command2.getArg5());
                        
                        int st= stoi(command2.getArg4());
                        int cncs=stoi(command2.getArg5());
                        Phone phnm;
                        Email mll;
                        Fan* fptt;

                        bool mailsimilar2=a.searchmail(command.getArg3());
                        bool phonesimilar2=a.searchphone(command.getArg2());
                        if(mailsimilar2==false && phonesimilar2 ==false && resultLastName==1 && resultFirstName==1 &&resultPhone==true && resultMail==1 && Resultcon2==true){
                            phnm= Phone(command2.getArg2(),AreaCoderesult,fptt);
                            mll= Email(command2.getArg3(),EmailNameResult,fptt);
                            fanobj3 = Fan(command2.getOperation(), command2.getArg1(), phnm,mll,st,cncs);
                            a.insertnode(fanobj3);
                            fptt=a.get_fan_pointer();
                            phnm.set_pointer(fptt);
                            mll.set_pointer(fptt);
                            treephone.addNode(phnm);
                            treemail.addNode(mll);
                            
                        }
                        else if(mailsimilar2!=false || phonesimilar2 !=false || resultLastName==0 ||resultFirstName==0 || resultPhone==false || resultMail==0 ||Resultcon2==false){
                            if(phonesimilar2==true)
                                cout<<"Phone number on line "<<linecount1<<"is used before"<<endl;
                            if(mailsimilar2==true){
                                cout<<"Mail address on line "<<linecount1<<"is used before"<<endl;
                            }
                            if(resultMail==0){
                                cout<<"ERROR: Email is not well-formatted!!! for the number line"<<linecount1<<"fan"<<endl;
                            }
                            if(Resultcon2==false){
                                cout<<"ERROR: Concession is not numeric !!! on line "<< linecount1<<"fan"<<endl;
                            }
                            if(resultPhone==false){
                                cout<<"ERROR: Phone number is not well-formatted!!! for the number line"<<linecount1<<" fan" <<endl;
                            }
                            if(resultLastName==0){
                                cout<<"ERROR: Lastname is not well-formatted!!! for the number line"<<linecount1<< " fan"<<endl;
                            }
                            if(resultFirstName==0){
                                cout<<"ERROR: Firstname is not well-formatted!!! for the number line" <<linecount1<<" fan"<<endl;
                            }

                        }
                        
                        linecount1++;

                      
                    }
                    read.close();
                }
                else{
                    cout << "file cannot open..." << endl;
                    return 1;
                }
            }
        }

       if(command.getOperation() == "Spend"){
            if(command.numArgs() >2){
                cout<<std::endl<<"Ignoring " << UNEXPECTED_ARGS << endl;
            }
            if (command.numArgs() < 2) {
                cout << std::endl << MISSING_ARGS << endl;
            }
            else{
                continue;
                
                string fanidd= command.getArg1();
                int dollars = stoi(command.getArg2());

                int isEmail=0;
                for(int i=0; i<fanidd.length();i++){
                    if(fanidd[i]=='@'){
                        isEmail=1;
                    }
                }
                /*
                if(isEmail==1){
                    //we should lookup the email BST
                    string EmailNameResul = EmailNameCheck(fanidd);
                    Email emailobj;
                    emailobj= Email(command.getArg1(),EmailNameResul);
                    treemail.lookupConcession(emailobj,dollars);
                }
                else if(isEmail==0){
                    string AreaCoderesul = AreaCodeCheck(fanidd);
                    Phone phoneobj;
                    phoneobj = Phone(command.getArg1(),AreaCoderesul);
                    treephone.lookupConcession(phoneobj,dollars);
                    treephone.lookupConcession(phoneobj,dollars);
                    


            
                } 
                */
                

            }
        }

       if(command.getOperation() == "Remove"){
           if(command.numArgs()>1){
               cout<<std::endl<<"Ignoring " << UNEXPECTED_ARGS << endl;
           }
           if(command.numArgs()<1){
               cout << std::endl << MISSING_ARGS << endl;
            }
            else{
                //CODE WILL BE WRITTEN
                continue;
            }

       }
       if(command.getOperation() == "Process"){
           if(command.numArgs()==1){
                string fname = command.getArg1();
                Process(fname);
            }
            else{
                if(command.numArgs()>1){
                    cout<<std::endl<<"Ignoring " << UNEXPECTED_ARGS << endl;
                }
                if(command.numArgs()<1){
                    cout << std::endl << MISSING_ARGS << endl;
                }
            }
       }

   // }
      
    }
}