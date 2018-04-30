#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct property{
    int childs;
    string x;
    struct property *left;
     struct property *right;
     struct property *parent;
     // struct property *tree;
};
typedef struct property prop;
prop *root;                       //globle variable


void deleteNode(string s,prop *tree) {
  if(s.compare(tree->x)==0){    // replacement search start   condition1
    prop *fix=tree;
    if(tree->right==NULL && tree->left !=NULL){     //condition1.1
      fix->childs -=1;
      tree=tree->left;
      //fix=tree;
      if(tree->right==NULL){
        if(tree->left!=NULL){
          tree->parent->left=tree->left;
          tree->left->parent=tree->parent;
          fix->x=tree->x;


        }
        else{
          tree->parent->left=NULL;
          fix->x=tree->x;
        }
      }
      else{
        while(tree->right!=NULL){
          tree=tree->right;
        }
        if(tree->left==NULL){

         tree->parent->right=NULL;
         fix->x=tree->x;

       }
       else{
         tree->parent->right=tree->left;
         tree->left->parent=tree->parent;
         fix->x=tree->x;

       }

      }


  }
  else if( tree->right !=NULL){             //condition1.2
      tree=tree->right;

      if(tree->left==NULL){
        if(tree->right!=NULL){
          tree->right->parent=tree->parent;
          tree->parent->right=tree->right;
          fix->x=tree->x;

        }
        else{
          tree->parent->right=NULL;
          fix->x=tree->x;

        }
      }
      else{
        while(tree->left !=NULL){
          tree->childs -=1;
          tree=tree->left;
        }
        if(tree->right==NULL){
         tree->parent->left=NULL;
         fix->x=tree->x;

       }
       else{
         tree->right->parent=tree->parent;
         tree->parent->left=tree->right;
         fix->x=tree->x;

       }
      }


    }

    else{                                         //condition1.3
      if(tree->parent==NULL){
        fix=NULL;
      }
      else if(tree==tree->parent->left){
        tree->parent->childs -=1;
        tree->parent->left=NULL;
        fix->x=tree->x;
      }
      else{
        tree->parent->right=NULL;
        fix->x=tree->x;
      }
    }
    if(fix==NULL){
      root=fix;
      root=new prop();
      //root=(prop*)malloc(sizeof(prop));
      root->childs=0;
    }
  } // root found in search
  else if((tree->x).compare(s)>0){ //go left         condition2
    tree->childs -=1;
    deleteNode(s,tree->left);
  }
  else{                                           //go right condition3
      deleteNode(s,tree->right);
  }
}





                          //function ends
int findRank(string s,prop*tree){  // childs denotes children to the left of any node + itself

    if(s.compare(tree->x)==0)return tree->childs;
    else if((tree->x).compare(s)>0){
      return findRank(s,tree->left);  //left child must exist
    }
    else{
      return tree->childs+findRank(s,tree->right); //right child must exist
    }
}

void Add(prop *node ,prop*tree){   //insertion in BST2
    if((node->x).compare(tree->x)==0);

    else if((node->x).compare(tree->x)<0){
          tree->childs+=1;
          if(tree->left==NULL)  {
            tree->left=node;
            node->parent=tree;
          }

      else  {
        Add(node,tree->left);
              }
    }
    else{
      if(tree->right==NULL){
        tree->right=node;
        node->parent=tree;
          tree->right->childs=1;
      }
      else  Add(node,tree->right);
    }
}
void insert(string s){        //insertion in BST1
  prop *new_node=new prop();
    //prop *new_node=(prop*)malloc(sizeof(prop));
    //prop *tree=(prop*)malloc(sizeof(prop));
    new_node->x=s;
    new_node->childs=1;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->parent=NULL;
    prop *tree=root;
  //  tree->childs+=1;
    if(tree->childs==0){                //adding first element in BST
        tree->childs=1;
        tree->x=s;
        tree->left=NULL;
        tree->right=NULL;
        tree->parent=NULL;
    }
    else{                                  //adding other element in BST
          if((new_node->x).compare(tree->x)==0);    //check if left addition
         else  if((new_node->x).compare(tree->x)<0){
          tree->childs+=1;
          if(tree->left==NULL) {               //left side fist element addition
             tree->left=new_node;
             new_node->parent=tree;
           }
          else  Add(new_node,tree->left);
        }
        else{                             //right side addition
          if(tree->right==NULL){          //right side fist element addition
            tree->right=new_node;
            new_node->parent=tree;
            tree->right->childs=1;
          }
          else  Add(new_node,tree->right);
        }
    }
}


int main(){
//root=(prop*)malloc(sizeof(prop));
root=new prop();
root->childs=0;
//root->x = NULL;
int n;
 cin>>n;
 for (int i=0; i<n; i++){
     string s1,s2;
     cin>>s1>>s2;

    if(s1[0]==108){                          //'l'=108
        insert(s2);
        //cout<<root->childs<<endl;

    }
    if(s1[1]==105){                       //   'i'=105
        prop *tree=root;
    cout<<findRank(s2,tree)<<endl;
  }


    if(s1[1]==111){                      //  'o'=111
      prop *tree=root;
      cout<<findRank(s2,tree)<<endl;
      deleteNode(s2,tree);
    }



 }
//cout<<root->left->left->childs<<endl;
	return 0;
}

