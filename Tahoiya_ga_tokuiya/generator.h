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
  string qs[3];
  int ls;
  int tn;
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

string gen_rand_str(int ls,int tn){
  char s[100];
  rep(i,ls){
    s[i] = 'A'+(xorshift() % tn);
  }
  return string(s,ls);
}

void gen_test_case(int n,int ls,int tn,vector<testcase*>& cases){
  rep(_,n){
    testcase* c = new testcase();
    rep(i,3)c->qs[i] = gen_rand_str(xorshift() % ls + 1,tn);
    c->ls = ls;
    c->tn = tn;
    cases.push_back(c);
  }
}

void gen_corner_case(vector<testcase*>& cases){
	testcase* c;
	c = new testcase();
	rep(i,3)c->qs[i] = "ABCDEF";
	c->ls = 6;
	c->tn = 6;
	cases.push_back(c);
	c = new testcase();
	c->qs[0] = "AB";
	c->qs[1] = "CD";
	c->qs[2] = "EF";
	c->ls = 2;
	c->tn = 6;
	cases.push_back(c);
	c = new testcase();
	rep(i,3)c->qs[i] = "AABABAABABAA";
	c->ls = 12;
	c->tn = 2;
	cases.push_back(c);
}

void puts_test_case(testcase* c){
	rep(i,3){
		printf("%lu\n%s\n",c->qs[i].size(),c->qs[i].c_str());
  }
}

