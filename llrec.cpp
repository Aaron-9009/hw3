#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  
  Node* currSmall = nullptr;
  Node* currLarge = nullptr;
  Node* currNode = head;
  head = head->next;
  currNode->next=nullptr;

  if(currNode->val <= pivot){
    smaller = currNode;
    currSmall = smaller;
    smaller= smaller->next;
  }else{
    larger = currNode;
    currLarge = larger;
    larger= larger->next;
  }

  llpivot(head,smaller,larger,pivot);

  if(currSmall != nullptr){
    currSmall->next=smaller;
    smaller = currSmall;
  }
  if(currLarge != nullptr ){
    currLarge->next=larger;
    larger = currLarge;
  }
}

