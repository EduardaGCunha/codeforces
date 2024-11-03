#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
const int MAXN = 5*(1e3)+7;
//we have a dp of m*m 
int dp[MAXN][MAXN];

int main(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> v1, v2;

    int p = 0;
    //initial state
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        /* basically, we want to create two arrays
        in which we'll store the attributes  check
        */
        if(arr[i] < 0) v2.push_back(-arr[i]);
        else if(arr[i] > 0) v1.push_back(arr[i]);
        else{
            /*this case is where we find a point, so we incrase the
            total amount of points we have and sort our attributes arrays
            */
            sort(all(v1));
            sort(all(v2));
            p++;

            /*we'll do a simulation of adding points to either s or t!
            p is the total amount of points we have currently, so let's say we
            have put j points in intelligence, then, it is clear to see that p - j
            poins will be on strenght.
            since we have at most m points, we have m*m possibilities which is doable
            */
            for(int j = 0; j < p+1; j++){
                /* 
                if j is 0, then we are not taking any intelligence points at this state,
                that's why we must check if j != 0
                */
                if(j != 0){
                    /*since we have the sorted arrays, we are just using upperbound to find 
                    out how many attribute checks we pass with j-1 (iq) points and
                    p-j (strength) points*/
                    int res = (upper_bound(all(v1), (j-1)) - v1.begin() +
                    upper_bound(all(v2), p-j) - v2.begin());

                    /*so our dp[p][j] is the maximum between itself and 
                    the amount of points we got + how many points we had with 1 point less in
                    intelligence & total
                    */
                    dp[p][j] = max(dp[p][j], dp[p-1][j-1] + res);
                }
                //this case only happens if we haven't spent all our points on iq
                if(j < p){
                    //same logic as before
                    int res = (upper_bound(all(v1), (j)) - v1.begin() +
                    upper_bound(all(v2), p-j-1) - v2.begin());
                    //we are using p-1 because that point there is where we'll spend our strenght at
                    dp[p][j] = max(dp[p][j], dp[p-1][j] + res);
                }

            }
            v1.clear();
            v2.clear();
        }
    }

    sort(all(v1));
    sort(all(v2));
    int ans = 0;

    /*this case only happens when we have more attributes checks after
    our latest m 
    */
    for(int i = 0; i < m+1; i++){
        //we are using i as intelligence point and m-i as strenght point
        int val = (upper_bound(all(v1), i) - v1.begin()
        + upper_bound(all(v2), m-i) - v2.begin());
        ans = max(ans, dp[m][i] + val);
    }

    cout << ans << "\n";


}