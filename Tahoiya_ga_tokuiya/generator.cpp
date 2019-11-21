#include "generator.h"

int main(int argc,char* argv[]){
  vector<testcase*> cs;
  seeding(atoi(argv[2]));
  gen_test_case(1,atoi(argv[1]),26,cs);
  puts_test_case(cs[0]);
}
