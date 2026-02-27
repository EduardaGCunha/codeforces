#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<vector<int>, bool> memo;

// Returns true if the current player can win.
// But wait, the game is asymmetric.
// Let's define solve(state) -> true if Alice wins, false if Bob wins.
// Alice wants to reach a terminal state that is not sorted.
// Bob wants to reach a sorted state.
// If state is sorted, Bob wins immediately (returns false).
// If state is terminal and not sorted, Alice wins (returns true).
// If it's Alice's turn, she wants to find a move that returns true.
// If it's Bob's turn, he wants to find a move that returns false.
// Wait, we need to know whose turn it is!
// The number of moves made so far is determined by the state.
// Initial state has some number of prime factors.
// Each move increases the length by 1.
// So the parity of (current_length - initial_length) tells us whose turn it is.

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
    if (is_sorted(a)) return false; // Bob wins
    if (is_terminal(a)) return true; // Alice wins
    
    if (memo.count(a)) return memo[a];
    
    int moves = a.size() - initial_len;
    bool is_alice = (moves % 2 == 0);
    
    if (is_alice) {
        // Alice wants to find ANY move that leads to true
        for (int i = 0; i < a.size(); ++i) {
            int x = a[i];
            for (int y = 2; y * y <= x; ++y) {
                if (x % y == 0) {
                    int z = x / y;
                    // Try y, z
                    vector<int> nxt = a;
                    nxt.erase(nxt.begin() + i);
                    nxt.insert(nxt.begin() + i, z);
                    nxt.insert(nxt.begin() + i, y);
                    if (solve(nxt)) return memo[a] = true;
                    
                    // Try z, y
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
        // Bob wants to find ANY move that leads to false
        for (int i = 0; i < a.size(); ++i) {
            int x = a[i];
            for (int y = 2; y * y <= x; ++y) {
                if (x % y == 0) {
                    int z = x / y;
                    // Try y, z
                    vector<int> nxt = a;
                    nxt.erase(nxt.begin() + i);
                    nxt.insert(nxt.begin() + i, z);
                    nxt.insert(nxt.begin() + i, y);
                    if (!solve(nxt)) return memo[a] = false;
                    
                    // Try z, y
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
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        initial_len = n;
        memo.clear();
        if (solve(a)) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
