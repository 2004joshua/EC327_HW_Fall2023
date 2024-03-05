#include <iostream>
#include "LinkedList.h"

//include other files as needed
//



using namespace std;

//Put UniqueList class here
//

class UniqueList : public LinkedList<int> {
  public:  
    void insert(int x); 

  private: 
};

void UniqueList::insert(int x){
  Node<int>* current = this->head; 

  while(current != NULL){
    if(current->element == x){ //
      return; 
    }
    current = current->next; 
  }

  this->addLast(x); 
}



int main()
{
  //Uncomment once UniqueList class is created
  //DO NOT modify the test code
  
  UniqueList myList;
  //attempts to insert each integer from 0 to 49 twice
  for(int i = 0; i < 100; i++){
    myList.insert(i/2);
  }
  //checking inserted elements
  if(myList.getSize() > 50){
    cout << "Error: Inserted too many numbers."
         << " You should insert only if x does not already exist!\n";
    return -1;
  } else if(myList.getSize() < 50){
    cout << "Error: Inserted too few numbers.\n";
    return -1;
  }
  for(int i = 0; i < 50; i++){
    int next;
    if((next = myList.removeFirst()) != i){
      cout << "Error: Encountered " << next << " when expecting " << i << "!\n";
      return -1;
    }
  }
  cout << "Insert function has passed the test!\n";
  




  // Put the additional test code here if needed
  //






  return 0;
}

