//find longest increasing subsequence o(n^2)

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[10100];
int lis[10100];
int par[10100];
int n;

int findlis(int a[]){
    lis[0] = 1;
    //par[0] = -1;
    for(int i = 0;i < n;i++){
        par[i] = i;
    }
    for(int i = 1;i < n;i++){
        lis[i] = 1;
        for(int j = 0;j < i;j++){
            if(arr[j] < arr[i]){
                if(lis[i] < lis[j] + 1){
                    lis[i] = lis[j] + 1;
                    par[i] = j;
                }
            }
        }
    }
    int maxelem = 0;
    for(int i = 0;i < n;i++){
        if(lis[i] > lis[maxelem]){
            maxelem = i;
        }
    }

    return maxelem;
}

void solve(){
    cin >> n;
    for(int i =0;i < n;i++){
        cin >> arr[i];
    }
    int id = findlis(arr);
    int maxlis = lis[id];
    vector<int> subseq;
    while(par[id] != id){
        subseq.push_back(arr[id]);
        id = par[id];
    }
    subseq.push_back(arr[id]);
    reverse(subseq.begin(),subseq.end());
    cout << "longest increasing subsequence is " << maxlis << endl;
    for(auto i : subseq){
        cout << i << " ";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    solve();

    return 0;
}