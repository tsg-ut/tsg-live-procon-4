#include "generator.h"

int main(int argc,char* argv[]){
  vector<testcase*> cs;
  seeding(atoi(argv[3]));
  gen_test_case(1,atoi(argv[1]),atoi(argv[2]),cs);
  
  rep(i,1){
    int n = cs[i]->data.size();
    printf("%d\n",n);
    rep(y,n){
      rep(x,n)printf("%c",cs[i]->data[y][x]);
      puts("");
    }
  }
}
