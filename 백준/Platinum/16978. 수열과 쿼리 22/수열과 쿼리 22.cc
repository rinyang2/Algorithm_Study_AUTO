#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
#define ll long long
using namespace std;

//update [Idx]th value +Value
void update(vector<ll> &v, int Idx, int Value){
        while(Idx<v.size()){
                v[Idx]+=Value;
                Idx+=(Idx&-Idx);
        }
}

//initialize fenwick tree
vector<ll> maketree(vector<ll> &arr){
    vector<ll> tree(arr.size()+1);
    for(int i=1; i<=arr.size(); i++){
        update(tree, i, arr[i]);
    }
    return tree;
}

//sum of range (1~Idx)
ll sum(vector<ll> &v, int Idx){
    ll temp = 0;
    while(Idx>0){
        temp += v[Idx];
        Idx -= (Idx&-Idx);
    }
    return temp;
}

ll rangesum(vector<ll> &v, int left, int right){
    return sum(v, right) - sum(v, left-1);
}

void printtree(vector<ll> &v){
        for(auto a:v)cout<<a<<" ";
        cout<<endl;
}
struct qry{
    int idx;
    int left;
    int right;
    int order;
    bool operator<(qry q){
        return idx<q.idx;
    }
};


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin>>N;
    vector<ll> arr(N+1);
    for(int i=1;i<=N;i++)
            cin>>arr[i];
    vector<ll> tree = maketree(arr);
    
    int Q;
    cin>>Q;

    vector<pair<int,int>> query_type_1;
    vector<qry> query_type_2;
    
    int cnt = 0;
    //offline query
    while(Q--){
        int a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            query_type_1.push_back({b,c});
        }
        else if (a==2){
            cin>>b>>c>>d;
            query_type_2.push_back({b,c,d,cnt++});
        }
    }
    sort(query_type_2.begin(), query_type_2.end());
    vector<pair<int,ll>> ans;    
    cnt = 0;
    for(int i = 0 ; i < query_type_2.size(); i++){
        while(query_type_2[i].idx>cnt){
            int idx = query_type_1[cnt].first, value = query_type_1[cnt].second;
            int diff = value - arr[idx];
            update(tree, idx, diff);
            arr[idx] = value;
            cnt++;
        }
        ans.push_back({query_type_2[i].order,rangesum(tree, query_type_2[i].left, query_type_2[i].right)});
    }
    sort(ans.begin(), ans.end());
    for(auto a: ans)
            cout<<a.second<<endl;

}