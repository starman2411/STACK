#ifndef SUBLIST_H_INCLUDED
#define SUBLIST_H_INCLUDED
#include "Stack_class.h"
#include <iostream>

using namespace std;

class Sublist;

class Node {
    private:
        int data;
        Node *next;
    friend Sublist;
};

class Sublist: public Stack{
    private:
        Node *head;
        unsigned int length;
    public:

    Sublist()
    {
        head=NULL;
        length=0;
    }

    ~Sublist()
    {
        if (head==0) return;
        Node *p=head;
        do
        {
            Node *s=p;
            p=p->next;
            delete s;
        } while (p!=0);
        return;
    }

    bool push_forward(int a)
    {
        Node *elem = new(Node);
        elem ->data=a;
        length++;
        if (head==0)
        {
            elem->next=NULL;
            head=elem;
        }
        else
        {
            elem->next=head;
            head=elem;
        }
        return(elem);
    }


    bool push_back(int a)
    {
        Node *elem = new(Node);
        Node *p=head;
        elem ->data=a;
        elem ->next=NULL;
        length++;

        do
        {
            p=p->next;
            //cout<<"t"<<p->data;
        } while (p->next!=NULL);
        p->next=elem;
        return(0);
    }


    void print()
    {
        Node *p=head;
        do
        {
            cout <<p->data<<" ";
            p=p->next;

        } while (p!=0);

    }

    bool pop_back()
    {
        Node *p=head;
        Node *s=NULL;
        length--;

        do
        {
            s=p;
            p=p->next;
        }while (p->next!=NULL);
        delete p;
        s->next=NULL;
        return(0);
    }

    int pop_forward(){
        Node* p=head->next;
        delete head;
        head = p;
        length--;
        return(0);

    }

    bool push_where(unsigned int where,int a){
        Node* elem=new(Node);
        Node* p=head;
        Node* s=NULL;
        elem->data=a;
        p=head;
        if (where>length)
        {
            cout<<"номер за пределами списка, обратитесь к функции push_back";
        }
        for (int i=2;i<where;i++)
        {
            p=p->next;
        }
        s=p->next;
        p->next=elem;
        elem->next=s;
        length++;
        return(0);
    }

    bool Clean()
    {
        if (head==0) return 0;
        Node *p=head;
        do
        {
            Node *s=p;
            p=p->next;
            delete s;
        } while (p!=0);
        return 0;
    }

    bool erase_where(unsigned int where){
        Node* p=head;
        Node* s=NULL;
        if (where>length)
        {
            cout<<"номер за пределами списка, обратитесь к функции pop_back";
        }
        for (int i=2;i<where;i++)
        {
            p=p->next;
        }
        s=p->next;
        p->next=s->next;
        delete s;
        length--;
        return(0);
    }

    unsigned int size(){
        return(length);
    }

    };

#endif // SUBLIST_H_INCLUDED
