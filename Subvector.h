#ifndef SUBVECTOR_H_INCLUDED
#define SUBVECTOR_H_INCLUDED
#include <iostream>
#include "Stack_class.h"
using namespace std;

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

#endif // SUBVECTOR_H_INCLUDED
