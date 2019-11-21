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
#include <iostream>
#include <utility>
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


// check用のテストケースを作る


struct testcase{
  vector<vector<char>> data;
  int ans;
};

uint32_t seed_y = 2463534242;
void seeding(uint32_t v){
	seed_y = v;
}

uint32_t xorshift(void) {
  uint32_t y = seed_y;
  y = y ^ (y << 13); y = y ^ (y >> 17);
  seed_y = y = y ^ (y << 5);
  return seed_y;
}

// n個のテストケース 大きさdn*dn k個の?
void gen_test_case(int n,int dn,int k,vector<testcase*>& cases){
  rep(_,n){
    testcase* c = new testcase();
    c->data = vector<vector<char> >(dn,vector<char>(dn));
    rep(y,dn)rep(x,dn){
      c->data[y][x] = xorshift() % 2 ? '#' : '.';
    }
    rep(i,k){
      int y = xorshift() % dn;
      int x = xorshift() % dn;
      c->data[y][x] = '?';
    }
    
    cases.push_back(c);
  }
}
