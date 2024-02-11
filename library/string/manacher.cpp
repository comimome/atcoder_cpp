#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (ll i = 0; i < n; ++i)

// 文字列中の回文を検出する
// 回文の最大長さを返す
// Manacherのアルゴリズム
ll Manacher(string s)
{
  ll ans=0;
  ll n=s.size();
  if(n%2==1){
    REP(i, n){
      ll sum=0;
      REP(j, min(i+1,n-i)){
        if(s[i-j]==s[i+j]){
          if(j==0) sum+=1;
          else sum+=2;
        }
        else break;
      }
      ans=max(sum,ans);
    }
  }
  else{
    string t(2*n+1,'#');
    REP(i, n) t[2*i+1] = s[i];
    n=2*n+1;
    REP(i, n){
      ll sum=0;
      REP(j, min(i+1,n-i)){
        if(t[i-j]==t[i+j]){
          if(j==0) sum+=1;
          else sum+=2;
        }
        else break;
      }
      sum=sum/2;
      ans=max(sum,ans);
    }
  }
  return ans;
}