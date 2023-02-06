#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 100 //定义栈中元素的最大个数


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//顺序栈
typedef struct SqStack {
    int data[MaxSize]; //存放栈中的元素
    int top; //栈顶指针
}SqStack, PSeqstack;

//初始化
void InitStack(SqStack& S) {
    S.top = -1;
}

//判栈空
bool Empty(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    else {
        return false;
    }
}

//入栈
void Push(SqStack &S, int x) {
    if (S.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return;
    }
    S.top++;
    S.data[S.top] = x;
}

//出栈
void Pop(SqStack& S, int& x) {
    if (S.top == -1) {
        cout << "栈空" << endl;
        return;
    }
    x = S.data[S.top--];
}

//读栈顶元素
int GetTop(SqStack S) {
    if (S.top == -1) {
        cout << "栈空" << endl;
        return -1;
    }
    else {
        return S.data[S.top];
    }
}


//遍历栈
void PrintStack(PSeqstack S) {
    while (S.top != -1) {
        cout << S.data[S.top--] << " ";
    }
    cout << endl;
}

//栈置空
void ClearStack(SqStack& S) {
    S.top = -1;
}


typedef int SElemType;
//链栈的存储结构，与单链表相同
typedef struct StackNode
{
    SElemType date;//数据域
    struct StackNode* next;//指针域
} StackNode, * LinkStack;

//链栈的初始化
int InitStack(LinkStack& S)
{
    //构造一个空栈S，栈顶指针置空
    S = NULL;
    cout << "链栈构造成功！" << endl;
    return 1;

}

//判断栈空
int StackEmpty(LinkStack S)
{
    if (S == NULL)
        return TRUE;
    else
        return FALSE;
}

//链栈的入栈
int Push(LinkStack& S, SElemType e)
{
    //在栈顶插入元素e
    LinkStack p = new StackNode;//生成新结点
    p->date = e;//将新结点数据域置为e
    p->next = S;//将新结点插入栈顶，也就是把栈顶的地址给新结点的指针域，使其指向他
    S = p;//修改栈顶指针为p
 //   cout << "入栈成功！" << endl;
    return 1;
}

//链栈的出栈
int Pop(LinkStack& S, SElemType& e)
{
    
    //删除S的栈顶元素，用e返回其值
    if (S == NULL)//栈空
    {
        cout << "出栈失败，栈空！" << endl;
        return 0;
    }
    e = S->date;//将栈顶元素赋给e
    LinkStack p = S;//用p临时保存栈顶元素空间，以备释放
    S = S->next;//修改栈顶指针
    delete p;//释放原栈顶元素空间
    cout << "出栈成功！" << endl;
    return e;
}

//取栈顶元素
int GetTop(LinkStack S)
{
    //返回S的栈顶元素，不修改栈顶指针
    if (S != NULL)
    {
        cout << "取栈顶元素成功！" << endl;
        return S->date;//返回栈顶元素的值，栈顶指针不变
    }
}
//多元素入栈
void InPutStack(LinkStack& S)
{
    cout << "你想几个元素入栈：";
    int n, e;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "个入栈元素：";
        cin >> e;
        Push(S, e);
    }
}
void OutPutStack(LinkStack& S)
{
    cout << "- - - - -" << endl;
    LinkStack p = S;

    while (p != NULL)
    {
        cout << p->date << endl;
        p = p->next;
    }
    cout << "- - - - -" << endl;
}
int main()
{
    LinkStack S;
    InitStack(S);
    InPutStack(S);

    OutPutStack(S);

    int d;
    int data = Pop(S, d);
    cout << data << endl;

    

}



//int main() {
//    SqStack S;
//    InitStack(S);
//    Push(S, 1);//入栈
//    Push(S, 2);
//    Push(S, 3);
//    Push(S, 4);
//    cout << "栈顶元素为：" << GetTop(S) << endl;
//    cout << "出栈顺序为：";
//    PrintStack(S);
//    int x;
//    Pop(S, x);
//    cout << x << "出栈" << endl;
//    cout << "栈中剩余元素：";
//    PrintStack(S);
//    Pop(S, x);
//    cout << x << "出栈" << endl;
//    cout << "栈中剩余元素：";
//    PrintStack(S);
//    if (!Empty(S)) {
//        cout << "当前栈不为空" << endl;
//    }
//    else {
//        cout << "当前栈为空" << endl;
//    }
//    cout << Empty(S) << endl;
//   // ClearStack(S);
//    PrintStack(S);
//    cout << Empty(S) << endl;
//    return 0;
//}
