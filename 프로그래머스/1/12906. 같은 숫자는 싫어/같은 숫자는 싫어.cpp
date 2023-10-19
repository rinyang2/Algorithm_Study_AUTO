#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int now=arr[0];
    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]==now)
            continue;
        else{
            answer.push_back(arr[i]);
            now=arr[i];
        }
    }

    return answer;
}