#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef int key_t;

typedef struct Node{
  key_t key;
  struct Node *left;
  struct Node *right;
  struct Node *p;
}Node;

typedef struct btree{
  Node *root;
}btree;

Node * insert(btree * t, const key_t value);
int erase(btree *t, Node * node);
Node * find(const btree * t, const key_t value);
Node * minimum(const btree * t);
Node * maximum(const btree *t);
void printInorder(Node * node);


int main(){
  btree * t = (btree*)calloc(1,sizeof(btree));

  t->root = NULL;

  insert(t,100);
  insert(t,30);
  insert(t,20);
  insert(t,10);
  insert(t,11);
  insert(t,70);
  insert(t,90);

  printf("==============================\n");
  printInorder(t->root);
  printf("\n==============================\n");

  Node * search = find(t, 30);
  (search != NULL) ? printf("find : %d, 주소, 0x%p\n", search->key, search) : printf("검색결과 없음\n");
  Node * minN = minimum(t);
  printf("Minimum number : %d\n", minN->key);
  Node * maxN = maximum(t);
  printf("Maximum number : %d\n", maxN->key);

  printf("\n*****************************************\n");
  printf("***************DELETE********************\n");
  printf("*****************************************\n");

  Node * delete = find(t, 100);
  Node * delete2 = find(t, 11);
  // printf("delete before : %p\n", delete);
  // printf("before key : %p\n", delete->left);
  // printf("delete->p->left->left : %p\n", delete->p->left->left);
  erase(t, delete);
  erase(t, delete2);
  // printf("delete after : %p\n", delete);
  // printf("key : %d\n", delete->key);
  // free(delete);
  printf("\n==============================\n");
  printInorder(t->root);
  printf("\n==============================\n");
  printf("%p", t->root);
  free(t);
  
  return 0;
}


// insert
Node * insert(btree * t, const key_t value){
  Node * n = (Node *)calloc(1, sizeof(Node));
  n->key = value;
  // n->left = NULL;
  // n->right = NULL;
  if (t->root == NULL){
    t->root = n;
    return n;
  }else{
    Node * curr = t->root;
    while(curr != NULL){
      if(curr->key > value){
        //left
        if(curr->left == NULL){
          curr->left = n;
          n->p = curr;
          return n;
        }
        curr = curr->left; // else
      }
      else{
        //right
        if(curr->right == NULL){
          curr->right = n;
          n->p = curr;
          return n;
        }
          curr = curr -> right; // else
      }
    }
  }
  return n;
}

// delete
int erase(btree *t, Node * node){
  if (t==NULL){
    // tree is empty
    return 0;
  }
  if (node == NULL){
    // 삭제할 노드 트리에 존재하지 않음
    return 0;
  }
  if(node->left == NULL && node ->right == NULL){ // 차수가 0
    // *node = NULL; // 안됨 ->이유좀 -> 도영
    if(node -> p == NULL){
      t->root = NULL;
    }
    else{
      if(node->p->left == node){
        node->p->left = NULL;
      }else{
        node->p->right = NULL;
      }
    }
  }
  else if(node->left == NULL || node->right == NULL) // 차수가 1
  {
    Node * child = (node->left != NULL) ? node->left : node->right;
    if(node->p == NULL){
      t->root = child;
    }else{
      if(node->p->left == node){
        node->p->left = child;
      }else{
        node->p->right = child;
      }
    }
  }else{ // 차수가 2이상 후계자 찾기 -> 오른쪽
    Node *succ_parent = node;
    Node *succ = node->right;
    while(succ->left != NULL){
      succ_parent = succ;
      succ= succ->left;
    }
    node->key = succ->key;
    if (succ_parent -> left == succ){
      succ_parent->left = succ->right;
    }else{
      succ_parent->right = succ->right;
    }
    node = succ;
    return 1;
  }
}
// search
// Node * find(const btree * t, const key_t value){
//   if(t==NULL || t->key == value){
//     return t;
//   }
//   if(value < t->key){
//     return find(t->left, value);
//   }
//   return find(t->right, value);
// }
/*
재귀 호출을 while 루프로 펼쳐(unrolling)이 프로시저를 순환적인 형태로 재작성할 수 있다.
대부분의 컴퓨터에서 순환적 형태의 버전이 수행시간이 빠르다.
*/
// search recursion
Node * find(const btree * t, const key_t value){
  Node * curr = (Node *)calloc(1, sizeof(Node));
  curr = t->root;
  while(curr!=NULL && value != curr->key){
    if(value < curr->key){
      curr = curr->left;
    }else{
      curr = curr->right;
    }
  }
  return curr;
}

Node * minimum(const btree * t){
  Node * curr = t->root;
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

Node * maximum(const btree *t){
  Node * curr = t->root;
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}

void printInorder(Node * node){
  if (node == NULL){
    return;
  }
  printInorder(node->left);
  printf("%d ", node->key);
  printInorder(node->right);
}