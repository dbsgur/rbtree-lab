#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

// 학생 구조체 선언
typedef struct {
  int student_number;
  char student_name[MAX_STRING];
  char student_address[MAX_STRING];
}student;

student stack[MAX_STACK_SIZE]; // 스택 배열을 전역 변수로 선언
int top= -1; // 스택에 아무 요소가 없을 때는 0이 아닌 -1

// is_empty()
bool is_empty(){
  return top == -1;
}

// is_full(s) 
bool is_full(){
  return top == MAX_STACK_SIZE-1;
}

// push(s, item)
void push(student object){
  if (is_full()){
    printf("STACK IS FULL\n");
    return;
  }
  stack[++top] = object;
}

// pop(s)
student pop(){
  if(is_empty()){
    printf("STACK IS EMPTY\n");
    exit(1);
    // return;
  }
  return stack[top--];
}

// peek(s) : 제일 위 원소 출력
student peek(){
  if(is_empty()){
    printf("STACK IS EMPTY\n");
    exit(1);
    // return;
  }
  return stack[top];
}

int main(void){
  student keys = {
    20220430, "YH", "DAEJEON"
  };
  student object;
  push(keys);
  object = pop();

  printf("number : %d\n", object.student_number);
  printf("name : %s\n", object.student_name);
  printf("address : %s\n", object.student_address);
}