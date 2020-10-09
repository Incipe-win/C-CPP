#include <malloc.h>
#include <stdio.h>
#include <iostream>
struct TreeNode {
  char val;
  TreeNode *left, *right;
  unsigned int isOut;  //专门为后序遍历设置的，0为不需要被输出，1为需要被输出
};
// typedef struct TreeNode TreeNode;

//先序遍历创建二叉树
void CreateTreeNode(TreeNode *&root) {
  char ch;
  ch = getchar();
  if (ch == '#')
    root = NULL;
  else {
    root = (TreeNode *)malloc(sizeof(TreeNode *));
    root->val = ch;
    CreateTreeNode(root->left);
    CreateTreeNode(root->right);
  }
}
//递归前序遍历
void rePreOrder(TreeNode *&root) {
  if (root) {
    printf("%c ", root->val);
    rePreOrder(root->left);
    rePreOrder(root->right);
  }
}

//递归中序遍历
void reInOrder(TreeNode *&root) {
  if (root) {
    reInOrder(root->left);
    printf("%c ", root->val);
    reInOrder(root->right);
  }
}

//递归后序遍历
void rePostOrder(TreeNode *&root) {
  if (root) {
    rePostOrder(root->left);
    rePostOrder(root->right);
    printf("%c ", root->val);
  }
}

//非递归先序遍历
void preOrder(TreeNode *&b) {
  TreeNode *stack[200], *p;
  int top = -1;
  if (b != NULL) {
    /* 根节点入栈 */
    top++;
    stack[top] = b;
    /* 栈不空时循环 */
    while (top > -1) {
      /* 出栈并访问该节点 */
      p = stack[top];
      top--;
      printf("%c ", p->val);
      /* 右孩子入栈 */
      if (p->right != NULL) {
        top++;
        stack[top] = p->right;
      }
      /* 左孩子入栈 */
      if (p->left != NULL) {
        top++;
        stack[top] = p->left;
      }
    }
  }
}

// 非递归中序遍历
void inOrder(TreeNode *&b) {
  TreeNode *stack[200], *p;
  int top = -1;
  if (b != NULL) {
    p = b;
    while (top > -1 || p != NULL) {
      /* 扫描p的所有左节点并入栈 */
      while (p != NULL) {
        top++;
        stack[top] = p;
        p = p->left;
      }
      if (top > -1) {
        /* 出栈并访问该节点 */
        p = stack[top];
        top--;
        printf("%c ", p->val);
        /* 扫描p的右孩子 */
        p = p->right;
      }
    }
  }
}

//非递归后续遍历
void postOrder(TreeNode *b) {
  TreeNode *stack[200], *p;
  int sign, top = -1;
  if (b != NULL) {
    do {
      /* b所有左节点入栈 */
      while (b != NULL) {
        top++;
        stack[top] = b;
        b = b->left;
      }
      /* p指向栈顶前一个已访问节点 */
      p = NULL;
      /* 置b为已访问 */
      sign = 1;
      while (top != -1 && sign) {
        /* 取出栈顶节点 */
        b = stack[top];
        /* 右孩子不存在或右孩子已访问则访问b */
        if (b->right == p) {
          printf("%c ", b->val);
          top--;
          /* p指向被访问的节点 */
          p = b;
        } else {
          /* b指向右孩子节点 */
          b = b->right;
          /* 置未访问标记 */
          sign = 0;
        }
      }
    } while (top != -1);
  }
}

//层次遍历二叉树
void levleOrder(TreeNode *&T) {
  TreeNode *Queue[200], *b;
  int front, rear;
  front = rear = 0;
  if (T) {
    Queue[rear++] = T;
    while (front != rear) {
      b = Queue[front++];
      printf("%c ", b->val);
      if (b->left != nullptr) Queue[rear++] = b->left;
      if (b->right != nullptr) Queue[rear++] = b->right;
    }
  }
}

int main() {
  TreeNode *root;
  printf("请用前序遍历输入二叉树:");
  CreateTreeNode(root);
  printf("创建二叉树成功！\n");
  int choice;
  while (1) {
    printf("请选择是否递归:是 ? 1 : 2\n你的选择:");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("递归前序遍历为:");
        rePreOrder(root);
        puts("");
        printf("递归中序遍历为:");
        reInOrder(root);
        puts("");
        printf("递归后序遍历为:");
        rePostOrder(root);
        puts("");
      case 2:
        printf("非递归前序遍历为:");
        preOrder(root);
        puts("");
        printf("非递归中序遍历为:");
        inOrder(root);
        puts("");
        printf("非递归后序遍历:");
        postOrder(root);
        puts("");
        printf("层次遍历为:");
        levleOrder(root);
        puts("");
        break;
    }
    printf("是否继续:是 ? 1 : 2\n你的选择:");
    int choice1;
    scanf("%d", &choice1);
    if (choice1 != 1) break;
  }
  return 0;
}

// 124##5##36##7##