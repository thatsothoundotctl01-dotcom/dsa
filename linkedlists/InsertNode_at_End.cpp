


 
#include <bits/stdc++.h>
using namespace std ; 

struct node {
  int data ;
  node *next  ;  
}  ;  
struct node *head = NULL ; 
struct node *current  = NULL ; 


void insertnodebegin(int data ){
  // create new data or link 
  
  struct node *link  = new node() ;  
  link -> data = data ; 
  link -> next = head ;   

  head  = link; 
} 
void insertnodeEnd( int data ) {
  // create new data  or link 

  struct node *link   = new node() ;  
  link->data = data ;  
  struct node *linkedlist =head ;   

  //print to old first node  
  while(linkedlist -> next != nullptr) {
    linkedlist = linkedlist -> next ;
  }  
  //first to new first node 
  linkedlist->next = link;
} 
void printlist() {
  struct node *p = head ;  
  std::cout << endl ;  
  while (p != nullptr ) {
    std::cout << "  " <<  p  -> data << " "  ; 
    p  = p -> next ; 
  } 
  std::cout <<endl ;
}
int main() {

  insertnodebegin(12) ; 
  insertnodeEnd(30) ; 
  insertnodeEnd(10) ; 
  insertnodeEnd(5) ; 
  insertnodeEnd(20) ; 
  printlist() ; 
  return  0 ; 
}
