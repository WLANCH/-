#include <iostream>
using namespace std;
#define ERROR -1
#define OK 1
typedef int QElemType;
typedef int Status;
//循环队列的存储结构
#define MAXQSIZE  3   //最大队列长度
typedef  struct
{
    QElemType *base;       //用于动态分配存储空间
    int  front;            //队头索引
    int  rear;             //队尾索引
} SqQueue;
//初始化
void InitQueue (SqQueue &Q)
{
    //构造一个空队列
    Q.base =new QElemType[MAXQSIZE];
    Q.front=Q.rear=0;
}
//销毁队列
void DestroyQueue(SqQueue &Q)
{
    if(Q.base)
        free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = 0;
}
//清空队列
void ClearQueue(SqQueue &Q)
{
    Q.front=Q.rear=0;
}
//求长度
int  QueueLength (SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
//判空
bool QueueEmpty (SqQueue Q)
{
    return (Q.front==Q.rear);
}
//求队头元素
Status GetHead (SqQueue Q, QElemType &e)
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    return OK;
}
//循环队列入队
Status EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front)  return ERROR;
    Q.base[Q.rear]=e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}
//循环队列出队
Status DeQueue (SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1) % MAXQSIZE;
    return OK;
}
//遍历使队列显示
void DisplayQueue(SqQueue Q)
{
    int i=Q.front;
    while(Q.front!=Q.rear && (i+MAXQSIZE) % MAXQSIZE != Q.rear)
    {
        cout<<Q.base[i]<<endl;
        i++;
    }
}



//多元素入队
void CreatQueue(SqQueue& Q, const int n)
{
   // cout << "input msg" << endl;
   // QElemType input;
    for (int i = 0; i < n; ++i)
    {
     //   cin >> input;
        EnQueue(Q, i+1);
    }
}



int main()
{
    char operate_code;
    show_help();
    SqQueue Q;
    InitQueue(Q);
    QElemType e;
    int i;
    CreatQueue(Q, 3);

}