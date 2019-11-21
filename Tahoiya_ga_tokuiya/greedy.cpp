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


int dp[100][100];
int calc_dist(const char* s,int ls,const char* t,int lt){
  memst(dp,0);
  reg(i,0,ls){
    reg(j,0,lt){
      if(i==0){
        dp[i][j] = j;
        continue;
      }
      else if(j==0){
        dp[i][j] = i;
        continue;
      }
      
      dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
      if(s[i] == t[j])dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
    }
  }
  
  return dp[ls][lt];
}


struct testcase{
  string qs[3];
  int ans;
};

uint32_t xorshift(void) {
  static uint32_t y = 2463534242;
  y = y ^ (y << 13); y = y ^ (y >> 17);
  return y = y ^ (y << 5);
}

string gen_rand_str(int ls,int tn){
  char s[100];
  rep(i,ls){
    s[i] = 'a'+(xorshift() % tn);
  }
  return string(s,ls);
}


template<typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
FixPoint : private F
{
public:
  explicit constexpr FixPoint(F&& f) noexcept
    : F(std::forward<F>(f))
  {}
 
  template<typename... Args>
  constexpr decltype(auto)
  operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
    noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif  // !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
  {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};  // class FixPoint
 
 
template<typename F>
static inline constexpr decltype(auto)
makeFixPoint(F&& f) noexcept
{
  return FixPoint<F>{std::forward<F>(f)};
}

/*
int dfs_solve(char* s,int nlen,int d,int tn,){
  if(d==0){
    int res = 0;
    rep(i,3)res += calc_dist(s,nlen,
  }
  else{
    s[d-1] = 0;
    int res = dfs_solve(s,d-1,d-1,tn);
    rep(i,tn){
      s[d-1] = 'a'+i;
      res = min(res,dfs_solve(s,nlen,d-1,tn));
    }
    return res;
  }
}
*/

void greedy_solve(testcase* c,int maxlen,int tn){
  char s[105];
  s[maxlen] = 0;
  c->ans = makeFixPoint([&](auto f,int nlen, int d) -> int {
    if(d==0){
      int res = 0;
      rep(i,3)res += calc_dist(s,nlen,c->qs[i].c_str(),c->qs[i].size());
      return res;
    }
    else{
      s[d-1] = 0;
      int res = f(d-1,d-1);
      rep(i,tn){
        s[d-1] = 'a'+i;
        res = min(res,f(nlen,d-1));
      }
      return res;
    }
  })(maxlen,maxlen);
}

void gen_test_case(int n,int ls,int tn,vector<testcase*>& cases){
  rep(_,n){
    testcase* c = new testcase();
    rep(i,3)c->qs[i] = gen_rand_str(xorshift() % ls + 1,tn);
    greedy_solve(c,ls,tn);
    cases.push_back(c);
  }
}

int main(){
  vector<testcase*> cs;
  gen_test_case(10,6,6,cs);
}
