#include <iostream>
using namespace std;
#define ERROR -1
#define OK 1
typedef int QElemType;
typedef int Status;
//ѭ�����еĴ洢�ṹ
#define MAXQSIZE  3   //�����г���
typedef  struct
{
    QElemType *base;       //���ڶ�̬����洢�ռ�
    int  front;            //��ͷ����
    int  rear;             //��β����
} SqQueue;
//��ʼ��
void InitQueue (SqQueue &Q)
{
    //����һ���ն���
    Q.base =new QElemType[MAXQSIZE];
    Q.front=Q.rear=0;
}
//���ٶ���
void DestroyQueue(SqQueue &Q)
{
    if(Q.base)
        free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = 0;
}
//��ն���
void ClearQueue(SqQueue &Q)
{
    Q.front=Q.rear=0;
}
//�󳤶�
int  QueueLength (SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
//�п�
bool QueueEmpty (SqQueue Q)
{
    return (Q.front==Q.rear);
}
//���ͷԪ��
Status GetHead (SqQueue Q, QElemType &e)
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    return OK;
}
//ѭ���������
Status EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front)  return ERROR;
    Q.base[Q.rear]=e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}
//ѭ�����г���
Status DeQueue (SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1) % MAXQSIZE;
    return OK;
}
//����ʹ������ʾ
void DisplayQueue(SqQueue Q)
{
    int i=Q.front;
    while(Q.front!=Q.rear && (i+MAXQSIZE) % MAXQSIZE != Q.rear)
    {
        cout<<Q.base[i]<<endl;
        i++;
    }
}



//��Ԫ�����
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