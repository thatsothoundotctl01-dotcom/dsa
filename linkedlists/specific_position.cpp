

 
 
#include <bits/stdc++.h>
using namespace std ;  
  
struct node {
  int data ; 
  struct node *next ; 
} ;  
struct node *head = nullptr ;  
struct node *current = nullptr ; 

void insertatfirst(int data) {
  struct node *link  = new node() ;  
  link  -> data  = data; 
  link -> next  = head; 
  head = link ; 
} 
void insertatepos(int data , int pos) {
 
  if (pos == 0 ) {return ; } 

  struct node *prev  = head;  
  for (int i = 0 ; i< pos - 1 && prev != nullptr  ; i++) {
    prev = prev -> next ; 
  } 
  if (prev == nullptr ) {
    return ; 
  } 
  struct node *link  = new node() ;  
  link -> data = data ; 
  link  -> next = prev -> next ;  
  prev -> next  = link ; 

} 
void printlist() {
  struct node *p = head;  
  while (p !=  nullptr) {
    std::cout << p -> data << " " ; 
    p = p  -> next;  
  } 
  std::cout << " " <<endl ; 
}
int main(){  
  insertatfirst(3) ; 
  insertatfirst(1) ;  
  insertatfirst(2) ;  
  insertatepos(99,1) ;  
  insertatepos(3,2) ;
  printlist() ; 
  return 0 ;
}
