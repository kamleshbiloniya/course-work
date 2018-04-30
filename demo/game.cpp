                                  //C00L Coder---->kamlesh k biloniya//
#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
string max_str;
int max_num;
struct property{                              //structure has six properties
    int childs;
    int height;
    string x;
    int key;
    struct property *left;
     struct property *right;
     struct property *parent;


};
typedef struct property prop;
prop *root;


/*prop* findInsucc(prop*tree){
    tree=tree->right;

                    if(tree->left==NULL){
                        return tree;
                    }
                    else{
                      while(tree->left !=NULL){
                        tree->childs-=1;
                        tree=tree->left;
                      }
                      return tree;
                    }


    }*/




int max(int a ,int b){
  if(a>b)return a;
  else return b;
}

int height(prop*tree){                          // calculate height
  if(tree==NULL)return 0;
  else return tree->height;
}

prop*newNode(string s){                         //create a new node
  prop *node=new prop();
  node->childs=1;
  node->x=s;
  node->key=1;
  node->left=NULL;
  node->right=NULL;
  node->parent=NULL;
  node->height=1;
  return (node);
}

prop *RR(prop*y){                                //Right Rotation
 //std::cout << "rotation about "<<y->x << '\n';
  prop *x=y->left;
  prop *tmp=x->right;
  if(y->parent!=NULL){
    prop*bapu=y->parent;
    if(y==y->parent->right)bapu->right=x;
    else bapu->left=x;
    x->parent=bapu;
    //std::cout << "yeah parentis "<<bapu->x << '\n';
  }
  else {
    x->parent=NULL;
    root=x;
  }



  x->right=y;
  y->parent=x;
  y->left=tmp;
  if(tmp!=NULL)tmp->parent=y;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;

  if(tmp!=NULL){
    y->childs=y->childs-x->childs;
  }
  else y->childs=1;


  //std::cout << "RR done" << '\n';

  return x;
}

prop *LR(prop*x){                                   //left Rotation
  //std::cout << "rotation about "<<x->x << '\n';
  prop*y=x->right;
  prop*tmp=y->left;
  if(x->parent!=NULL){
    prop*bapu=x->parent;
    if(x==x->parent->left)bapu->left=y;
    else bapu->right=y;
    y->parent=bapu;
    //std::cout << "yeah parent is "<<bapu->x << '\n';
  }
  else {
    y->parent=NULL;
    root=y;
  }


  y->left=x;
  x->parent=y;
  x->right=tmp;
  if(tmp!=NULL)tmp->parent=x;
  x->height=max(height(x->left),height(x->right))+1;
  y->height=max(height(y->left),height(y->right))+1;


  if(tmp!=NULL){
  y->childs=x->childs+y->childs;
  }
  else y->childs=x->childs+1;

  //std::cout << "LR done" << '\n';

  return y;
}

int BF(prop*node){                        //Balance factor calculate
  if(node==NULL)return 0;
  int h=height(node->left)-height(node->right);
  return h;
}


/*void deleteNode(string s,prop *tree) {
  prop*tre=tree;
    // cout<<" s= "<<s<<" tree: "<<tree->x<<endl;
   if(s<tree->x){ //go left         condition2
    tree->childs -=1;
    deleteNode(s,tree->left);
  }
  else if (s>tree->x){                                           //go right condition3
      deleteNode(s,tree->right);
  }
  else{ tre=NULL;

      // cout<<"string matched: "<<endl;
      if(tree->left==NULL&&tree->right==NULL){
        // cout<<" leaf node "<<endl;
        if(tree->parent==NULL){
          // cout<<" parent null1 "<<endl;
          root=NULL;
          // cout<<" empty tree "<<endl;
          root=new prop();
          root->childs=0;
        }
        else if(tree==tree->parent->left){
          tree->parent->left=NULL;
        }
        else{
          tree->parent->right=NULL;
        }
      }//leaf node


      else if(tree->right==NULL&&tree->left!=NULL){
        if(tree->parent==NULL){
          // cout<<" parent null2 "<<endl;
          tree=tree->left;
          tree->parent=NULL;
          root=tree;
        }
        else if(tree==tree->parent->left){
          // cout<<tree->x<<" is left child of1 "<<tree->parent->x<<endl;
          tree->parent->left=tree->left;
          tree->left->parent=tree->parent;
        }
        else{
          // cout<<tree->x<<" is right1 child of "<<tree->parent->x<<endl;
          tree->parent->right=tree->left;
          tree->left->parent=tree->parent;
        }
      }//having only left subtree
      else if(tree->right!=NULL&&tree->left==NULL){
      //  prop *Insucc=findInsucc(tree)
        if(tree->parent==NULL){
          // cout<<" parent null3 "<<endl;
          tree=tree->right;
          tree->parent=NULL;
          root=tree;

        }
        else if(tree==tree->parent->left){
          // cout<<tree->x<<" is left child of2 "<<tree->parent->x<<endl;
          tree->parent->left=tree->right;
          tree->right->parent=tree->parent;
        }
        else{
          // cout<<tree->x<<" is right2 child of "<<tree->parent->x<<endl;
          tree->parent->right=tree->right;
          tree->right->parent=tree->parent;
        }
      }//having only right subtree

      else{
          prop *Insucc=findInsucc(tree);
          tree->x=Insucc->x;
          deleteNode(Insucc->x,Insucc);

      }

  }


  //hrere
  if(tre==NULL)return;
  tre->height=1+max(height(tre->left),height(tre->right));

  int bf=BF(tre);

  //std::cout << "tree and bf are =="<<tree->x<<" "<<bf << '\n';

  if(bf>1 && BF(tre->left)>=0)
  {
    tre=RR(tre);
  //  std::cout << "new tree " <<tree->x<< '\n';
  }
  else if(bf<-1 && BF(tre->right)<=0)
  {
    tre=LR(tre);
    //std::cout << "new tree " <<tree->x<< '\n';
  }
  else if(bf>1 && BF(tre->left)<0)
  {
    tre->left=LR(tre->left);
    tre=RR(tre);
  }

  else if(bf<-1 && BF(tre->right)>0)
  {
    tre->right=RR(tre->right);
    tre=LR(tre);
  }
//std::cout << "I'm done" << '\n';
  return;


}*/



