#include <iostream>
#include <stdlib.h>

using namespace std;

class Test
{
public:
    int* term;
    int count;
//    Test* k;
    //Test() {
    //    count = 0;
    //    term = NULL;
    //}    
    Test(int num = 0) : count(num)
    {
        printf("Test()\n");
        if (num == 0)
        {
            term = NULL;
        }
        else
        {
            term = new int[num];
            memset(term, 0, sizeof(int) * num);
        }
        
    }
    ~Test()
    {
        printf("~Test()\n");
        if (term)
            delete[] term;
    }
    void malloc(int num) 
    {
        count = num;
        printf("Test()\n");
        term = new int[num];
        memset(term, 0, sizeof(int) * num);
    }
    void print()
    {
        for (int i = 0; i < count; i++)
            printf("%d ", term[i]);
        printf("\n");
    }
};
Test* func(int num)
{
    //Test* a = new Test(num);
    Test* a = (Test*)malloc(sizeof(Test));
    a->count = num;
    a->term = new int[num];

    //a->malloc(num);
    //Test t(num);
    for (int i = 0; i < num; i++)
        a->term[i] = i;
    a->print();
    //a = &t;
    return a;
}

int main()
{
    Test* a = func(10);
    a->print();
    delete a;
    //Test t = func(10);
    //t.print();
}