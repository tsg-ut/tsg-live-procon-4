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
  
  // dp[i][j][k] は、 s0[0,i) と s1[0,j) と s2[0,k) についての答え
  // 番兵を使ってしゅっと書きたかった...
  
  memset(dp,0,sizeof(dp));
  reg(i,0,ls[0]){
    reg(j,0,ls[1]){
      reg(k,0,ls[2]){
      	if(i==0 && j==0 && k==0){
          dp[i][j][k] = 0;
          continue;
        }
				int v = IINF;
				if(i > 0)v = min(v,dp[i-1][j][k]+1);
				if(j > 0)v = min(v,dp[i][j-1][k]+1);
				if(k > 0)v = min(v,dp[i][j][k-1]+1);
				if(i > 0 && j > 0 && k > 0){
				  v = min(v,dp[i-1][j-1][k-1]+2);
        	if(s[0][i-1] == s[1][j-1] && s[0][i-1] == s[2][k-1])v = min(v,dp[i-1][j-1][k-1]);
        }
        if(i > 0 && j > 0){
        	v = min(v,dp[i-1][j-1][k]+2);
          if(s[0][i-1] == s[1][j-1]){
          	v = min(v,dp[i-1][j-1][k]+1);
            if(k > 0)v = min(v,dp[i-1][j-1][k-1]+1);
         	}
        }
        if(i > 0 && k > 0){
        	v = min(v,dp[i-1][j][k-1]+2);
          if(s[0][i-1] == s[2][k-1]){
            v = min(v,dp[i-1][j][k-1]+1);
            if(j > 0)v = min(v,dp[i-1][j-1][k-1]+1);
          }
        }
        if(j > 0 && k > 0){
        	v = min(v,dp[i][j-1][k-1]+2);
          if(s[1][j-1] == s[2][k-1]){
            v = min(v,dp[i][j-1][k-1]+1);
            if(i > 0)v = min(v,dp[i-1][j-1][k-1]+1);
          }
        }
        
        //printf("%d %d %d : %d\n",i,j,k,v);
        dp[i][j][k] = v;
      }
    }
  }
  
  printf("%d\n",dp[ls[0]][ls[1]][ls[2]]);
}
