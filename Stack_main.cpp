#include <iostream>

using namespace std;
//Класс для данных Sublist
class Node {
    public:
        int data;
        Node *next;
};



class Stack{
    public:
        Stack() {};
        ~Stack() {};
        virtual bool push_back(int a) = 0;
        virtual bool pop_back() = 0;
        virtual void print() = 0;
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
        Node *p=new(Node);
        p=head;
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
        Node *p=new(Node);
        Node *s=new(Node);
        p=head;
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
        Node* p=new(Node);
        p=head->next;
        delete head;
        head = p;
        length--;
        return(0);

    }

    bool push_where(unsigned int where,int a){
        Node* elem=new(Node);
        Node* p=new(Node);
        Node* s=new(Node);
        elem->data=a;
        p=head;
        if (where>length)
        {
            cout<<"íîìåð çà ïðåäåëàìè ñïèñêà, îáðàòèòåñü ê ôóíêöèè push_back";
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

    bool erase_where(unsigned int where){
        Node* p=new(Node);
        Node* s=new(Node);
        p=head;
        if (where>length)
        {
            cout<<"íîìåð çà ïðåäåëàìè ñïèñêà, îáðàòèòåñü ê ôóíêöèè pop_back";
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



class Subvector:public Stack {
    private:
        int* mas;
        unsigned int top;
        unsigned int capacity;

    public:

    Subvector()
    {
        mas = NULL;
        top = 0;
        capacity = 0;
    }

    ~Subvector()
    {
        delete [] mas;
        top = 0;
        capacity = 0;
    }


    bool push_back(int a)
    {
        int new_cap;

        if (top<capacity)
        {
            new_cap=capacity;
        }
        else
        {
            new_cap=capacity+1;
        }

        int* new_mas = new int[new_cap];

        for (int i=0;i<top;i++)
        {
            new_mas[i]=mas[i];
        }
        new_mas[top]=a;

        delete[] mas;
        mas=new_mas;
        top++;
        capacity=new_cap;
    }

    bool pop_back(){

        int* new_mas = new int [capacity];

        for(int i=0; i<(top-1);i++)
        {
            new_mas[i]=mas[i];
        }

        delete[] mas;
        mas=new_mas;
        top--;
    }

    bool resize(unsigned int new_cap){
        int* new_mas = new int[new_cap];
        for (int i=0;i<top;i++)
        {
            new_mas[i]=mas[i];
        }

        delete [] mas;
        mas = new_mas;
        capacity=new_cap;

        return 1;
    }

    void shrink_to_fit(){
        int new_cap = top;
        int* new_mas = new int [new_cap];

        for (int i=0;i<top;i++)
        {
            new_mas[i]=mas[i];
        }

        delete[] mas;
        mas=new_mas;
        capacity=new_cap;
        top=new_cap;
    }

    void print(){
    for (int i=0;i<top;i++)
    {
        cout<<mas[i]<<" ";
    }

    }

    void clear(){
    delete[] mas;
    top=0;


    }



};

int main()
{
    Subvector sub_1;
    sub_1.push_back(1);
    sub_1.push_back(2);
    sub_1.push_back(3);
    sub_1.push_back(4);
    sub_1.push_back(5);
    sub_1.push_back(6);


    sub_1.pop_back();
    //sub_1.~Subvector();
    //sub_1.clear();
    //sub_1.shrink_to_fit();

    sub_1.print();
    cout<<endl;


    Sublist list1;

    list1.push_forward(2);
    list1.push_forward(3);
    list1.push_forward(4);
    list1.push_back(9);
    list1.push_back(9);
    list1.pop_back();
    //list1.pop_forward();
    list1.push_where(3,8);
    list1.erase_where(3);
    list1.print();
    cout<<endl;
    cout<<(list1.size());

return(0);
}
