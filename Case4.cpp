#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  Node *next;
}*head,*tail,*curr;

Node *createNode(int n){
  Node *newNode = (Node*) malloc (sizeof(Node));
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

void check(){
  curr = head;
  Node *temp = NULL;
  while(curr->next){
    temp = curr->next;
    while(temp){
      if(temp->n == curr->n){
        curr->next = temp->next;
        free(temp);
      }
      temp = temp->next;
    }
    curr = curr->next;
  }
}

void print(){
  curr = head;
  while(curr){
    if(curr->next){
      printf ("%d->",curr->n);
    } else{
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
  while(n--){
    int num;
    scanf ("%d", &num);
    pushTail(num);
  }
  check();
  print();
  return 0;
}