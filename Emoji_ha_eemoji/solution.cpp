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


typedef struct node_{
  struct node_* cs[4];
  struct node_* pa;
  int ha;
} node;

key key_of_node(node* no){
  return make_tuple(
    no->cs[0]->ha,
    no->cs[1]->ha,
    no->cs[2]->ha,
    no->cs[3]->ha
  );
}

bool update_node(node* no){
  bool ok = true;
  rep(i,4){
    if(no->cs[i]->ha < 0)ok = false;
  }
  if(!ok){
    no->ha = -1;
    return false;
  }
  key k = key_of_node(no);
  
  bool res = false;
  if(data.find(k) == data.end()){
    int s = data.size();
    data[k] = s;
    res = true;
  }
  no->ha = data[k];
  return res;
}

node* init(int y,int x,int b,vector<node*>& qs){
  node* res;
  if(b == 0){
    res = new node();
    char c = s[y][x];
    if(c == '.')res->ha = 0;
    else if(c == '#')res->ha = 1;
    else{
      res->ha = -1;
      qs.push_back(res);
    }
  }
  else{
    res = new node();
    rep(dy,2)rep(dx,2){
      res->cs[dy*2+dx] = init(y+b*dy, x+b*dx, b/2, qs);
    }
    rep(i,4){
      res->cs[i]->pa = res;
    }
    update_node(res);
  }
  return res;
}

int main(){
  int n;
  scanf("%d",&n);
  rep(i,n){
    scanf("%s",s[i]);
  }
  
  bool hass[2] = {false,false};
  rep(y,n)rep(x,n){
    if(s[y][x] == '?')continue;
    else{
      hass[s[y][x] == '#' ? 1 : 0] = true;
    }
  }
  
  if(!(hass[0] && hass[1])){
    puts("1");
    return 0;
  }
  data[make_tuple(0,0,0,0)] = 0;
  data[make_tuple(1,1,1,1)] = 1;
  
  
  vector<node*> qs;
  node* tree = init(0,0,n/2,qs);
  tree->pa = NULL;
  
  int ans = 1 << 30;
  rep(i,1 << qs.size()){
    vector<key> rems;
    
    rep(j,qs.size()){
      int c = ((1 << j) & i) ? 1 : 0;
      qs[j]->ha = c;
      
      node* no = qs[j]->pa;
      while(no != NULL){
        bool isnew = update_node(no);
        if(no->ha < 0)break;
        if(isnew){
          rems.push_back(key_of_node(no));
        }
        no = no->pa;
      }
    }
    ans = min(ans,((int)data.size()));
    
    rep(j,rems.size()){
      data.erase(rems[j]);
    }
    
    rep(j,qs.size()){
      node* no = qs[j];
      while(no != NULL){
        no->ha = -1;
        no = no->pa;
      }
    }
  }
  printf("%d\n",ans);
}
