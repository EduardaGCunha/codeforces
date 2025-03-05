#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        
        vector<vector<int>> graph(n);
        for(int i = 0; i < n-1; i++){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        multiset<int, greater<int>> deg;
        for(int i = 0; i < n; i++){
            deg.insert(graph[i].size());
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            deg.erase(deg.find(graph[i].size()));
            for(auto u : graph[i]){
                ans = max<int>(ans, graph[i].size() + graph[u].size() - 2);
                deg.erase(deg.find(graph[u].size()));
            }

            if(!deg.empty()){
                int d = *deg.begin();
                ans = max<int>(ans, graph[i].size() + d - 1);
            }

            deg.insert(graph[i].size());
            for(auto u : graph[i]){
                deg.insert(graph[u].size());
            }
        }
        cout << ans << endl;
    }
}
