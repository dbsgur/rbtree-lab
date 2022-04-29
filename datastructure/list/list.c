#include <stdio.h>
#include <stdlib.h> // malloc, free함수가 선언된 헤더 파일

typedef int element;

typedef struct ListNode {
  element data;
  struct ListNode * link;
}ListNode;

// 앞부분에 노드 삽입
ListNode * insert_first(ListNode * head, element value){
  ListNode * p = (ListNode*)malloc(sizeof(ListNode));
  p->data = value;
  p->link = head;
  head= p;
  return head;
}

// 노드 pre뒤에 새로운 노드 삽입
ListNode * insert(ListNode*head, ListNode* pre, element value) {
  ListNode* p = (ListNode*)malloc(sizeof(ListNode));
  p->data = value;
  p->link = pre->link;
  pre->link = p;
  return head;
}


// typedef struct NODE { //연결 리스트의 노드 구조체
//   struct NODE *next; // 다음 노드의 주소를 저장할 포인터
//   int data; // 데이터를 저장할 멤버
// }NODE;

// int main(){
//   NODE *head = malloc(sizeof(NODE)); // 머리노드 생성 
//                                                    // 머리 노드는 데이터를 저장하지 않음
//   NODE *node1 = malloc(sizeof(NODE)); //첫번째 노드 생성
//   head -> next = node1;// 머리 노드 다음은 첫번째 노드
//   node1 -> data = 10;

//   NODE *node2 = malloc(sizeof(NODE));
//   node1 -> next = node2;
//   node2 -> data = 20;

//   node2 -> next = NULL;

//   NODE *curr = head->next; //연결리스트 순회용 포인터에 첫번째 노드의 주소 저장
//   while (curr!= NULL){
//     printf("%d\n", curr->data);
//     curr = curr->next;
//   }
//   free(node2);
//   free(node1);
//   free(head);
//   return 0;
// }