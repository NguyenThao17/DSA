
#include <iostream>
using namespace std;

// Implement a stack of int yourself (array or linked list, do NOT use std::stack)
// and use it to write the function below:
//   void printBinary(int n)
//     Print the binary representation of n (no leading zeros), followed by a newline.
//     Hint: push n % 2, then n /= 2; finally pop the bits to print them (LIFO).
struct stack{
    int *a=new int [100] ;
    int t;
};

void CreatStack(stack& st)
{
    st.t=-1;
}

bool isEmpty(const stack& st)
{
    return st.t==-1;
}

bool isFull(const stack& st)
{
    return st.t==99;
}
int push(stack& st, int x)
{
    if(!isFull(st))
    {
        st.a[++st.t]=x;
        return 1;
    }
    return 0;
}
int pop(stack& st, int& x)
{
    if(!isEmpty(st))
    {
        x=st.a[st.t];
        st.t--;
        return 1;
    }
    return 0;
}

void printBinary(int n)
{
    stack a;
    CreatStack(a);
    int x;
    while(n!=0)
    {
        x=n%2;
        push(a,x);
        n/=2;
    }
    while(!isEmpty(a))
    {
        pop(a,x);
        cout<<x;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    printBinary(n);

    return 0;
}
