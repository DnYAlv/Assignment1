#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  Node *next;
}*head,*tail,*curr;

Node *createNode (int n){
  Node *newNode = (Node*) malloc (sizeof(Node));
  newNode->next = NULL;
  newNode->n = n;
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

void check(int a){
  curr = head;
  int ctr = 1;
  while(curr){
    if(ctr == a){
      printf ("%d\n",curr->n);
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
  puts ("Input the data:");
  for(int i = 1 ; i <= n ; i++){
    int num;
    scanf ("%d", &num);
    pushTail(num);
  }
  printf ("Input the node : ");
  int a; 
  scanf ("%d", &a);
  printf ("The %dth Node from the end of the linked list is : ",a);
  check(n-a+1);

  return 0;
}