//find longest increasing subsequence o(n^2)

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[10100];
int lis[10100];
int n;

int findlis(int a[]){
    lis[0] = 1;
    for(int i = 1;i < n;i++){
        lis[i] = 1;
        for(int j = 0;j < i;j++){
            if(arr[j] <= arr[i]){
                lis[i] = max(lis[i],lis[j] + 1);
            }
        }
    }
    int maxlen = 1;
    for(int i = 0;i < n;i++){
        maxlen = max(maxlen,lis[i]);
    }

    return maxlen;
}

void solve(){
    cin >> n;
    for(int i =0;i < n;i++){
        cin >> arr[i];
    }
    int ans = findlis(arr);
    
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    solve();

    return 0;
}