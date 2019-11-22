#include"generator.h"

int dp[100][100];
int calc_dist(const char* s,int ls,const char* t,int lt){
  memst(dp,0);
  reg(i,0,ls){
    reg(j,0,lt){
      if(i==0){
        dp[i][j] = j;
        continue;
      }
      if(j==0){
        dp[i][j] = i;
        continue;
      }
      
      dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
      if(s[i-1] == t[j-1])dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
    }
  }
  return dp[ls][lt];
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

int greedy_solve(testcase* c){
	int maxlen = c->ls;
	int tn = c->tn;
  char s[105];
  s[maxlen] = 0;
  int res = makeFixPoint([&](auto f,int nlen, int d) -> int {
    if(d==0){
      int res = 0;
      rep(i,3)res += calc_dist(s,nlen,c->qs[i].c_str(),c->qs[i].size());
      //if(c->qs[0] == "dbbaca" && res < 8)
      //printf("%d %s\n",res,s);
      return res;
    }
    else{
      s[d-1] = 0;
      int res = f(d-1,d-1);
      rep(i,tn){
        s[d-1] = 'A'+i;
        res = min(res,f(nlen,d-1));
      }
      return res;
    }
  })(maxlen,maxlen);
  return res;
}

int main(){
	/*
	printf("%d\n",calc_dist("ef",2,"ec",2));
	printf("%d\n",calc_dist("ef",2,"f",1));
	printf("%d\n",calc_dist("ef",2,"eff",3));
	return 0;
  */
  seeding(314159);
  vector<testcase*> cs;
  gen_corner_case(cs);
  gen_test_case(40,4,26,cs);
  gen_test_case(30,6,6,cs);
  gen_test_case(30,11,2,cs);
	
  rep(i,cs.size()){
  	int ans = greedy_solve(cs[i]);
    puts("head");
    puts_test_case(cs[i]);
    puts("ans");
    printf("%d\n",ans);
  }
}
