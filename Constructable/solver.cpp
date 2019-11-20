#include<bits/stdc++.h>

int main(){
    using namespace std;
    
    unsigned long A, B, X;
    cin >> A >> B >> X;
    
    unsigned long g{__gcd(A, B)};
    if(X % g)return 0 & puts("No");
    if(X * g >= A * B)return 0 & puts("Yes");
    for(unsigned long i = 0; i * g <= B && i * A <= X; ++i)if((X - i * A) % B == 0)return 0 & puts("Yes");
    puts("No");
    
    return 0;
}
