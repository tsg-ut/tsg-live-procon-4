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


char s[1030][1030];
int hash[13][1030][1030];

typedef tuple<int,int,int,int> key;
map<key,int> data;

int init(int u,int d,int l,int r,int a,bool& ok){
  key k;
  int ha;
  if(u+1 == d && l+1 == r){
    char c = s[u][l];
    if(c == '.')ha = 0;
    else if(c == '#')ha = 1;
    else{
      ok = false;
      return -1;
    }
  }
  else{
    int my = (u+d)/2;
    int mx = (l+r)/2;
    int hs[4];
    rep(i,2)rep(j,2){
      int tu=u,td=my,tl=l,tr=mx;
      if(i%2){
        tu = my; td = d;
      }
      if(j%2){
        tl = mx; tr = r;
      }
      hs[i*2+j] = init(tu,td,tl,tr,a+1,ok);
    }
    key k = make_tuple(hs[0],hs[1],hs[2],hs[3]);
    if(!ok)return -1;
    
    if(data.find(k) == data.end()){
      int s = data.size();
      data[k] = s;
    }    
    ha = data[k];
  }
  hash[a][u][d] = ha;
  return ha;
}

vector<mp> ps;




int calc(){
  vector<key> aks;
  rep(i,ps.size()){
    int u,d,l,r;
    u = ps[i].fst; d=u+1;
    l = ps[i].snd; r=l+1;
    int b = 1;
    while((r-l) <= n){
      int tu = u ^ (b & u);
      int td = tu + b;
      int tl = l ^ (b & l);
      int tr = tl + b;
      b *= 2;
      
    }
  }
  
  
  rep(i,ps.size()){
    int y = ps[
    hash[dn][
  }
  rep(i,aks.size()){
    key k = aks[i];
    if(data.find(k) != data.end()){
      data.erase(k);
    }
  }
}

int main(){
  scanf("%d",&n);
  rep(i,n){
    scanf("%s",s[i]);
  }
  
  bool hass[2] = {false,false};
  rep(y,n)rep(x,n){
    if(s[y][x] == '?'){
      ps.push_back(mp(y,x));
    }
    else{
      hass[s[y][x] == '#' ? 1 : 0] = true;
    }
  }
  
  if(!(hass[0] && hass[1])){
    puts("0");
    return 0;
  }
  data[make_tuple(0,0,0,0)] = 0;
  data[make_tuple(1,1,1,1)] = 1;
  
  memset(hash,-1,sizeof(hash));
  bool ok = true;
  init(0,n,0,n,0,ok);
  
  int ans = 1 << 30;
  rep(i,1 << ps.size()){
    rep(j,ps.size()){
      char c = ((1 << j) & i) ? '#' : '.';
      s[ps[j].fst][ps[j].snd] = c;
    }
    ans = min(ans,calc());
  }
  printf("%d\n",ans);
}
