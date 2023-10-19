#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct fun{
  bool operator()(int left, int right) const{
      if(left>right)return true;
      return false;
  }  
};
map<int,int,fun> m;
queue<pair<int,int>>q;
int solution(vector<int> priorities, int location) {
    int answer=0;
    for(int i=0;i< priorities.size();i++){
        m[priorities[i]]++;
        q.push({i,priorities[i]});
    }
    bool br=false;
    while(!br){
        for(int i=0;i< priorities.size();i++){
            int index=q.front().first;
            int value=q.front().second;
            q.pop();
            auto now=m.begin();
            if(value<now->first){
                q.push({index,value});
            }
            else{
                answer++;
                if(location==index){
                    br=true;
                    break;
                }
                m[value]--;
                priorities.erase(priorities.begin()+i);
                if(m[value]==0){
                    m.erase(now);
                }
            }
            
        }
    }
    
    
      

    
    return answer;
}