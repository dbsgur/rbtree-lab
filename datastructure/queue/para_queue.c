#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
  int friend_number;
  char friend_name[MAX];
}friend;

typedef struct{
  friend data[MAX];
  int rear;
  int front;
  int size;
}Queue;

void init_queue(Queue *q){
  q->size = 0;
  q->rear = 0;
  q->front = 0;
  return;
}

// is full
bool is_full(Queue *q){
  return (q->rear + 1) % MAX == q->front;
}
// is empty
bool is_empty(Queue *q){
  return q->rear == q->front;
}

// deque
friend deque(Queue *q){
  if(is_empty(q)){
    printf("QUEUE IS EMPTY\n");
    exit(1);
  }

  q->size -= 1;
  // q->rear -= 1;
  return q->data[(q->rear--) % MAX];
}

// enque
bool enque(Queue *q, friend object){
  if(is_full(q)){
    printf("QUEUE IS FULL\n");
    return false;
  }
  // rear = (rear+1) % MAX
  q->rear = (q->rear+1) % MAX;

  q->data[q->rear] = object;
  // size + 1
  q->size += 1;
  return true;
  
}
// size
int size(Queue *q) {
  return q->size;
}

int main(){
  Queue q;
  init_queue(&q);
  friend keys = {
    20220328, "JUNGLE"
  };
  friend object;

  enque(&q, keys);
  object = deque(&q);
  printf("friend number : %d \n ", object.friend_number);
  printf("friend name : %s \n ", object.friend_name);
  return 0;
}
