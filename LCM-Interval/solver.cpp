#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N, X;
    cin >> N >> X;

    unsigned long l{0}, r{0}, f{1};
    stack<unsigned long> val_front, fold_front, val_back;
    fold_front.push(1);
    const auto& lcm = [](unsigned long a, unsigned long b) -> unsigned long {
        return a / __gcd(a, b) * b;
    };
    const auto& push = [&r, &f, &fold_front, &val_back, &lcm](unsigned long x) -> unsigned long {
        val_back.push(x);
        f = lcm(f, x);
        ++r;
        return lcm(f, fold_front.top());
    };
    const auto& pop = [&l, &f, &val_front, &fold_front, &val_back, &lcm]() -> unsigned long {
        ++l;
        if(val_front.empty()){
            while(!val_back.empty()){
                auto t = val_back.top();
                val_back.pop();
                val_front.push(t);
                fold_front.push(lcm(t, fold_front.top()));
            }
            f = 1;
        }
        val_front.pop();
        fold_front.pop();
        return lcm(f, fold_front.top());
    };

    unsigned long al{0}, ar{0};
    for(unsigned long i = 0, k, a; i < N; ++i){
        cin >> a;
        k = push(a);
        while(k > X){
            k = pop();
        }
        if(ar + l < r + al){
            ar = r;
            al = l;
        }
    }
    cout << al + 1 << " " << ar << endl;
    return 0;
}
