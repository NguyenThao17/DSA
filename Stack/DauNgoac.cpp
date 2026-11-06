
#include <iostream>
#include <string>
using namespace std;

// Implement a stack of characters yourself (array or linked list, do NOT use std::stack)
// and use it to write the function below:
//   bool isBalanced(const string& s)
//     Return true if the bracket string s is valid (every opener is closed by the
//     matching closer in the correct nesting order), otherwise false.
struct stack{
    char* a=new char[1000000];
    int t;
};

void CreateStack(stack &st)
{
    st.t=-1;
}
bool isEmpty(const stack &st)
{
    if(st.t==-1)
        return 1;
    return 0;
}
bool isFull(const stack &st)
{
    if(st.t>=1000000-1)
        return 1;
    return 0;
}
bool push(stack &st, char x)
{
    if(!isFull(st))
    {
        st.a[++st.t]=x;
        return 1;
    }
    return 0;
}
int top(const stack &st,char &x)
{
    if(!isEmpty(st))
    {
        x=st.a[st.t];
        return 1;
    }
    return 0;
}
int pop(stack &st)
{
    if(isEmpty(st)==0)
    {
        st.t--;
        return 1;
    }
    return 0;
}

bool isBalanced(const string &s)
{
    stack st;
    CreateStack(st);
    for(int i=0; i<size(s); i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            push(st,s[i]);
        }

        else if (s[i]==')'||s[i]==']'||s[i]=='}'){
            if(isEmpty (st)) 
            {
                delete[] st.a;
                return false;
            }
            else{
                    char x;
                    top(st,x);
                    if(x=='('&&s[i]==')'||x=='['&&s[i]==']'||x=='{'&&s[i]=='}')
                    {
                        pop(st);
                    } 
                    else 
                    {
                        return false;
                        delete[] st.a;
                    }
                }
            }
        }
    if(!isEmpty(st)) return false;
    delete[] st.a;
    return true;
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << (isBalanced(s) ? "YES" : "NO") << '\n';

    return 0;
}
