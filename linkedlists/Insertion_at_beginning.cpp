 






 
#include <bits/stdc++.h>
using namespace std ; 
struct node {
  int data ; 
  node *next ; 
} ;  
struct node *head = NULL ; 
struct node *current  = NULL ; 
 
void insertatbegin(int data ) {

  struct node *newls  = new node() ; // new of node   
  newls -> data = data ;   
  newls -> next = head ;  
  head = newls ; 

}  
// print data  
void printlist_newls(){
  struct node *p  = head ; 
  std::cout << endl;  
  while (p != nullptr) {
    std::cout << " " << p -> data  << "\t" ;   
    p = p -> next ; 
  } 
  std::cout << endl ; 
}
int main() {

  insertatbegin(1) ; 

  insertatbegin(2); 

  insertatbegin(3) ; 
  
  insertatbegin(5) ;  

  printlist_newls() ; 
 
  // ans of : 5 3 2 1  
  return 0  ; 
}
