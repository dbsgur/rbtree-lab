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

  insert(t,50);
  insert(t,30);
  // insert(t,20);
  // insert(t,10);
  // insert(t,11);
  // insert(t,70);
  // insert(t,90);

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

  Node * delete = find(t, 30);
  erase(t, delete);

  printf("\n==============================\n");
  printInorder(t->root);
  printf("\n==============================\n");
  free(t);
  
  return 0;
}


// insert
Node * insert(btree * t, const key_t value){
  Node * n = (Node *)calloc(1, sizeof(Node));
  n->key = value;
  if (t->root == NULL){
    t->root = n;
    // return;
    return n;
  }else{
    Node * curr = t->root;
    while(curr != NULL){
      if(curr->key > value){
        //left
        if(curr->left == NULL){
          curr->left = n;
          return n;
        }
        curr = curr->left; // else
      }
      else{
        //right
        if(curr->right == NULL){
          curr->right = n;
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
    // root is empty
    return 0;
  }
  Node * search = find(t, node->key);
  if (search == NULL){
    // 삭제할 노드 없음
    return 0;
  }
  // 자식이 없는 경우도 이프문에서 삭제됨 + else
  if(search->left == NULL){
    node = NULL;
    printf("%d", node==NULL);
    free(node);
    return 1;
  }
  else if(search->right == NULL){
    free(node);
  }
  free(search);
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
// search recursion
Node * find(const btree * t, const key_t value){
  Node * curr = t->root;
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