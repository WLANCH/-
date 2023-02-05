#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node
{

    int number;//序号
    int password;//密码
    struct Node* next;
}Node, * Lnode;

Lnode creatlist(int n)
{
    int i = 1;
    int Pass;

    Node* head;//链表头结点
    Node* current;//链表当前节点
    Node* next;//链表下一个节点

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
        //连接链表与新创建的节点
        current->next = next;
        current = next;
    }
    //尾节点连接到头结点，形成循环链表
    current->next = head;
    return head;
}

void Joseph(Node* head, int len, int password)
{
    //前一个节点
    Node* pre = NULL;
    //后一个节点
    Node* next = NULL;
    //要删除的节点
    Node* temp = NULL;
    //初始化
    next = head;
    for (int i = 1; i < len; ++i)
    {
        pre = next->next;
        next = next->next;
    }
    //遍历所有人
    for (int i = 1; i <= len; ++i)
    {
        //先将指针移动到出列的前一个
        for (int j = 1; j < password; ++j)
        {
            pre = pre->next;
        }
        temp = pre->next;//保存要删除的节点
        next = temp->next;//下一个节点
        password = temp->password; //修改密码
        cout << temp->number << " ";//输出出列序号

        pre->next = next; //连接链表，去除中间节点
        free(temp);//释放中间节点
    }
}

int main()
{
    //环的长度
    int len;
    cout << "输入约瑟夫环的长度：";
    cin >> len;
    cout << "请输入m的初始值 m:";
    int m;
    cin >> m;
    Lnode head = creatlist(len);
  
    //cout << head->number;
    Joseph(head, len, m);
    return 0;
}