
#include <string>
#include "Fan.h"
#include "fans.h"
#include "Email.h"
#include "Phone.h"
#include <iostream>
#include <bits/stdc++.h>

template <class T>



class BinaryTree{
    struct node{
        T value;
        struct node * right;
        struct node * left;
    };

    public:
        ~BinaryTree();
        BinaryTree();
        void addNode(T node);
        bool lookup(T val);
        void printInOrder();
        void lookupShow(T val);
        //node* minValueNode(node* node);
        void remove (int fanid);
        //Fan* lookupConcession(T val,int dolr);
        //struct node* minValueNode(struct node* node);
        void conc(Fan& val);
       

    private:
        void remove (struct node* val, int fanid);
        struct node* root;
        int treesize;
        //struct node deleteNode(struct node* root, T k);
        bool lookup(struct node* node, T val);
        void addNode(struct node** node, T val);
        void printInOrder(struct node* node);
        
        //struct node* minValueNode(struct node* node);
        void deleteTree(struct node* node);
        void lookupShow(struct node* node, T val);
        //Fan* lookupConcession(struct node* node, T val,int dolr);
        //struct node* deleteNode(struct node* root, T k);
        //node* remove(T value, node* t);

    };





    template <class T>
    BinaryTree<T>::BinaryTree(){
	    this->root = NULL;
	    this->treesize = 0;
    }

    template <class T>
    BinaryTree<T>::~BinaryTree(){
	    deleteTree(this->root);
    }

    template <class T>
    void BinaryTree<T>::deleteTree(struct node* node){
	    if(node != NULL){
		    deleteTree(node->left);
		    deleteTree(node->right);
		    delete node;
	    }
    }


    template <class T>
    void BinaryTree<T>::addNode(T val){
	    addNode(&(this->root), val);
    }



    template <class T>
    void BinaryTree<T>::addNode(struct node** node, T val){
        if(*node==NULL){
            struct node * tmp = new struct node();
            tmp->value = val;
            tmp->left =NULL;
            tmp->right = NULL;
            *node =tmp;
            this->treesize++;
        
        }
        else{
            
            if(val> (*node)->value){
                addNode(&(*node)->right, val);
            }
            else{
                addNode(&(*node)->left, val);
            }
        }
    }
    
    template <class T>
    void BinaryTree<T>::lookupShow(T val){
	    lookupShow(this->root, val);
    }

    template <class T>
    void BinaryTree<T>::lookupShow(struct node* node, T val){
        if(node==NULL){
            cout<<"Node can not be shown because not exist";
        }

        else{
            if(val==node->value){
                cout<< node->value.get_pointer() <<endl;
                //cout<<node->value<<endl;
            }
            if(val> node->value){
                return lookupShow(node->right, val);
            }
            else if(val< node->value){
                return lookupShow(node->left, val);
            }
        }
    }

    /*
    template <class T>
    Fan* BinaryTree<T>::lookupConcession(T val,int dolr){
	    lookupConcession(this->root, val,dolr);
    }

    template <class T>
    void BinaryTree<T>::conc(Fan& val){
        val.concessions=10;

    }


    template <class T>
    Fan* BinaryTree<T>::lookupConcession(struct node* node, T val, int dolr){
        if(node==NULL){
            cout<<"Fan can not be found in the database"<<endl;
        }

        else{
            if(val==node->value){
                //cout<<"Initial: "<<node->value.get_pointer().getconcession()<<endl;
                //setConces(node->value.get_pointer(),dolr);
                
                conc(node->value.get_pointer()).concessions=conc(node->value.get_pointer()).concessions + dolr;
                
                //cout<<"Final: "<<node->value.get_pointer().getconcession()<<endl;


                //cout<<node->value.get_pointer()->getconcession()<<endl;
                //cout<<node->value<<endl;
            }
            if(val> node->value){
                return lookupConcession(node->right, val,dolr);
            }
            else if(val< node->value){
                return lookupConcession(node->left, val,dolr);
            }
        }
    }
    */


    


    template <class T>
    bool BinaryTree<T>::lookup(T val){
	    return lookup(this->root, val);
    }

    template <class T>
    bool BinaryTree<T>::lookup(struct node* node, T val){
        if(node==NULL){
            return false;
        }
        else{
            if(val==node->value){
                return true;
            }
            if(val> node->value){
                return lookup(node->right, val);
            }
            else if(val< node->value){
                return lookup(node->left, val);
            }
        }
    }


    template <class T>
    void BinaryTree<T>::printInOrder(){
	    printInOrder(this->root);
	    std::cout << std::endl;
    }

    template <class T>
    void BinaryTree<T>::printInOrder(struct node* node){
	    if(node != NULL){
		    printInOrder(node->left);
		    std::cout << node->value <<endl;
		    printInOrder(node->right);
	    }
    }
    /*
    template <class T>
    void BinaryTree<T>::remove(int fanid) {
        remove(this->root, fanid);
    }
    */


    template <class T>
    void BinaryTree<T>::remove(struct node* val, int fanid) {
        if (val == NULL) {
            cout << "fanid cannot found" << endl; // burasi simldilik exit1 dursun.
            exit(1);
        }
         
        if (val->GetData() >fanid) {
            root->left = remove(root->left, fanid);
            // burda silme islemini yap
        }
            
        if (val->GetData() < fanid) {
            root->right = remove(val->right, fanid);
        }
        else {
            remove(val->left, fanid);
        }

        if (val->left == NULL) {
            node* temp = val->right;
            delete val;
        }
        else if (val->right == NULL) {
            node* temp = val->left;
            delete val;
            
        }
        else {

            node* succParent = val;

            node* succ = val->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
        

            if (succParent != val)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            root->value = succ->value;
 
            delete succ;

        }
    }
            
         
        

    
    // template <class T>
    // void BinaryTree<T>::deleteNode(struct node* root, T k)
    // {
    
    //     if (root == NULL)
    //         return root;
 
    // // Recursive calls for ancestors of
    // // node to be deleted
    //     if (root->value > k) {
    //         root->left = deleteNode(root->left, k);
    //         return root;
    //     }
    //     else if (root->value < k) {
    //         root->right = deleteNode(root->right, k);
    //         return root;
    //     }
 
    // // We reach here when root is the node
    // // to be deleted.
 
    // // If one of the children is empty
    //     if (root->left == NULL) {
    //         node* temp = root->right;
    //         delete root;
    //         return temp;
    //     }
    //     else if (root->right == NULL) {
    //         node* temp = root->left;
    //         delete root;
    //         return temp;
    //     }
 
    // // If both children exist
    //     else {
 
    //         node* succParent = root;
 
    //     // Find successor
    //         node* succ = root->right;
    //         while (succ->left != NULL) {
    //             succParent = succ;
    //             succ = succ->left;
    //         }
 
    //     // Delete successor.  Since successor
    //     // is always left child of its parent
    //     // we can safely make successor's right
    //     // right child as left of its parent.
    //     // If there is no succ, then assign
    //     // succ->right to succParent->right
    //         if (succParent != root)
    //             succParent->left = succ->right;
    //         else
    //             succParent->right = succ->right;
 
    //     // Copy Successor Data to root
    //         root->value = succ->value;
 
    //     // Delete Successor and return root
    //         delete succ;
    //         return root;
    //     }
    // }
    
    
    

   

   
    

