#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;

/*
 * 存储结构
 */
typedef struct BiTNode
{
    TElemType data;    //数据
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/*
 * 创建二叉树,输入0表示创建空树
 */
static int a = 0;
Status CreateBiTree(BiTree *T, int expr[])
{
    TElemType e;
    /*scanf("%d", &e);*/
    e = expr[a++];
    if(e == -10)
    {
        a--;
        return OK;
    }
    if (e == 0)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree) malloc(sizeof(BiTNode));
        if (!T)
        {
            exit(OVERFLOW);
        }
        (*T)->data = e;
        CreateBiTree(&(*T)->lchild, expr);    //创建左子树
        CreateBiTree(&(*T)->rchild, expr);    //创建右子树
    }
    return OK;
}

/*
 * 访问元素
 */
void visit(TElemType e)
{
    printf("%d ", e);
}

/*
 * 先序遍历二叉树：指先访问根，然后访问孩子的遍历方式
 */
Status PreOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if (T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}

/*
 * 中序遍历二叉树：指先访问左（右）孩子，然后访问根，最后访问右（左）孩子的遍历方式
 */
Status InOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if (T)
    {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}

/*
 * 后序遍历二叉树：指先访问孩子，然后访问根的遍历方式
 */
Status PostOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if (T)
    {
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
}

/*
 * 表达式转换为对应的树
 */
void Expr2Tree(char str[], int expr[]){
    int top = 0;
    char stack[100];
    int len = 0;
    char *c = str;
    for(; *c != '\0'; c++){
        if isdigit(*c)
            stack[top++] = *c - '0';
        else if(*c == '+'){
            expr[len++] = -1;
            expr[len++] = stack[--top];
            expr[len++] = 0;
            expr[len++] = 0;
        }
        else if(*c == '-'){
            expr[len++] = -2;
            expr[len++] = stack[--top];
            expr[len++] = 0;
            expr[len++] = 0;
        }
        else if(*c == '*'){
            expr[len++] = -3;
            expr[len++] = stack[--top];
            expr[len++] = 0;
            expr[len++] = 0;
        }
        else if(*c == '/'){
            expr[len++] = -4;
            expr[len++] = stack[--top];
            expr[len++] = 0;
            expr[len++] = 0;
        }
    }
    expr[len++] = stack[--top];
    expr[len++] = 0;
    expr[len++] = 0;
    expr[len] = -10;
    // return expr;
}
int main()
{
    char str[] = "2-3*2";
    int expr[100];
    int i = 0;
    Expr2Tree(str, expr);
    for(;expr[i] != -10; ++i )
        printf("%d", expr[i]);
    printf("%d\n", expr[i]);
    BiTree T;
    printf("创建树，输入0为空树：\n");
    CreateBiTree(&T, expr);
    printf("先序遍历：");
    PreOrderTraverse(T, *visit);
    printf("\n中序遍历：");
    InOrderTraverse(T, *visit);
    printf("\n后序遍历：");
    PostOrderTraverse(T, *visit);
    printf("\n");

    return 0;
}
