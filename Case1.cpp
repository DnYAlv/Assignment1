#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  Node *next;
}*head,*tail;

Node *createNode(int n){
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

void sort(){
  Node *curr = head;
  Node *temp = NULL;
  if(!head){
    printf ("NO DATA !\n");
    return;
  } else {
    while(curr){
      temp = curr->next;
      while(temp){
        if(curr->n > temp->n){
          int swap = curr->n;
          curr->n = temp->n;
          temp->n = swap;
        }
        temp = temp->next;
      }
      curr = curr->next;
    }
  }
}

void print(){
  printf ("The sorted linked list is:\n");
  Node *temp = head;
  while(temp){
    if(temp->next) printf ("%d->",temp->n);
    else printf ("%d\n",temp->n);
    temp= temp->next;
  }
}

int main(){
  printf ("Input how many data for L1 : ");
  int n;
  scanf ("%d", &n);
  printf ("Input the data : ");
  for(int i = 1 ; i <= n; i++){
    int num;
    scanf ("%d", &num);
    pushTail(num);
  }
  printf ("Input how many data for L2 : ");
  int a;
  scanf ("%d", &a);
  printf ("Input the data : ");
  for(int i = 1 ; i <= a ; i++){
    int num;
    scanf ("%d", &num);
    pushTail(num);
  }
  sort();
  print();
  return 0;
}