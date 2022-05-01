#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int queue[MAX];
int front = 0, rear= 0;
int s = 0;

bool is_full(){
  if((rear+1) % MAX == front) return true;
  return false;
}

bool is_empty(){
  if(front == rear )return true;
  return false;
}

int Dequeue(){
  if (is_empty()) return -999;
  front = (front + 1) % MAX;
  s--;
  return queue[front];
}
bool Enqueue(int a){
  if (is_full()) return false;
  rear = (rear + 1) % MAX;
  queue[rear] = a;
  s++;
  return true;
}

int Size(){
  return s;
}

int main() {
  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  Enqueue(4);
  Enqueue(5);
  printf("%d\n", Dequeue());
  printf("%d\n", Dequeue());
  printf("%d\n", Dequeue());
  printf("%d\n", Dequeue());

  return 0;
}