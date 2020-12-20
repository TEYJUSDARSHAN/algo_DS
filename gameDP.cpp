//determine whether the player will win or not.
/*N stones present.player has the option to choose [k1, k2 ,k3 ......,kn] stones
at a time.player loses if he cant make a move*/

#include<bits/stdc++.h>
using namespace std;

int n;
int k;
vector<int> arr;
int memo[100];

bool dp(int n){
    //cout << "finding dp(" << n << ")" << endl;
    if(n < 0){
        return 1;
    }
    if(n == 0){
        return memo[0] = 0;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    
    bool res = true;
    for(int i = 0;i < k;i++){
        //cout << "i : " << arr[i] << endl;
        bool curr = dp(n - arr[i]);
        res = res && curr;
        
    }
    res = !(res);
    return memo[n] = res;
}

void solve(){
    cin >> n >> k;
    arr.resize(k);
    memset(memo,-1,sizeof(memo));
    for(int i = 0;i < k;i++){
        cin >> arr[i];
    }
    bool ans = dp(n);
    /*for(int i = 0;i <= n;i++){
        cout << memo[i] << " ";
    }*/
    //cout << endl;
    if(ans){
        cout << "you can win the game" << endl;
    }else{
        cout << "you will definitely lose!" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    solve();

    return 0;
}