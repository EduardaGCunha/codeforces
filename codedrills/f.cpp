#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    // Compute initial XOR 
    int global_xor = 0;
    for(int i = 1; i <= N; i++){
        global_xor ^= A[i];
    }

    // For each bit b, maintain set of indices where A[i] has bit b = 1
    static set<int> pos[20];
    for(int b = 0; b < 20; b++){
        pos[b].clear();
    }
    for(int i = 1; i <= N; i++){
        for(int b = 0; b < 20; b++){
            if (A[i] & (1 << b)) {
                pos[b].insert(i);
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int L, R, X;
        cin >> L >> R >> X;

        // For every bit b where X has a zero, we're going to clear that bit in A[L..R]
        for(int b = 0; b < 20; b++){
            if ((X >> b & 1) == 0) {
                // gather all positions in pos[b] ∩ [L,R]
                auto it = pos[b].lower_bound(L);
                vector<int> to_rem;
                while(it != pos[b].end() && *it <= R){
                    to_rem.push_back(*it);
                    ++it;
                }
                int cnt = to_rem.size();
                // toggling cnt bits from 1→0 flips the global XOR in bit b iff cnt is odd
                if (cnt & 1) {
                    global_xor ^= (1 << b);
                }
                // actually remove them
                for(int idx : to_rem){
                    pos[b].erase(idx);
                }
            }
        }

        // print the new XOR of the entire array
        cout << global_xor << "\n";
    }

    return 0;
}
