#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node
{

    int number;//���
    int password;//����
    struct Node* next;
}Node, * Lnode;

Lnode creatlist(int n)
{
    int i = 1;
    int Pass;

    Node* head;//����ͷ���
    Node* current;//����ǰ�ڵ�
    Node* next;//������һ���ڵ�

    current = new Node;
    current->number = i;
    cin >> Pass;
    current->password = Pass;
    head = current;
    for (i = 2; i <= n; ++i)
    {
        cin >> Pass;
        next = new Node;
        next->number = i;
        next->password = Pass;
        //�����������´����Ľڵ�
        current->next = next;
        current = next;
    }
    //β�ڵ����ӵ�ͷ��㣬�γ�ѭ������
    current->next = head;
    return head;
}

void Joseph(Node* head, int len, int password)
{
    //ǰһ���ڵ�
    Node* pre = NULL;
    //��һ���ڵ�
    Node* next = NULL;
    //Ҫɾ���Ľڵ�
    Node* temp = NULL;
    //��ʼ��
    next = head;
    for (int i = 1; i < len; ++i)
    {
        pre = next->next;
        next = next->next;
    }
    //����������
    for (int i = 1; i <= len; ++i)
    {
        //�Ƚ�ָ���ƶ������е�ǰһ��
        for (int j = 1; j < password; ++j)
        {
            pre = pre->next;
        }
        temp = pre->next;//����Ҫɾ���Ľڵ�
        next = temp->next;//��һ���ڵ�
        password = temp->password; //�޸�����
        cout << temp->number << " ";//����������

        pre->next = next; //��������ȥ���м�ڵ�
        free(temp);//�ͷ��м�ڵ�
    }
}

int main()
{
    //���ĳ���
    int len;
    cout << "����Լɪ�򻷵ĳ��ȣ�";
    cin >> len;
    cout << "������m�ĳ�ʼֵ m:";
    int m;
    cin >> m;
    Lnode head = creatlist(len);
  
    //cout << head->number;
    Joseph(head, len, m);
    return 0;
}