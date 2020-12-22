#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  Node *next;
}*tail,*head,*curr;

Node *createNode (int n){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->n = n;
  newNode->next = NULL;
  return newNode;
}

void pushTail(int n){
  Node *temp = createNode(n);
  if(!head){
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void check(int n){
  curr = head;
  int ctr = 1;
  while(curr){
    if(ctr == n){
      printf ("%d\n", curr->n);
      return;
    }
    ctr++;
    curr = curr->next;
  }
  
}

int main(){

  printf ("Input how many data : ");
  int n;
  scanf ("%d", &n);
  puts("Input the data:");
  for(int i = 0 ; i < n ; i++){
    int num;
    scanf ("%d", &num);
    pushTail(num);
  }
  printf ("The middle element of the linked list is : ");
  if(n % 2 == 0){
    check(n/2);
  } else {
    check (n/2 + 1);
  }
  
  return 0;
}