//find the longest common subsequence(recursive way)

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

string s1,s2;
int len1,len2;

int memo[1000][1000];

int dp(int i,int j){
    if(i == -1 || j == -1){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    if(s1[i] == s2[j]){
        return memo[i][j] = 1+dp(i - 1,j - 1);
    }else{
        return memo[i][j] = max(dp(i - 1,j),dp(i,j - 1));
    }
}

void solve(){
    cin >> s1 >> s2;
    memset(memo,-1,sizeof(memo));
    len1 = s1.length();
    len2 = s2.length();
    int ans = dp(len1 - 1,len2 - 1);

    cout << "longest common subsequence is : " << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}