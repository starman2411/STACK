#ifndef STACK_CLASS_H_INCLUDED
#define STACK_CLASS_H_INCLUDED


class Stack{
    protected:
        Stack() {};
        ~Stack() {};
        virtual bool push_back(int a) = 0;
        virtual bool pop_back() = 0;
        virtual void print() = 0;
};

#endif // STACK_CLASS_H_INCLUDED