int findRank(string s,prop*tree){  // childs denotes children to the left of any node + itself

    if(s.compare(tree->x)==0)return tree->childs;
    else if(s.compare(tree->x)<0){
      return findRank(s,tree->left);  //left child must exist
    }
    else{
      return tree->childs+findRank(s,tree->right); //right child must exist
    }
}

void insert(prop *tree,string s){                         //insert function
  if(tree->childs==0){
    tree=newNode(s);
    max_str=s;
    max_num=1;
    root=tree;
    return;
  }

  if(s<tree->x){
    tree->childs+=1;
    if(tree->left==NULL){
      tree->left=newNode(s);
      tree->left->parent=tree;
    }
    else insert(tree->left,s);

  }

  else if(s>tree->x){
    if(tree->right==NULL){
      tree->right=newNode(s);
      tree->right->parent=tree;
    }
    else insert(tree->right,s);
  }

  else {
    tree->key+=1;
    if(tree->key > max_num){
      max_num=tree->key;
      max_str=s;
    }
  }                             //duplicate string

  tree->height=1+max(height(tree->left),height(tree->right));

  int bf=BF(tree);

  //std::cout << "tree and bf are =="<<tree->x<<" "<<bf << '\n';

  if(bf>1 && s<tree->left->x)
  {
    tree=RR(tree);
  //  std::cout << "new tree " <<tree->x<< '\n';
  }
  else if(bf<-1 && s>tree->right->x)
  {
    tree=LR(tree);
    //std::cout << "new tree " <<tree->x<< '\n';
  }
  else if(bf>1 && s>tree->left->x)
  {
    tree->left=LR(tree->left);
    tree=RR(tree);
  }

  else if(bf<-1 && s<tree->right->x)
  {
    tree->right=RR(tree->right);
    tree=LR(tree);
  }
//std::cout << "I'm done" << '\n';
  return;
}

int main(){
root=new prop();
root->childs=0;
int n;
 cin>>n;
 for (int i=0; i<n; i++){
     string s2;
     prop*tree=root;
     cin>>s2;
     //if(s1[0]==108){                          //'l'=108
        insert(tree,s2);
  //  }


  /*  if(s1[1]==105){                       //   'i'=105
        prop *tree=root;
    cout<<findRank(s2,tree)<<endl;
    }
   if(s1[1]==111){                      //  'o'=111
        prop *tree=root;
        cout<<findRank(s2,tree)<<endl;
        deleteNode(s2,tree);
    }*/
    // for(prop* x=root;x!=NULL;x=x->left){
    //   cout<<"root is: "<<x->x<<endl;
    // }
    // for(prop* x=root;x!=NULL;x=x->right){
    //   cout<<"root is: "<<x->x<<endl;
    // }
 }

 std::cout <<max_str << '\n';
//  std::cout << "hello hello" <<endl;
//  prop *tree=root;
//  if(tree->left==NULL)std::cout << "ohh No empty tree" << '\n';
// do{
//    cout<<tree->x<<"  bf="<<BF(tree)<<endl;
//    tree=tree->left;
//  } while(tree->left!=NULL);
//
//  prop *tree1=root;
// do{
//    cout<<tree1->x<<"  bf="<< BF(tree1)<<endl;
//    tree1=tree1->right;
//  } while(tree1->right!=NULL);
	return 0;
}
