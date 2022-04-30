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

// 앞부분의 노드 제거
ListNode* delete_first(ListNode*head){
  ListNode* removed;
  if(head == NULL) return NULL;
  removed = head;
  head = removed->link;
  free(removed);
  return head;
}

//pre가 가리키는 노드의 다음 노드 삭제
ListNode* delete(ListNode * head, ListNode*pre){
  ListNode * removed;
  removed = pre->link;
  pre->link = removed->link;
  free(removed);
  return head;
}

// concat two lists
ListNode* concat_list(ListNode*head1, ListNode*head2)
{
  if(head1 == NULL) return head2;
  else if (head2==NULL) return head1;
  else {
    ListNode*p;
    p= head1;
    while(p->link != NULL){
      p = p->link;
    }
    p->link = head2;
    return head1;
  }
}

//reverse LIST
ListNode* reverse(ListNode * head){
  ListNode *p, *q, *r;

  p= head; // p는 역순으로 만들 리스트
  q= NULL; // q는 역순으로 만들 노드
  while(p!=NULL){
    r = q;  //r은 역순으로 된 리스트
    q = p;  // r은 q,q는 p를 차례로 따라간다
    p = p->link; 
    q->link = r;  // q의 링크 방향을 바꾼다
  }
  return q;
}

// Print list length
int get_length(ListNode * head){
  int count = 0;
  for(ListNode*p=head; p!=NULL; p= p->link)
  {
    count++;
  }
  return count;
}

// get list sum
int get_sum(ListNode*head){
  int sum = 0;
  for(ListNode *p =head; p!= NULL; p=p->link){
    sum+= p->data;
  }return sum;
}

// get list max number
int get_max(ListNode*head){
  int maxNum = 0;
  for(ListNode*p = head; p!=NULL; p=p->link){
    if (maxNum < p->data){
      maxNum = p->data;
    }
  }return maxNum;
}

//get value's count in list
int count(ListNode* head, int value){
  int count = 0;
  for(ListNode*p=head;p!=NULL; p=p->link){
    if (value == p->data){
      count++;
    }
  }
  return count;
}

// delete value in list
ListNode* delete_node(ListNode*head, int value){
  ListNode * pre = NULL;

  for(ListNode* p = head; p!=NULL; pre=p, p=p->link){
    if(p->data == value){
      if (p== head){
        ListNode* removed = head;
        head = head->link;
        free(removed);
      }else{
        pre->link = p->link;
        free(p);
        p = pre;
      }
    }
  }
  return head;
}

// print LIST
void print_list(ListNode * head)
{
  for (ListNode*p=head; p != NULL; p= p->link){
    printf("%d -> ",p->data);
  }
  printf("NULL \n");
}

// insert Last Node
ListNode* insert_last(ListNode*head, var value){
  ListNode * p = (ListNode*)malloc(sizeof(ListNode));
  p->data = value;
  if(head == NULL){
    p->link = head;
    head = p;
  }else{
    ListNode * q = head;
    while(q->link != NULL){q=q->link}
    p->link = q->link;
    q->link = p;
  }
  return head;
}

// merge list
ListNode * merge(ListNode* list1, ListNode* list2){
  ListNode* result = NULL;
  ListNode* p1 = list1, *p2 = list2;
  if(p1 == NULL) return list2;
  if(p2==NULL) return list1;
  while(p1!= NULL && p2!=NULL){
    if(p1->data < p2->data){
      result = insert_last(result, p1->data);
      p1=p1->link;
    }else {
      result = insert_last(result, p2->data);
      p2=p2->link;
    }
  }
  while(p1 != NULL){
    result = insert_last(result, p1->data);
    p1 = p1->link
  }
  while(p2!=NULL){
    result = insert_last(result, p2->data);
    p2=p2->link;
  }
  return result;
}

// create list odd in list
ListNode * odd_extract(ListNode * list){
  ListNode * oddList = NULL;
  ListNode * p;
  for(p=list; p!=NULL; p=p->link){
    if (p->data % 2 != 0){
      oddList = insert_first(oddList, p->data);
      p= p->link;
    }
  }
  return oddList;
}

int main(void){
  ListNode *head = NULL;
  int i;
  for(i=0; i<5; i++){
    head = insert_first(head,i);
    print_list(head);
  }
  printf("#####################\n");
  for(i=0; i<5; i++){
    head = delete_first(head);
    print_list(head);
  }
  return 0;
}
