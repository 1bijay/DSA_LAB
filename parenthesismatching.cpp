#include <iostream>
#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main()
{

    string exp = "((a+b)*(c-d)";
    bool balanced = true;
    // cout<<"exp lenght="<<exp.length()<<endl;
    int i = 0;
    for (i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
        {
            
            st.push('(');
        }
        else if (exp[i] == ')')
        {
            
            if (st.empty())
            {
                balanced = false;
            }
            else{
                st.pop();
            }
        }
    }
    
    if (st.empty() && balanced == true)
        cout << "Parathesis are Balanced" << endl;
    else
        cout << "Parathesis are UnBalanced" << endl;
}
