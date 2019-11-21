#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))


int ls[3];
char s[3][105];

int dp[105][105][105];
int main(){
  rep(i,3){
    scanf("%d",&ls[i]);
    scanf("%s",s[i]);
  }
  
  memset(dp,0,sizeof(dp));
  reg(i,1,ls[0]){
    reg(j,1,ls[1]){
      reg(k,1,ls[2]){
        int v = min(dp[i][j][k-1],dp[i][j-1][k],dp[i-1][j][k]) + 1;
        if(s[0][i] == s[1][j] && s[0][i] == s[2][k])v = min(v,dp[i-1][j-1][k-1]);
        if(s[0][i] == s[1][j])v = min(v,dp[i-1][j-1][k]+1);
        if(s[0][i] == s[2][k])v = min(v,dp[i-1][j][k-1]+1);
        if(s[1][j] == s[2][k])v = min(v,dp[i][j-1][k-1]+1);
        dp[i][j][k] = v;
      }
    }
  }
  
  printf("%d\n",dp[i][j][k]);
}
