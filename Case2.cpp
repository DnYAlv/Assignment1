#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  int flag = 0;
  Node *next;
}*head,*tail,*curr;

Node *createNode (int n){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->n = n;
  newNode->flag = 0;
  newNode->next = NULL;
  return newNode;
}

void pushTail(int n){
  Node *temp = createNode(n);
  if(!head){
    head = tail = temp;
  } else{
    tail->next = temp;
    tail = temp;
  }
}

int check(){
  curr = head;
  while(curr){
    if(curr->flag == 1){
      return 1;
    }
    curr->flag = 1;
    curr = curr->next;
  }
  return -1;
}

int main(){
  printf ("Input how many data: ");
  int n;
  scanf ("%d", &n);
  printf ("Input the data:\n");
  for(int i = 1; i <= n ; i++){
    int num;
    scanf ("%d", &num);
    pushTail(num);
  }
  curr = head;
  while(curr){
    if(curr->next == NULL){
      curr->next = head;
      break;
    }
    curr = curr->next;
  }
  int found = check();
  if(found == 1){
    puts("The Linked List is a Cycle");
  }else if(found == -1){
    puts("The Linked List is not a Cycle");
  }

  return 0;
}