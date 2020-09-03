#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdexcept>
#define SMAX 10000
using namespace std;
template <typename T>
class MyStack
{
    protected:
        int v, T s[SMAX];
    public:
        MyStack(){ v = -1;};
        T& Top(){
            logic_error e("null stack");
            if(v < 0) throw e;
            return s[v];
        }
        T& Pop(){
            logic_error e("null stack");
            if(v < 0) throw e;
            return s[v--];
        }
        void Push(const T& x){
            logic_error e("stack limit reached");
            if(v == SMAX - 1) throw e;
            s[++v] = x;

        }
        bool Empty() {return v == -1;}
        int Size() {return v + 1;}
        virtual ~MyStack();
};

#endif // MYSTACK_H
