#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    bool finish[100];
    vector<int> imformation;
    for(int i=0;i<progresses.size();i++){
        int count=(100-progresses[i])/speeds[i];
        if(((100-progresses[i])%speeds[i]))
            count ++;
        imformation.push_back(count);
    }
    int now=imformation[0];
   int num=0;
    for(int i=0;i<progresses.size();i++){
        
        if(now>=imformation[i]){
            num++;
            
        }
        else{
            answer.push_back(num);
            num=1;
            now=imformation[i];
           
        }
        if(i==progresses.size()-1)
            answer.push_back(num);
        
    }

    
    
    
    
    return answer;
}