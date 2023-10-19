#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <queue>

using namespace std;


struct fun{
    bool operator()( int left,  int  right) const{
        if (left>right) return true;
        return false;
    }
};

struct fun2{
    bool operator()( char left,  char  right) const{
        if (left>right) return true;
        return false;
    }
};

string solution(string number, int k) {
    string answer = "";
    map <char,priority_queue<int,vector<int>,fun>,fun2>m;
    for(int i=0;i<number.size();i++){
        m[number[i]].push(i);
    }
    int index=-1;
   
    for(int i=0;i<number.size()-k;i++){
        while(1){
            bool find=false;
            for(auto now =m.begin();now!=m.end();now++){
                if(!now->second.empty()){
                    if(number.size()-k-i>number.size()-now->second.top()){
                       continue; 
                    }
                    
                    else if(now->second.top()<index){
                        now->second.pop();
                        break;
                    }
                    else{
                        answer+=now->first;
                        index=now->second.top();
                        now->second.pop();
                        find=true;
                        break;
                    }
                }
                else
                    m.erase(now);
                    
            }
            
            if(find)
                break;
        }
        
    }
   
    
    
    
   /*for(auto now =m.begin();now!=m.end();now++){
        cout << now->first << ": ";
       while(!now->second.empty()){
           cout << now->second.top();
           now->second.pop();
           }
       cout << endl;
    }*/
    
    
    
    return answer;
}