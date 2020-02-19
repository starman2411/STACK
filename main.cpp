#include <iostream>
#include "Subvector.h"
#include "Sublist.h"
#include "Stack_class.h"
using namespace std;


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
