#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long lim[10] = {15, 50, 70, 100};
    const auto& lcm = [](unsigned long a, unsigned long b) -> unsigned long {
        if(!a || !b)return a + b;
        return a / __gcd(a, b) * b;
    };
    unsigned long N, X, K;
    cin >> N >> X >> K;
    unsigned long C;
    cin >> C;
    vector<vector<unsigned long>> gue(K + 1);
    for(unsigned long i = 0; i <= K; ++i)gue[i].resize(N + K - i);
    
    random_device rdv;
    mt19937 mt(rdv());
    uniform_int_distribution<unsigned long> daiji(0, 99);
    const auto& gen = [&C, &mt, &daiji](unsigned long U) -> unsigned long {
        auto k = daiji(mt);
        if(k < C)return uniform_int_distribution<unsigned long>(1, U)(mt);
        return 0;
    };
    
    for(unsigned long i = 0; i < K; ++i){
        for(auto& j : gue[i])if(!j)j = gen(lim[i]);
        for(unsigned long j = 0; j + i + 1 < N + K; ++j)gue[i + 1][j] = lcm(gue[i][j], gue[i][j + 1]);
        for(const auto& j : gue[i])cout << j << "\t";cout << endl;
    }
}
