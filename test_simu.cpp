#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

map<vector<int>, bool> memo;
int initial_len;

bool is_sorted(const vector<int>& a) {
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

bool is_terminal(const vector<int>& a) {
    for (int x : a) {
        if (x <= 1) continue;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return false;
        }
    }
    return true;
}

bool solve(vector<int> a) {
    if (is_sorted(a)) return false;
    if (is_terminal(a)) return true;
    if (memo.count(a)) return memo[a];
    
    int moves = a.size() - initial_len;
    bool is_alice = (moves % 2 == 0);
    
    if (is_alice) {
        for (int i = 0; i < a.size(); ++i) {
            int x = a[i];
            for (int y = 2; y * y <= x; ++y) {
                if (x % y == 0) {
                    int z = x / y;
                    vector<int> nxt = a;
                    nxt.erase(nxt.begin() + i);
                    nxt.insert(nxt.begin() + i, z);
                    nxt.insert(nxt.begin() + i, y);
                    if (solve(nxt)) return memo[a] = true;
                    if (y != z) {
                        nxt = a;
                        nxt.erase(nxt.begin() + i);
                        nxt.insert(nxt.begin() + i, y);
                        nxt.insert(nxt.begin() + i, z);
                        if (solve(nxt)) return memo[a] = true;
                    }
                }
            }
        }
        return memo[a] = false;
    } else {
        for (int i = 0; i < a.size(); ++i) {
            int x = a[i];
            for (int y = 2; y * y <= x; ++y) {
                if (x % y == 0) {
                    int z = x / y;
                    vector<int> nxt = a;
                    nxt.erase(nxt.begin() + i);
                    nxt.insert(nxt.begin() + i, z);
                    nxt.insert(nxt.begin() + i, y);
                    if (!solve(nxt)) return memo[a] = false;
                    if (y != z) {
                        nxt = a;
                        nxt.erase(nxt.begin() + i);
                        nxt.insert(nxt.begin() + i, y);
                        nxt.insert(nxt.begin() + i, z);
                        if (!solve(nxt)) return memo[a] = false;
                    }
                }
            }
        }
        return memo[a] = true;
    }
}

int main() {
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 20; ++j) {
            vector<int> a = {i, j};
            initial_len = 2;
            memo.clear();
            bool alice_wins = solve(a);
            if (alice_wins) {
                cout << i << " " << j << " : Alice\n";
            }
        }
    }
    return 0;
}
