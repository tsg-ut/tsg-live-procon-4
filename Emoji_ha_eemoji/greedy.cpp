#include"generator.h"

int calc(vector<vector<char>> &data){
  int n = data.size();
  int ls=n;
  
  set<string> res;
  while(n>=1){
    rep(iy,ls/n){
      rep(ix,ls/n){
        // [iy*n,(iy+1)*n) の n*n が範囲
        int sn=1;
        while(sn<n){
          bool ok=true;
          rep(y,n/sn/2){
            rep(x,n/sn/2){
              // [iy*n+y*sn*2,iy*n+(y+1)*sn*2) が範囲なので、端の2個が一致していればよい。
              int py=iy*n+y*sn*2;
              int px=ix*n+x*sn*2;
              //printf("%d %d %d: %d %d\n",sn,py,px,iy*n+y*sn*2,iy*n+(y+1)*sn*2);
              char c = data[py][px];
              rep(dy,2)rep(dx,2){
                char tc = data[py+dy*sn][px+dx*sn];
                if(tc!=c)ok=false;
              }
            }
          }
          if(!ok)break;
          sn *= 2;
        }
        // sn個は一緒なので分割する
        //printf("sn %d n %d\n",sn,n);
        
        string s="";
        rep(y,n/sn){
          rep(x,n/sn){
            //printf("%c",data[iy*n+y*sn][ix*n+x*sn]);
            s += data[iy*n+y*sn][ix*n+x*sn];
            //printf("%d %s ",s.size(),s);
          }
        }
        //printf("%s\n",s.c_str());
        res.insert(s);
      }
    }
    n /= 2;
  }
  
  return res.size();
}

void greedy_solve(testcase* c){
  vector<pair<int,int> > ps;
  int ls = c->data.size();
  rep(y,ls)rep(x,ls){
    if(c->data[y][x] == '?'){
      ps.push_back(mp(y,x));
    }
  }
  
  /*
  n = 11 で、
  答えは、最大でも、
  >>> sum([min(4 ** i,2 ** (4 ** (n-i-1))) for i in range(n)])
  87399
  >>> sum([4 ** i for i in range(n)])
  1398101
  
  n = 12  
  >>> sum([min(4 ** i,2 ** (4 ** (n-i-1))) for i in range(n)])
  152935
  
  >>> sum([4 ** i for i in range(n)])
  5592405
  
  */
  int ans = 1 << 30;
  int bitn = 1 << (ps.size());
  rep(i,bitn){
    rep(j,ps.size()){
      c->data[ps[j].first][ps[j].second] = (i&(1<<j)) ? '#' : '.';
    }
    ans = min(ans,calc(c->data));
  }
  
  c->ans = ans;
  rep(j,ps.size()){
      c->data[ps[j].first][ps[j].second] = '?';
  }
}

int main(){
  vector<testcase*> cs;
  gen_test_case(100,64,8,cs);
  
  rep(i,cs.size()){
  	greedy_solve(cs[i]);
    int n = cs[i]->data.size();
    puts("HEAD");
    printf("%d\n",n);
    rep(y,n){
      rep(x,n)printf("%c",cs[i]->data[y][x]);
      puts("");
    }
    puts("ANS");
    printf("%d\n",cs[i]->ans);
  }
}


