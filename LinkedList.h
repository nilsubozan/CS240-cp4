#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>
#include <iostream>
#include "Fan.h"
#include "fans.h"
#include "Email.h"
#include "Phone.h"


using namespace std;

struct node{
    Fan data;
    node *next;
    node *prev;
};


class LinkedList{
    private:
        node *tail, *head;
    public:
        
        ~LinkedList(){
            node *tmp=nullptr;
            while(head){
                tmp=head;
                head=head->next;
                delete tmp;
            }
            delete head;
            head=nullptr;
	    }
        
        
	    
    //}
        
       
        LinkedList(){
            head=NULL;
            tail=NULL;
        }
        Fan obj;
        void insertnode(Fan obj){
	        // create new node
	        node *temp;
	        temp = new node();
	        temp->data = obj;
	        temp->prev = tail;
	        temp->next = NULL;

	        // if list is empty
	        if(tail == NULL)
		        head = temp;
	        else
		        tail->next = temp;	
	            tail = temp;
        }

        Fan* get_fan_pointer(){
            return &(tail->data);
        }

        bool searchphone(string phonenumber){
            node* temp = head;
            while(temp != NULL){
                if (temp->data.getphonenum() == phonenumber)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        bool searchmail(string email){
            node* temp = head;
            while(temp != NULL){
                if (temp->data.getEmail() == email)
                    return true;
                temp = temp->next;
            }
            return false;
        }
   

        void delete_Node(node** headref, Fan key){
            node *temp = *headref;
            node *previous = NULL;

            if(temp!=NULL && temp->data==key){
                *headref=temp->next;
                delete temp;
                return;
            }
            else{
                while(temp!=NULL && temp->data!=key){
                    previous=temp;
                    temp=temp->next;

                }
                //The key is not in the linked list
                if(temp==NULL){
                    return;
                }

                previous->next=temp->next;

                delete temp;
            }
        }

        void display(ofstream& outfile){
            node *tmp;
            tmp=head;
            while(tmp!=NULL){
                outfile<<tmp->data<<endl;
                tmp=tmp->next;
            }
            
        }

         void display22(){
            node *tmp;
            tmp=head;
            while(tmp!=NULL){
                cout<<tmp->data<<endl;
                tmp=tmp->next;
            }
        }


        

      

};

#endif