#include "rbtree.h"
#include <stdlib.h>
#include <stdio.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  node_t *nil = (node_t *)calloc(1, sizeof(node_t));
  p->nil = nil;
  p->nil->color = RBTREE_BLACK;
  p->root = nil;
  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  // node_t * curr = (node_t *)calloc(1, sizeof(node_t));
  // curr = t->root;
  // while(curr != t->nil){
  //   if(curr->left != t->nil){
  //     //??
  //   }
  //   free(curr->right);
  // }
  free(t);
}

void left_rotate(rbtree * t, node_t * n){
  // node_t * y = (node_t *)calloc(1, sizeof(node_t));
  node_t *y = n->right; // y를 설정한다.
  n->right = y->left; // y의 왼쪽 서브트리를 n의 오른쪽 서브트리로 옮긴다.
  if (y->left != t->nil){
    y->left->parent = n;
  }
  y->parent = n->parent; // n의 부모를 y로 연결한다.
  if(n->parent == t->nil){
    t->root = y;
  }else if (n == n->parent->left){
    n->parent->left = y;
  }else{
    n->parent->right = y;
  }
  y->left = n; // x를 y의 왼쪽으로 놓는다.
  n->parent = y;
}

void right_rotate(rbtree *t, node_t *n){
  node_t * y = (node_t*)calloc(1, sizeof(node_t));
  y = n->left;
  n->left = y->right;
  if(y->right != t->nil){
    y->right->parent = n;
  }
  y->parent = n->parent;

  if(n->parent == t->nil){
    t->root = y;
  }else if(n== n->parent->right){
    n->parent->right = y;
  }else{
    n->parent->left = y;
  }

  y->right = n;
  n->parent = y;
}

void insert_fixup(rbtree * t, node_t * n){
  node_t * y = (node_t *)calloc(1, sizeof(node_t));
  // node_t * y = NULL;
  while(n->parent->color == RBTREE_RED){
    if(n->parent == n->parent->parent->left){
      y = n->parent->parent->right;
      // 삼촌이 빨갛냐? CASE 1
      if(y->color == RBTREE_RED){
        n->parent->color == RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        n = n->parent->parent;
      }else {
        // CASE 2
        if(n == n->parent->right){
          n = n->parent;
          left_rotate(t, n);
        }
        // CASE 3
        n->parent->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        right_rotate(t,n->parent->parent);
      }
    }else{
      y = n->parent->parent->left;
      // CSAE 4
      if(y->color == RBTREE_RED){
        n->parent->color == RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        n = n->parent->parent;
      }else{
        // CASE 5
        if(n == n->parent->left){
          n = n->parent;
          right_rotate(t,n);
        }
        // CASE 6
        n->parent->color = RBTREE_BLACK;
        n->parent->parent->color = RBTREE_RED;
        left_rotate(t, n->parent->parent);
      }
    }
  }
  t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t * y = t->nil;
  node_t * x = t->root;
  // n-> parent = y;
  while (x!=t->nil){
    y = x;
    if(key < x->key){
      x = x->left;
    }else{
      x = x->right;
    }
  }
  node_t * n = (node_t *)calloc(1, sizeof(node_t));
  n-> key = key;
  n->parent = y;
  // y == root
  if (y==t->nil){
    t->root = n;
    // n -> color = RBTREE_BLACK;
    // return t->root;
  }else if(n->key < y->key) {
    y->left = n;
  }else{
    y->right = n;
  }
  n->left = t->nil;
  n->right = t->nil;
  n->color = RBTREE_RED;
  // RB-INSERT-FIXUP(T,z);
  insert_fixup(t, n);
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  node_t * curr = (node_t *)calloc(1, sizeof(node_t));
  curr = t->root;
  while(curr!=NULL && key != curr->key){
    if(key < curr->key){
      curr = curr->left;
    }else{
      curr = curr->right;
    }
  }
  return curr;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  node_t * curr = (node_t *)calloc(1, sizeof(node_t));
  curr = t->root;
  while(curr->left != t->nil){
    curr = curr->left;
  }
  return curr;
  // return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  node_t * curr = (node_t *)calloc(1, sizeof(node_t));
  curr = t->root;
  while(curr->right != t->nil){
    curr = curr->right;
  }
  return curr;
  // return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  node_t * curr = (node_t *)calloc(1, sizeof(node_t));
  curr = t->root;
  int i = 0;
  while(1){
    while(curr != t->nil){
      printf("%d ", curr->key);
      arr[i] = curr->key;
      i++;
      curr = curr->left;
    }
    if(curr == NULL){
      break;
    }
    printf("%d ", curr->key);
    arr[i] = curr->key;
    i++;
    curr = curr->right;
  }
  return 0;
}


void printInorder(node_t * node){
  if (node == NULL){
    return;
  }
  printInorder(node->left);
  // printf("%p\n", node);
  printf("%d %d\n", node->key, node->color);
  printInorder(node->right);
}
