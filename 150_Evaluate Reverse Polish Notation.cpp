/*
150. Evaluate Reverse Polish Notation
Evaluate arithmetic expression given in Reverse Polish Notation (postfix) using a stack.
*/
#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens){
    stack<long long> st;
    for(auto &t: tokens){
        if(t=="+"||t=="-"||t=="*"||t=="/"){
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if(t=="+") st.push(a+b);
            else if(t=="-") st.push(a-b);
            else if(t=="*") st.push(a*b);
            else { st.push(a / b); }
        } else {
            st.push(stoll(t));
        }
    }
    return (int)st.top();
}

int main(){
    vector<string> t1 = {"2","1","+","3","*"};
    cout << "evalRPN([2,1,+,3,*]) = " << evalRPN(t1) << "\n"; // (2+1)*3 = 9

    vector<string> t2 = {"4","13","5","/","+"};
    cout << "evalRPN([4,13,5,/, +]) = " << evalRPN(t2) << "\n"; // 6

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
