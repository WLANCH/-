#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 100 //����ջ��Ԫ�ص�������


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//˳��ջ
typedef struct SqStack {
    int data[MaxSize]; //���ջ�е�Ԫ��
    int top; //ջ��ָ��
}SqStack, PSeqstack;

//��ʼ��
void InitStack(SqStack& S) {
    S.top = -1;
}

//��ջ��
bool Empty(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    else {
        return false;
    }
}

//��ջ
void Push(SqStack &S, int x) {
    if (S.top == MaxSize - 1) {
        cout << "ջ��" << endl;
        return;
    }
    S.top++;
    S.data[S.top] = x;
}

//��ջ
void Pop(SqStack& S, int& x) {
    if (S.top == -1) {
        cout << "ջ��" << endl;
        return;
    }
    x = S.data[S.top--];
}

//��ջ��Ԫ��
int GetTop(SqStack S) {
    if (S.top == -1) {
        cout << "ջ��" << endl;
        return -1;
    }
    else {
        return S.data[S.top];
    }
}


//����ջ
void PrintStack(PSeqstack S) {
    while (S.top != -1) {
        cout << S.data[S.top--] << " ";
    }
    cout << endl;
}

//ջ�ÿ�
void ClearStack(SqStack& S) {
    S.top = -1;
}


typedef int SElemType;
//��ջ�Ĵ洢�ṹ���뵥������ͬ
typedef struct StackNode
{
    SElemType date;//������
    struct StackNode* next;//ָ����
} StackNode, * LinkStack;

//��ջ�ĳ�ʼ��
int InitStack(LinkStack& S)
{
    //����һ����ջS��ջ��ָ���ÿ�
    S = NULL;
    cout << "��ջ����ɹ���" << endl;
    return 1;

}

//�ж�ջ��
int StackEmpty(LinkStack S)
{
    if (S == NULL)
        return TRUE;
    else
        return FALSE;
}

//��ջ����ջ
int Push(LinkStack& S, SElemType e)
{
    //��ջ������Ԫ��e
    LinkStack p = new StackNode;//�����½��
    p->date = e;//���½����������Ϊe
    p->next = S;//���½�����ջ����Ҳ���ǰ�ջ���ĵ�ַ���½���ָ����ʹ��ָ����
    S = p;//�޸�ջ��ָ��Ϊp
 //   cout << "��ջ�ɹ���" << endl;
    return 1;
}

//��ջ�ĳ�ջ
int Pop(LinkStack& S, SElemType& e)
{
    
    //ɾ��S��ջ��Ԫ�أ���e������ֵ
    if (S == NULL)//ջ��
    {
        cout << "��ջʧ�ܣ�ջ�գ�" << endl;
        return 0;
    }
    e = S->date;//��ջ��Ԫ�ظ���e
    LinkStack p = S;//��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
    S = S->next;//�޸�ջ��ָ��
    delete p;//�ͷ�ԭջ��Ԫ�ؿռ�
    cout << "��ջ�ɹ���" << endl;
    return e;
}

//ȡջ��Ԫ��
int GetTop(LinkStack S)
{
    //����S��ջ��Ԫ�أ����޸�ջ��ָ��
    if (S != NULL)
    {
        cout << "ȡջ��Ԫ�سɹ���" << endl;
        return S->date;//����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
    }
}
//��Ԫ����ջ
void InPutStack(LinkStack& S)
{
    cout << "���뼸��Ԫ����ջ��";
    int n, e;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "�������" << i << "����ջԪ�أ�";
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
//    Push(S, 1);//��ջ
//    Push(S, 2);
//    Push(S, 3);
//    Push(S, 4);
//    cout << "ջ��Ԫ��Ϊ��" << GetTop(S) << endl;
//    cout << "��ջ˳��Ϊ��";
//    PrintStack(S);
//    int x;
//    Pop(S, x);
//    cout << x << "��ջ" << endl;
//    cout << "ջ��ʣ��Ԫ�أ�";
//    PrintStack(S);
//    Pop(S, x);
//    cout << x << "��ջ" << endl;
//    cout << "ջ��ʣ��Ԫ�أ�";
//    PrintStack(S);
//    if (!Empty(S)) {
//        cout << "��ǰջ��Ϊ��" << endl;
//    }
//    else {
//        cout << "��ǰջΪ��" << endl;
//    }
//    cout << Empty(S) << endl;
//   // ClearStack(S);
//    PrintStack(S);
//    cout << Empty(S) << endl;
//    return 0;
//}
