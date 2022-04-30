#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
  int student_number;
  char student_name[MAX_STRING];
  char student_address[MAX_STRING];
}student;

typedef struct {
  student data[MAX_STACK_SIZE];
  int top;
}Stack;

void init_stack(Stack *s){
  // (*s).top == s->top
  s->top = -1;
  return;
}

bool is_empty(Stack *s){
  // (*s).top == -1
  return s->top == -1;
}

bool is_full(Stack *s) {
  return s->top >= MAX_STACK_SIZE-1;
}

void push(Stack *s, student object){
  if(is_full(s)){
    printf("STACK IS FULL\n");
    return;
  }
  s->data[++s->top] = object;
}

student pop(Stack * s){
  if(is_empty(s)){
    printf("STACK is EMPTY\n");
    // return;
    exit(1);
  }
  return s->data[s->top--];
}

student peek(Stack *s){
  if(is_empty(s)){
    printf("STACK IS EMPTY\n");
    exit(1);
  }else return s->data[s->top];
}

int main(void){
  Stack s;
  init_stack(&s);
  student keys = {
    20220430, "YH", "DAEJEON"
  };
  student object;

  push(&s, keys);
  object=pop(&s);

  printf("student number : %d \n", object.student_number);
  printf("student name : %s \n", object.student_name);
  printf("student address : %s \n", object.student_address);
  return 0;
}