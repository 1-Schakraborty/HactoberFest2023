//menu driven program on doubly circular linked list
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class Dlinkedlist
{
    node *head;
    node *last;

public:
    Dlinkedlist()
    {
        head = NULL;
        last = NULL;
    }
    ~Dlinkedlist()
    {
        node *x;
        x = head;
        while (x->next != NULL)
        {
            x = x->next;
            delete (x);
        }
        delete (x);
    }
    void insertBeg(int item);
    void insertEnd(int x);
    void deleteBeg();
    void deleteEnd();
    void insertAny(int index, int pro);
    void deleteAny(int pos);
    int lengthl();
    void display();
    void reverse();
    void scarch(int sc);
};
void Dlinkedlist::insertBeg(int item)
{
    node *Newnode = new node(item);
    Newnode->data = item;
    if (head == NULL)
    {
        head = Newnode;
        last = Newnode;
    }
    else
    {
        Newnode->next = head;
        head->prev = Newnode;
        head = Newnode;
    }
}
void Dlinkedlist::insertEnd(int it)
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *en = new node(it);
    en->prev = last;
    last->next = en;
    last = en;
}
void Dlinkedlist::deleteBeg()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else if (head == last)
    {
        node *te;
        te = head;
        head = last = NULL;
        delete (te);
    }
    else
    {
        node *temp;
        head->next->prev = NULL;
        temp = head;
        head = head->next;
        delete (temp);
    }
}
void Dlinkedlist::deleteEnd()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else if (head == last)
    {
        node *te;
        te = head;
        head = last = NULL;
        delete (te);
    }
    else
    {
        node *t;
        last->prev->next = NULL;
        t = last;
        last = last->prev;
        delete (t);
    }
}
void Dlinkedlist::insertAny(int index, int pro)
{
    int c = lengthl();
    if (index == 1)
    {
        insertBeg(pro);
    }
    else if (index >= 2 && index <= c)
    {

        node *newn = new node(pro);
        node *q;
        node *any;
        q = head;
        for (int i = 1; i < (index - 1); i++)
        {
            q = q->next;
        }
        newn->data = pro;
        newn->prev = q;
        any = q->next;
        q->next = newn;
        newn->next = any;
        any->prev = newn;
    }
    else if (index == c + 1)
    {
        insertEnd(pro);
    }
    else
        cout << "check the position!" << endl;
}
void Dlinkedlist::deleteAny(int pos)
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else
    {
        node *del;
        del = head;
        while (del->data != pos && del->next != NULL)
        {
            del = del->next;
        }
        if (del->data == pos)
        {
            if (del->next != NULL && del->prev == NULL)
            {
                deleteBeg();
            }
            else if (del->next == NULL && del->prev != NULL)
            {
                deleteEnd();
            }
            else if (del->prev != NULL && del->next != NULL)
            {
                del->prev->next = del->next;
                del->next->prev = del->prev;
                delete (del);
            }
            else
            {
                delete (del);
                head = NULL;
            }
        }
        else
        {
            cout << "element not found!" << endl;
        }
    }
}
int Dlinkedlist::lengthl()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *len;
    len = head;
    int count = 0;
    /*while (len->next != NULL)
    {
        len = len->next;
        count++;
    }
    count += 1;*/
    while (len != NULL)
    {
        count++;
        len = len->next;
    }
    return count;
}
void Dlinkedlist::reverse()
{
    node *pre;
    node *temp;
    pre = head;
    while (pre != NULL)
    {
        temp = pre->next;
        pre->next = pre->prev;
        pre->prev = temp;
        pre = temp;
    }
    pre = head;
    head = last;
    last = pre;
}
void Dlinkedlist::scarch(int sc)
{
    node *s;
    s = head;
    int flag = 0;
    while (s->data != sc && s->next != NULL)
    {
        s = s->next;
        flag += 1;
    }
    if (s->data == sc)
    {
        ++flag;
        cout << "the position of scarched item"
             << "=";
        cout << flag << endl;
    }
    else
    {
        cout << "the scarched item is not found!" << endl;
    }
}
void Dlinkedlist::display()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *s;
    s = head;
    while (s != NULL)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
int main()
{
    Dlinkedlist l;
    int n, item, i;
    int index, pro, pos, sc;
    cout << "operations on linkedlist:" << endl;
    cout << "----------------------------" << endl;
    cout << "0 for EXIT"
         << endl
         << "1.insert at beginning"
         << endl
         << "2.insert at end"
         << endl
         << "3.delete from beinning"
         << endl
         << "4.delete from end"
         << endl
         << "5.insert at any position"
         << endl
         << "6.delete any element"
         << endl
         << "7.length of the linkedlist"
         << endl
         << "8.reverse"
         << endl
         << "9.scarch an item"
         << endl
         << "10.display" << endl;
    cout << "-------------------------------" << endl;
    while (1)
    {
        cout << "enter your choice"
             << "=";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> item;
            l.insertBeg(item);
            break;
        case 2:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> i;
            l.insertEnd(i);
            break;
        case 3:
            l.deleteBeg();
            break;
        case 4:
            l.deleteEnd();
            break;
        case 5:
            cout << "enter the position where the value should be inserted"
                 << "=";
            cin >> index;
            cout << "enter the item to be inserted"
                 << "=";
            cin >> pro;
            l.insertAny(index, pro);
            break;
        case 6:
            cout << "enter the value that should be deleted"
                 << "=";
            cin >> pos;
            l.deleteAny(pos);
            break;
        case 7:
            int cou;
            cou = l.lengthl();
            cout << "the length of the linkedlist"
                 << "=";
            cout << cou << endl;
            break;
        case 8:
            l.reverse();
            break;
        case 9:
            cout << "enter the item to be scarched"<<" "
                 << "=";
            cin >> sc;
             l.scarch(sc);
            break;
        case 10:
            l.display();
            break;
        default:
            exit(99);
        }
    }
    return 0;
}
