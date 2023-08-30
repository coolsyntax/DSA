#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linked_list
{
private:
    node *first;

public:
    linked_list()
    {
        first = NULL;
    }

    linked_list(int A[], int n);

    ~linked_list();

    void display();

    void insert(int index, int n);

    int Delete(int index);

    int length();

    void reverse1();

    void reverse2();

    node reverse3(node *first);

    bool hascycle(node *first);
};

linked_list::linked_list(int A[], int n)
{
    node *last, *t;
    int i = 0;

    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

linked_list::~linked_list()
{
    node *p = first;

    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void linked_list::display()
{
    node *p = first;

    while (p)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL\n";
}

int linked_list::length()
{
    node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }

    return len;
}

void linked_list::insert(int index, int n)
{
    node *t, *p = first;

    if (index < 0 || index > length())
        return;

    t = new node;
    t->data = n;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int linked_list::Delete(int index)
{
    node *p, *q = NULL;

    int x = -1;

    if (index < 1 || index > length())
        return -1;

    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

// using 3 iteraters (best)
void linked_list::reverse1()
{
    node *prev = NULL, *current = first, *next;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

// using array and extra node
void linked_list::reverse2()
{
    vector<int> A;
    int i;
    node *p = first;
    node *q = p;
    while (q)
    {
        A.push_back(q->data);
        q = q->next;
    }
    q = p;
    i = A.size() - 1;
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

// using recursion
node linked_list::reverse3(node *head)
{
    if (head->next == NULL)
    {
        return *head;
    }
    node newhead = linked_list::reverse3(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

bool linked_list::hascycle(node *head)
{
    node *slow = head, *fast = head;
    if (head == NULL)
        return false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        ListNode *dummynode = new ListNode(-1);
        ListNode *p3 = dummynode;

        while(p1 != NULL && p2 != NULL){
            if(p1->val < p2->val){
                p3->next = p1;
                p1 = p1->next;
            }
            else{
                p3->next = p2;
                p2 = p2->next;
            }

            p3 = p3->next;
        }

        while(p1 != NULL){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }

        while(p2 != NULL){
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }

        return dummynode->next;
    }

    
int main()
{

    int A[] = {1, 2, 3, 4, 5};

    linked_list l(A, 5);

    l.insert(3, 6);

    l.display();

    // l.reverse3();

    l.display();

    return 0;
}