#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  Node *next;
}*head,*tail,*curr;

Node *createNode(int n){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->n = n;
  return newNode;
}

void pushHead(int n){
  Node *temp = createNode(n);
  if(!head){
    head = tail = temp;
  } else {
    temp->next = head;
    head = temp;
  }
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

void popHead(){
  if(!head){
    return;
  } else {
    Node *temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
  }
}
// 1 2 3 4 5
void check(){
  curr = head;
  Node *temp = NULL;
   if(!head){
    printf ("NO DATA !\n");
    return;
  } else {
    while(curr){
      temp = curr->next;
      while(temp){
        if(curr->n < temp->n){
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
  curr = head;
  while(curr){
    if(curr->next){
      printf ("%d->",curr->n);
    } else {
      printf ("%d\n",curr->n);
    }
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
  check();
  print();
  return 0;
}