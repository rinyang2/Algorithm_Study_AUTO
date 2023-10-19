#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<char>st;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            st.push(s[i]);
        else{
            if(st.empty() or st.top()==')'){
                st.push(s[i]);
                break;
            }
            st.pop();
        }
    }
    if(st.empty())
        answer=true;

    return answer;
}